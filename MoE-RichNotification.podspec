Pod::Spec.new do |s|
  s.name             = 'MoE-RichNotification'
  s.version          = '6.3.1'
  s.summary          = 'MoEngage Rich Notifications for iOS.'

  s.description  = <<-DESC
                   MORichNotification helps you to make use Notification Service Extensions to support media in notifications(Rich Push Notifications). This feature is available from iOS version 10.0 and above. 
                   DESC

  s.homepage     = 'https://www.moengage.com'
  s.documentation_url = 'https://developers.moengage.com'
  s.social_media_url   = 'https://twitter.com/moengage'

  s.license      = { :type => 'Commercial', :file => 'LICENSE' }
  s.author       = { 'MobileDev' => 'mobiledevs@moengage.com' }
  s.platform     = :ios
  s.ios.deployment_target = '10.0'
  s.source           = { 
  	:git => 'https://github.com/moengage/MoEngage-iOS-SDK-Beta.git',
  	:tag => 'moe-richPush-' + s.version.to_s 
  }

  s.ios.vendored_frameworks = 'Frameworks/MoEngageRichNotification.xcframework'
  s.requires_arc = true
  s.frameworks = 'Foundation', 'UIKit', 'UserNotifications', 'UserNotificationsUI'
  s.dependency 'MoE-iOS-SDK', '>= 8.3.0', '< 8.4.0'
end