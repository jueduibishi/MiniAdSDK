/*
 * Copyright 2022 Bytedance Inc.
 * SPDX license identifier: LGPL-2.1-or-later
 *
 *
 * Export private or deprecated symbols
 */

#include <stdint.h>
#include "libavformat/url.h"
#include "libavformat/avformat.h"
#include "libavutil/ttexport.h"

#define MAX_FIELD_LEN 64

/*
 * Renditions are e.g. alternative subtitle or audio streams.
 * The rendition may either be an external playlist or it may be
 * contained in the main Media Playlist of the variant (in which case
 * playlist is NULL).
 */
typedef struct hls_rendition {
    int info_id;
    enum AVMediaType type;
    char group_id[MAX_FIELD_LEN];
    char language[MAX_FIELD_LEN];
    char name[MAX_FIELD_LEN];
} hls_rendition;

typedef struct hls_playlist {
    int index;
    int n_renditions;
    hls_rendition **renditions;
} hls_playlist;

typedef struct hls_variant {
    int bandwidth;
    int average_bandwidth;
    char codecs[MAX_FIELD_LEN];
    int width;
    int height;
    float frame_rate;
    char HDCP_level[MAX_FIELD_LEN];
    char closed_captions[MAX_FIELD_LEN];

    char audio_group[MAX_FIELD_LEN];
    char video_group[MAX_FIELD_LEN];
    char subtitles_group[MAX_FIELD_LEN];
    int n_playlists;
    hls_playlist** playlists;
} hls_variant;

typedef struct HLSChooseBestStreamCtx {
    intptr_t handle;
    void (*stream_info)(intptr_t handle, int n_variants, struct hls_variant **variants);
    int (*choose_variant_bandwidth)(intptr_t handle);
    int (*choose_rendition_infoid)(intptr_t handle, int variant_index);
} HLSChooseBestStreamCtx;

int tt_register_protocol(URLProtocol *prot, int protocol_size);

/**
 * Only support register one protocol
 * If call this more than once, only the last once registered.
 * @param prot pointer to URLProtocol.
 * @param protocol_size additional abi check, must be same as sizeof(URLProtocol)
 * @return int Return 0 for success, others failed.
 */
int tt_register_3rd_protocol(URLProtocol *prot, int protocol_size);


int tt_register_input_format(AVInputFormat *format, int format_size);


void tt_register_dnsparser(tt_dns_start getinfo, tt_dns_result result, tt_dns_free end);

void tt_register_io_callback(tt_save_ip       save_ip, 
                             tt_log_callback  log_callback, 
                             tt_read_callback read_callback, 
                             tt_info_callback info_callback);

/**
 * Set the time base and wrapping info for a given stream. This will be used
 * to interpret the stream's timestamps. If the new time base is invalid
 * (numerator or denominator are non-positive), it leaves the stream
 * unchanged.
 *
 * @param s stream
 * @param pts_wrap_bits number of bits effectively used by the pts
 *        (used for wrap control)
 * @param pts_num time base numerator
 * @param pts_den time base denominator
 */
void tt_set_pts_info(AVStream *s, int pts_wrap_bits,
                         unsigned int pts_num, unsigned int pts_den);


/** Flush the frame reader. */
void tt_read_frame_flush(AVFormatContext *s);

/**
 * Read size bytes from AVIOContext into buf.
 * This reads at most 1 packet. If that is not enough fewer bytes will be
 * returned.
 * @return number of bytes read or AVERROR
 */
int tt_io_read_partial(AVIOContext *s, unsigned char *buf, int size);

void tt_set_verify_callback(int (*callback)(void*, void*, const char*, int));


/**
 * Copy encoding parameters from source to destination stream
 *
 * @param dst pointer to destination AVStream
 * @param src pointer to source AVStream
 * @return >=0 on success, AVERROR code on error
 */
int tt_stream_encode_params_copy(AVStream *dst, const AVStream *src);

/**
 * Copies the whilelists from one context to the other
 */
int tt_copy_whiteblacklists(AVFormatContext *dst, const AVFormatContext *src);

/**
 * Initialize an AVIOContext for buffered I/O.
 * avio_alloc_context is a better choice.
 *
 * @param buffer Memory block for input/output operations via AVIOContext.
 *        The buffer must be allocated with av_malloc() and friends.
 *        It may be freed and replaced with a new buffer by libavformat.
 *        AVIOContext.buffer holds the buffer currently in use,
 *        which must be later freed with av_free().
 * @param buffer_size The buffer size is very important for performance.
 *        For protocols with fixed blocksize it should be set to this blocksize.
 *        For others a typical size is a cache page, e.g. 4kb.
 * @param write_flag Set to 1 if the buffer should be writable, 0 otherwise.
 * @param opaque An opaque pointer to user-specific data.
 * @param read_packet  A function for refilling the buffer, may be NULL.
 *                     For stream protocols, must never return 0 but rather
 *                     a proper AVERROR code.
 * @param write_packet A function for writing the buffer contents, may be NULL.
 *        The function may not change the input buffers content.
 * @param seek A function for seeking to specified byte position, may be NULL.
 *
 * @return 0
 */
int tt_io_init_context(AVIOContext *s,
                  unsigned char *buffer,
                  int buffer_size,
                  int write_flag,
                  void *opaque,
                  int (*read_packet)(void *opaque, uint8_t *buf, int buf_size),
                  int (*write_packet)(void *opaque, uint8_t *buf, int buf_size),
                  int64_t (*seek)(void *opaque, int64_t offset, int whence));

void tt_save_host_addr(aptr_t handle, const char* ip, int user_flag);

void tt_network_log_callback(aptr_t handle, int type, int user_flag);

void tt_network_io_read_callback(aptr_t handle, int type, int size);

void tt_network_info_callback(aptr_t handle, int key, int64_t value, const char* strValue);

/**
 * Convert a relative url into an absolute url, given a base url.
 *
 * @param buf the buffer where output absolute url is written
 * @param size the size of buf
 * @param base the base url, may be equal to buf.
 * @param rel the new url, which is interpreted relative to base
 */
void tt_make_absolute_url(char *buf, int size, const char *base,
                          const char *rel);

/**
 * Check if the user has requested to interrupt a blocking function
 * associated with cb.
 */
int tt_check_interrupt(AVIOInterruptCB *cb);

void tt_free_stream(AVFormatContext *s, AVStream *st);


int tt_index_search_timestamp(const AVIndexEntry *entries, int nb_entries, int64_t wanted_timestamp, int flags);

int tt_add_index_entry(AVIndexEntry **index_entries,
                       int *nb_index_entries,
                       unsigned int *index_entries_allocated_size,
                       int64_t pos, int64_t timestamp, int size, int distance, int flags);