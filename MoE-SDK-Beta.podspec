
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageSDK contains initialization, enabling/disabling of MoEngage frameworks.
                   DESC
  
  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-Analytics-Beta'
  s.dependency 'MoE-Messaging-Beta'
  s.dependency 'MoE-ObjCUtils-Beta'
end
