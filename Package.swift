// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "MiniSDKFramework",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "MiniSDKFramework", targets: ["MiniSDKFramework"])
    ],
    targets: [
        .binaryTarget(
            name: "MiniSDKFramework",
            url: "https://github.com/jueduibishi/MiniAdSDK/releases/download/0.7.807/MiniSDKFramework.xcframework.zip",
            checksum: "64b4174fc4020f8b2745c116b73767fb0a890197c220100b03369723decce340"
        )
    ]
)
