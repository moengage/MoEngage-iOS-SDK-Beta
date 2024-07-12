
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageAnalytics framework enables you to track required data regarding user and user's activities inside the app to use the same for effective engagement.
                   DESC

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-ObjCUtils-Beta'
end
