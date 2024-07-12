
Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary      = 'MoEngage for iOS'
  s.description  = <<-DESC
                   MoEngage is a mobile marketing automation company. This framework acts like a umbrella framework to include MoEngageCore, MOAnalytics and MOMessaging frameworks.
                   MoEngageCore contains the central configuration of your app and common Utils and modules to be used accross all the MoEngage frameworks.
                   MOAnalytics framework enables you to track required data regarding user and user's activities inside the app to use the same for effective engagement. 
                   MOMessaging module will help you support all the features related to push notifications in your App.
                   DESC
         
  s.default_subspec = 'Core'
  s.subspec 'Core' do |ss|
    ss.dependency 'MoE-SDK-Beta'
    ss.dependency 'MoE-Core-Beta'
    ss.dependency 'MoE-Analytics-Beta'
    ss.dependency 'MoE-Messaging-Beta'
    ss.dependency 'MoE-ObjCUtils-Beta'
    ss.dependency 'MoE-Security-Beta'
  end

  s.subspec 'InApps' do |ss|
    ss.dependency 'MoE-iOS-SDK-Beta/Core'
    ss.dependency 'MoE-TriggerEvaluator-Beta'
    ss.dependency 'MoE-InApp-Beta'
  end

  s.subspec 'GeoFence' do |ss|
    ss.dependency 'MoE-iOS-SDK-Beta/Core'
    ss.dependency 'MoE-Geofence'
  end

  s.subspec 'RichNotification' do |ss|
    ss.dependency 'MoE-iOS-SDK-Beta/Core'
    ss.dependency 'MoE-RichNotification'
  end

  s.subspec 'RealTimeTrigger' do |ss|
    ss.dependency 'MoE-iOS-SDK-Beta/Core'
    ss.dependency 'MoE-iOS-SDK-Beta/RichNotification'
    ss.dependency 'MoE-RealTimeTrigger'
  end
end
