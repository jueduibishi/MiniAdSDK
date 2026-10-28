// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "MiniSDKFramework",
    platforms: [.iOS(.v12)],
    products: [
        .library(name: "MiniSDKFramework", targets: ["MiniSDKFramework"])
    ],
    targets: [
        .binaryTarget(
            name: "MiniSDKFramework",
            url: "https://github.com/jueduibishi/MiniAdSDK/releases/download/0.7.805/MiniSDKFramework.xcframework.zip",
            checksum: "940d2a2cecfcffa366886a6645a4821401e6ab692a8252ca4417a4f6356c5601"
        )
    ]
)
