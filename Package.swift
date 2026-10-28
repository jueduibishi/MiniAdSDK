// swift-tools-version:5.9
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
            checksum: "89b74bd776cd193c069c0ecbd2842d26473b05a62eb1aa8f72c235b65c418fce")
    ],
    traits: [
        .trait(name: "core", description: "广告集成")
    ]
)
