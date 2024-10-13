// swift-tools-version:5.10
import PackageDescription

let package = Package(
    name: "PPBluetoothKit",
    platforms: [
        .iOS(.v16)
    ],
    products: [
        .library(
            name: "PPBluetoothKit",
            targets: ["PPBluetoothKit"]
        )
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "PPBluetoothKit",
            path: "Frameworks/PPBluetoothKit.xcframework" // xcframework 경로 지정
        )
    ]
)
