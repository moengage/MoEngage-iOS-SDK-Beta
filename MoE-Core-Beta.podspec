
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDKBeta::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageCore contains the central configuration of your app and common Utils and modules to be used accross all the MoEngage frameworks.
                   DESC

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation', 'UIKit', 'SystemConfiguration' , 'Security'
  s.weak_framework = 'UserNotifications'

  s.dependency 'MoE-Security-Beta'
end
