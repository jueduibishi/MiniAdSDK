#!/bin/sh
set -e
set -u
set -o pipefail

function on_error {
  echo "$(realpath -mq "${0}"):$1: error: Unexpected failure"
}
trap 'on_error $LINENO' ERR


# This protects against multiple targets copying the same framework dependency at the same time. The solution
# was originally proposed here: https://lists.samba.org/archive/rsync/2008-February/020158.html
RSYNC_PROTECT_TMP_FILES=(--filter "P .*.??????")


variant_for_slice()
{
  case "$1" in
  "TTSDKCore.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKCore.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKLiveBase.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKLiveBase.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKLivePlayerLite.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKLivePlayerLite.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKPlayerCoreLiveLite.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKPlayerCoreLiveLite.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKReachability.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKReachability.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "ttboringssl.xcframework/ios-arm64")
    echo ""
    ;;
  "ttboringssl.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "ttcrypto.xcframework/ios-arm64")
    echo ""
    ;;
  "ttcrypto.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKStrategyLite.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKStrategyLite.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTFFmpeg.xcframework/ios-arm64")
    echo ""
    ;;
  "TTFFmpeg.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKTTFFmpegLiveLite.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKTTFFmpegLiveLite.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  "TTSDKTools.xcframework/ios-arm64")
    echo ""
    ;;
  "TTSDKTools.xcframework/ios-x86_64-simulator")
    echo "simulator"
    ;;
  esac
}

archs_for_slice()
{
  case "$1" in
  "TTSDKCore.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKCore.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  "TTSDKLiveBase.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKLiveBase.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  "TTSDKLivePlayerLite.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKLivePlayerLite.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  "TTSDKPlayerCoreLiveLite.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKPlayerCoreLiveLite.xcframework/ios-x86_64-simulator")
    echo "arm64 x86_64"
    ;;
  "TTSDKReachability.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKReachability.xcframework/ios-x86_64-simulator")
    echo "arm64 x86_64"
    ;;
  "ttboringssl.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "ttboringssl.xcframework/ios-x86_64-simulator")
    echo "arm64 x86_64"
    ;;
  "ttcrypto.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "ttcrypto.xcframework/ios-x86_64-simulator")
    echo "arm64 x86_64"
    ;;
  "TTSDKStrategyLite.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKStrategyLite.xcframework/ios-x86_64-simulator")
    echo "arm64 x86_64"
    ;;
  "TTFFmpeg.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTFFmpeg.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  "TTSDKTTFFmpegLiveLite.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKTTFFmpegLiveLite.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  "TTSDKTools.xcframework/ios-arm64")
    echo "arm64"
    ;;
  "TTSDKTools.xcframework/ios-x86_64-simulator")
    echo "x86_64"
    ;;
  esac
}

copy_dir()
{
  local source="$1"
  local destination="$2"

  # Use filter instead of exclude so missing patterns don't throw errors.
  echo "rsync --delete -av "${RSYNC_PROTECT_TMP_FILES[@]}" --links --filter \"- CVS/\" --filter \"- .svn/\" --filter \"- .git/\" --filter \"- .hg/\" \"${source}*\" \"${destination}\""
  rsync --delete -av "${RSYNC_PROTECT_TMP_FILES[@]}" --links --filter "- CVS/" --filter "- .svn/" --filter "- .git/" --filter "- .hg/" "${source}"/* "${destination}"
}

SELECT_SLICE_RETVAL=""

select_slice() {
  local xcframework_name="$1"
  xcframework_name="${xcframework_name##*/}"
  local paths=("${@:2}")
  # Locate the correct slice of the .xcframework for the current architectures
  local target_path=""

  # Split archs on space so we can find a slice that has all the needed archs
  local target_archs=$(echo $ARCHS | tr " " "\n")

  local target_variant=""
  if [[ "$PLATFORM_NAME" == *"simulator" ]]; then
    target_variant="simulator"
  fi
  if [[ ! -z ${EFFECTIVE_PLATFORM_NAME+x} && "$EFFECTIVE_PLATFORM_NAME" == *"maccatalyst" ]]; then
    target_variant="maccatalyst"
  fi
  for i in ${!paths[@]}; do
    local matched_all_archs="1"
    local slice_archs="$(archs_for_slice "${xcframework_name}/${paths[$i]}")"
    local slice_variant="$(variant_for_slice "${xcframework_name}/${paths[$i]}")"
    for target_arch in $target_archs; do
      if ! [[ "${slice_variant}" == "$target_variant" ]]; then
        matched_all_archs="0"
        break
      fi

      if ! echo "${slice_archs}" | tr " " "\n" | grep -F -q -x "$target_arch"; then
        matched_all_archs="0"
        break
      fi
    done

    if [[ "$matched_all_archs" == "1" ]]; then
      # Found a matching slice
      echo "Selected xcframework slice ${paths[$i]}"
      SELECT_SLICE_RETVAL=${paths[$i]}
      break
    fi
  done
}

install_xcframework() {
  local basepath="$1"
  local name="$2"
  local package_type="$3"
  local paths=("${@:4}")

  # Locate the correct slice of the .xcframework for the current architectures
  select_slice "${basepath}" "${paths[@]}"
  local target_path="$SELECT_SLICE_RETVAL"
  if [[ -z "$target_path" ]]; then
    echo "warning: [CP] $(basename ${basepath}): Unable to find matching slice in '${paths[@]}' for the current build architectures ($ARCHS) and platform (${EFFECTIVE_PLATFORM_NAME-${PLATFORM_NAME}})."
    return
  fi
  local source="$basepath/$target_path"

  local destination="${PODS_XCFRAMEWORKS_BUILD_DIR}/${name}"

  if [ ! -d "$destination" ]; then
    mkdir -p "$destination"
  fi

  copy_dir "$source/" "$destination"
  echo "Copied $source to $destination"
}

install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKCore/TTSDKCore.xcframework" "BUTTSDKFramework/Core" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKLiveBase/TTSDKLiveBase.xcframework" "BUTTSDKFramework/LiveBase" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKLivePlayerLite/TTSDKLivePlayerLite.xcframework" "BUTTSDKFramework/LivePlayer/Lite" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKPlayerCoreLiveLite/TTSDKPlayerCoreLiveLite.xcframework" "BUTTSDKFramework/PlayerCore/LiveLite" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKReachability/TTSDKReachability.xcframework" "BUTTSDKFramework/Reachability" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKSSL/ttboringssl.xcframework" "BUTTSDKFramework/SSL" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKSSL/ttcrypto.xcframework" "BUTTSDKFramework/SSL" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKStrategyLite/TTSDKStrategyLite.xcframework" "BUTTSDKFramework/Strategy/Lite" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKTTFFmpegLiveLite/TTFFmpeg.xcframework" "BUTTSDKFramework/TTFFmpeg/LiveLite" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKTTFFmpegLiveLite/TTSDKTTFFmpegLiveLite.xcframework" "BUTTSDKFramework/TTFFmpeg/LiveLite" "framework" "ios-arm64" "ios-x86_64-simulator"
install_xcframework "${PODS_ROOT}/BUTTSDKFramework/TTSDKFramework/TTSDKTools/TTSDKTools.xcframework" "BUTTSDKFramework/Tools" "framework" "ios-arm64" "ios-x86_64-simulator"

