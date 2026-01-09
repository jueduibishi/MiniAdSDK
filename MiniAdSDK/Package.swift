// swift-tools-version: 6.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MiniAdSDK",
    platforms: [.iOS(.v12)],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "MiniAdSDK",
            targets: ["MiniAdSDK"]
        ),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(name: "MiniAdSDK"),
        .binaryTarget(name: "MiniSDKFramework", url: "https://github.com/jueduibishi/MiniAdSDK/tree/main/MiniAdSDK/Sources/sdk/0.2.9/MiniSDKFramework.zip", checksum: "85ea7179963de50f979d123ebfb6afccad6949ca76df155ed57970a2dac6c6bd")
        
    ]
)
