
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDKBeta::Spec
  s.define

  s.summary      =  "#{s.name} for iOS"
  s.description  = <<-DESC
                     MoEngageSecurity enhances security for modules to be used accross all the MoEngage frameworks.
                   DESC
 

  s.addDirectUseWarning
  s.tvos.deployment_target = '11.0'
  s.frameworks = 'Foundation', 'Security'
end
