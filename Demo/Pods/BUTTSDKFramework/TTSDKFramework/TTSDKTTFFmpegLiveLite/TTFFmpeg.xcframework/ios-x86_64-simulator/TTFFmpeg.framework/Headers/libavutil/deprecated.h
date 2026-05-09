/**
 * After implementing the true DRM function, delete AVDeprecatedContext
 */

#ifndef AVUTIL_DEPRECATED_H
#define AVUTIL_DEPRECATED_H

#include <stdint.h>

#include "attributes.h"
#include "version.h"

/**
 * @defgroup lavu_aes AES
 * @ingroup lavu_crypto
 * @{
 */

struct AVDeprecatedContext;

/**
 * Allocate an AVDeprecatedContext context.
 */
struct AVDeprecatedContext *tt_deprecated_ctx_alloc(void);

/**
 * Initialize an AVDeprecatedContext context.
 * @param key_bits 128, 192 or 256
 */
int tt_deprecated_ctx_init(struct AVDeprecatedContext *a, const uint8_t *unused, const uint8_t *key, int key_bits);

/**
 * Decrypt a buffer using a previously initialized context.
 * @param count number of 16 byte blocks
 * @param dst destination array, can be equal to src
 * @param src source array, can be equal to dst
 * @param iv initialization vector for CBC mode, if NULL then ECB will be used
 */
void tt_deprecated_ctx_process(struct AVDeprecatedContext *a, const uint8_t *unused, uint8_t *dst, const uint8_t *src, int count, uint8_t *iv);
/**
 * @}
 */

#endif /* AVUTIL_DEPRECATED_H */
