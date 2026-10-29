killall Xcode 2>/dev/null
rm -rf ~/Library/Developer/Xcode/DerivedData
rm -rf ~/Library/Caches/org.swift.swiftpm
rm -rf ~/Library/org.swift.swiftpm
find . -name "Package.resolved" -delete
xcodebuild -resolvePackageDependencies -scmProvider system -project Demo.xcodeproj
open Demo.xcworkspace