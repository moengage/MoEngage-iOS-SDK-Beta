Pod::Spec.new do |s|
  require_relative 'Utilities/spec'
  s.extend MoEngageSDK::Spec
  s.define

  s.summary          = 'MoEngage Rich Notifications for iOS.'
  s.description  = <<-DESC
                   MORichNotification helps you to make use Notification Service Extensions to support media in notifications(Rich Push Notifications). This feature is available from iOS version 10.0 and above. 
                   DESC

  s.addDirectUseWarning
  s.frameworks = 'Foundation', 'UIKit', 'UserNotifications', 'UserNotificationsUI'

  s.dependency 'MoE-Core-Beta'
  s.dependency 'MoE-Analytics-Beta'
  s.dependency 'MoE-Messaging-Beta'
  s.dependency 'MoE-ObjCUtils-Beta'
end
