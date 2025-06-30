
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDKBeta::Spec
  s.define

  s.summary      = 'MoEngage RTT Campaigns for iOS'
  s.description  = <<-DESC
                 Real-time device triggers are push notifications that are triggered instantly in the device whenever a trigger event Is tracked with the SDK trackEvent: 
                   DESC

  s.addDirectUseWarning
  s.frameworks = 'Foundation', 'UIKit', 'ImageIO'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-Analytics-Beta'
  s.dependency 'MoE-Messaging-Beta'
  s.dependency 'MoE-RichNotification'
end
