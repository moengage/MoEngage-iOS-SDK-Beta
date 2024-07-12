
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageObjCUtils contains Objective-C Utils to be used accross all the MoEngage frameworks.
                   DESC

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation'

  s.dependency 'MoE-Core-Beta'
end
