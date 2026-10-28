// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "Probe",
    platforms: [.iOS(.v12)],
    products: [
        .library(name: "Probe", targets: ["Probe"])
    ],
    targets: [
        .binaryTarget(
            name: "MiniSDKFramework",
            path: "sdk/MiniSDKFramework.xcframework.zip"
        ),
        .target(
            name: "Probe",
            dependencies: ["MiniSDKFramework"]
        )
    ]
)
