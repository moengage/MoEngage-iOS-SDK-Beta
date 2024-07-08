Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary      = 'MoEngage InApp Campaigns for iOS'
  s.description  = <<-DESC
                   InApp Messaging are custom views which you can send to a segment of users to show custom messages or give new offers or take to some specific pages. They can be created from your MoEngage dashboard and MOInApp framework enables you to show those InApp campaigns in your iOS Apps.
                   DESC

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation', 'UIKit', 'CoreGraphics'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-Analytics-Beta'
  s.dependency 'MoE-Messaging-Beta'
  s.dependency 'MoE-ObjCUtils-Beta'
  s.dependency 'MoE-TriggerEvaluator-Beta'
end
