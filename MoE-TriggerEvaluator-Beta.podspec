
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDKBeta::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageTriggerEvaluator evaluates trigger conditions of InApp campaigns.
                   DESC

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation', 'UIKit', 'CoreGraphics'

  s.dependency 'MoE-Core-Beta'
end
