//
//  SceneDelegate.swift
//  Demo
//
//  Created by l on 2025/9/25.
//

import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
    var window: UIWindow?
    
    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        guard let windowScene = (scene as? UIWindowScene) else { return }
        
        // 创建窗口并与窗口场景关联
        window = UIWindow(windowScene: windowScene)
        window?.rootViewController = UINavigationController(rootViewController: TableVC())
        // 设置根视图控制器
        // 例如：window?.rootViewController = ViewController()
        // 如果原项目使用Storyboard，你可能需要实例化相应的故事板和视图控制器
        // let storyboard = UIStoryboard(name: "Main", bundle: nil)
        // let rootViewController = storyboard.instantiateInitialViewController()
        // window?.rootViewController = rootViewController
        
        window?.makeKeyAndVisible()
    }
    
    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // 处理被丢弃的场景会话
    }
}

