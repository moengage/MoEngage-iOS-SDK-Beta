
Pod::Spec.new do |s|

  s.name         = 'MoE-RealTimeTrigger'
  s.version      = '1.3.0'
  s.summary      = 'MoEngage RTT Campaigns for iOS'
  s.description  = <<-DESC
                 Real-time device triggers are push notifications that are triggered instantly in the device whenever a trigger event Is tracked with the SDK trackEvent: 
                   DESC

  s.homepage     = 'https://www.moengage.com'
  s.documentation_url = 'https://developers.moengage.com'
  s.license      = { :type => 'Commercial', :file => 'LICENSE' }
  s.author       = { 'MobileDev' => 'mobiledevs@moengage.com' }
  s.social_media_url   = 'https://twitter.com/moengage'
  s.platform     = :ios
  s.ios.deployment_target = '10.0'

  s.source       = { 
                    :git => 'https://github.com/moengage/MoEngage-iOS-SDK-Beta.git', 
                    :tag => 'moe-rtt-' + s.version.to_s 
                    }
                    
  s.ios.vendored_frameworks = 'Frameworks/MoEngageRealTimeTrigger.xcframework'
  s.requires_arc = true
  s.frameworks = 'Foundation', 'UIKit', 'ImageIO'
  s.dependency 'MoE-iOS-SDK', '>= 8.3.0', '< 8.4.0'
  s.dependency 'MoE-RichNotification', '>= 6.3.0', '< 6.4.0'
end
