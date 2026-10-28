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
            path: "sdk/MiniSDKFramework.xcframework.zip"
        )
    ]
)
