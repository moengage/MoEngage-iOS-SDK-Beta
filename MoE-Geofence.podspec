
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDKBeta::Spec
  s.define

  s.summary      = 'MoEngage SDK for Geofence based campaigns in iOS'
  s.description  = <<-DESC
                   MOGeofence framework helps you to trigger notifications based on the exit/entry of geofences. This framework makes use of the Region Monitoring service of CoreLocation to achieve the same.
                   DESC

  s.addDirectUseWarning
  s.frameworks = 'Foundation', 'UIKit', 'CoreLocation'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-Analytics-Beta'
end
