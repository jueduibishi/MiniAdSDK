// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "MiniAdSDK",
    platforms: [
        .iOS(.v12),
    ],
    products: [
        .library(
            name: "MiniAdSDK",
            targets: ["MiniSDKFramework"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "MiniSDKFramework",
            url: "https://github.com/jueduibishi/MiniAdSDK/releases/download/0.7.8.0.6/MiniSDKFramework.xcframework.zip",
            checksum: "0a3c9fd5fd3328802038ffbc8b32c99f70c42d0dedf669a170e1a2e58cae3489"
        ),
    ]
)
