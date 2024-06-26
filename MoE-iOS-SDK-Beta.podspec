
Pod::Spec.new do |s|

  s.name         = 'MoE-iOS-SDK-Beta'
  s.version      = '9.16.0'
  s.summary      = 'MoEngage for iOS'
  s.description  = <<-DESC
                   MoEngage is a mobile marketing automation company. This framework acts like a umbrella framework to include MoEngageCore, MOAnalytics and MOMessaging frameworks.
                   MoEngageCore contains the central configuration of your app and common Utils and modules to be used accross all the MoEngage frameworks.
                   MOAnalytics framework enables you to track required data regarding user and user's activities inside the app to use the same for effective engagement. 
                   MOMessaging module will help you support all the features related to push notifications in your App.
                   DESC

  s.homepage     = 'https://www.moengage.com'
  s.documentation_url = 'https://developers.moengage.com'
  s.license      = { :type => 'Commercial', :file => 'LICENSE' }
  s.author       = { 'MobileDev' => 'mobiledevs@moengage.com' }
  s.social_media_url   = 'https://twitter.com/moengage'
  s.ios.deployment_target = '11.0'
  s.tvos.deployment_target = '11.0'

  s.source       = { 
                    :git => 'https://github.com/moengage/MoEngage-iOS-SDK-Beta.git', 
                    :tag => 'moe-iOS-sdk-' + s.version.to_s 
                    }
         
  s.ios.vendored_frameworks = 'Frameworks/MoEngageSDK.xcframework','Frameworks/MoEngageCore.xcframework', 'Frameworks/MoEngageAnalytics.xcframework', 'Frameworks/MoEngageMessaging.xcframework','Frameworks/MoEngageObjCUtils.xcframework', 'Frameworks/MoEngageSecurity.xcframework'
  s.tvos.vendored_frameworks = 'Frameworks/MoEngageSDK.xcframework','Frameworks/MoEngageCore.xcframework', 'Frameworks/MoEngageAnalytics.xcframework', 'Frameworks/MoEngageMessaging.xcframework', 'Frameworks/MoEngageObjCUtils.xcframework', 'Frameworks/MoEngageSecurity.xcframework'
  s.requires_arc = true
  s.frameworks = 'Foundation', 'UIKit', 'SystemConfiguration' , 'Security'
  s.weak_framework = 'AdSupport', 'UserNotifications', 'AppTrackingTransparency'
end
