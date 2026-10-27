// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "MiniSDKFramework",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "MiniSDKFramework",
            targets: ["MiniSDKFramework"])
    ],
    targets: [
        .binaryTarget(
            name: "MiniSDKFramework",
            url: "https://github.com/jueduibishi/MiniAdSDK/releases/download/0.7.805/MiniSDKFramework.xcframework.zip",
            checksum: "0a3c9fd5fd3328802038ffbc8b32c99f70c42d0dedf669a170e1a2e58cae3489")
    ]
)
