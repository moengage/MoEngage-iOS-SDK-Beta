//
//  MoEngage.h
//  MoEngageSDK
//
//  Created by Chengappa C D on 20/04/18.
//  Copyright © 2018 MoEngage. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "MoEngageSDK.h"
@interface MoEngage : NSObject


#pragma mark - Shared instance
+(instancetype _Nonnull)sharedInstance;

/// Making the init method private as this Class has Singleton implementation
-(instancetype _Nonnull)init NS_UNAVAILABLE;

#pragma mark - Initialization Methods

/**
 Call this method in the AppDelegate in application:didFinishLaunchingWithOptions: to initialize the SDK for Test Environment with MOSDKConfig instance
 @param sdkConfig MOSDKConfig instance with the required config to initialize SDK
 @param launchOptions Launch Options obtained application:didFinishLaunching: method
 @version 7.0.0 and above
 */
-(void)initializeTestWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions __deprecated_msg("Use initializeDefaultTestInstanceWithConfig:andLaunchOptions instead.");

-(void)initializeTestInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions;

-(void)initializeTestInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andSDKState:(MoEngageSDKState)sdkState;

-(void)initializeDefaultTestInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions;

-(void)initializeDefaultTestInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig  andSDKState:(MoEngageSDKState)sdkState;
/**
 Call this method in the AppDelegate in application:didFinishLaunchingWithOptions: to initialize the SDK for Live Environment with MOSDKConfig instance
 @param sdkConfig MOSDKConfig instance with the required config to initialize SDK
 @param launchOptions Launch Options obtained application:didFinishLaunching: method
 @version 7.0.0 and above
 */
-(void)initializeLiveWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions __deprecated_msg("Use initializeDefaultLiveInstanceWithConfig:andLaunchOptions instead.");

-(void)initializeLiveInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions;

-(void)initializeLiveInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andSDKState:(MoEngageSDKState)sdkState;

-(void)initializeDefaultLiveInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andLaunchOptions:(NSDictionary* _Nullable)launchOptions;

-(void)initializeDefaultLiveInstanceWithConfig:(MOSDKConfig* _Nonnull)sdkConfig andSDKState:(MoEngageSDKState)sdkState;

#pragma mark - Messaging Module
#pragma mark Push Notification
/**
 Method to register your app for push notification with APNS for iOS10 and above.
 @param categories to set categories for supporting Notification Actions (iOS10 and above)
 @param delegate to set the delegate for UNUserNotificationCenter.
 @version 4.0.0 and above
 */
-(void)registerForRemoteNotificationWithCategories:(NSSet<UNNotificationCategory*>* _Nullable)categories withUserNotificationCenterDelegate:(id _Nullable )delegate API_UNAVAILABLE(tvos);

/**
 * Method to send notification categories to SDK to support Notification Action in iOS10 and above
 */
-(void)setUserNotificationCategories:(NSSet<UNNotificationCategory*>*_Nullable)categories API_UNAVAILABLE(tvos);

/**
 Use this method to pass the device token/push token generated by APNS for your app to MoEngage SDK which can be later used for sending push notification to your app users.
 
 Call this method in AppDelegate in application:didRegisterForRemoteNotificationsWithDeviceToken:.
 @param deviceToken The token of the device for push notifications
 */
-(void)setPushToken:(NSData *_Nullable)deviceToken API_UNAVAILABLE(tvos);

/**
 Call this method in AppDelegate in didReceiveRemoteNotification
 @param application The application instance
 @param userInfo The info dict with the push
 */
-(void)didReceieveNotificationinApplication:(UIApplication*_Nullable)application withInfo:(NSDictionary* _Nonnull)userInfo API_UNAVAILABLE(tvos);

/**
 Call this method in AppDelegate in didFailToRegisterForRemoteNotificationsWithError
 */
-(void)didFailToRegisterForPush API_UNAVAILABLE(tvos);

/**
 Call this method in AppDelegate in userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:
 @since iOS 10
 @version 3.0.0 and above
 */
-(void)userNotificationCenter:(UNUserNotificationCenter *_Nonnull)center didReceiveNotificationResponse:(UNNotificationResponse *_Nonnull)response API_UNAVAILABLE(tvos);

/**
 Method to detect App Launches due to MoEngage Silent Push Notifications
 @param launchOptions Launch Options obtained from application:didFinishLaunching: method
 @version 7.1.0 and above
*/
+(BOOL)isMoEngageSilentPushAppLaunchWithLaunchOptions:(NSDictionary*_Nonnull)launchOptions API_UNAVAILABLE(tvos);

/**
 Method to disable the badgeReset
 @param disableBadgeReset Pass true to disable badge reset.
 @version 8.0.0 and above
*/
-(void)setDisableBadgeReset:(BOOL)disableBadgeReset API_UNAVAILABLE(tvos);

#pragma mark- Analytics Module
#pragma mark Install/Update tracking

/**
 Use this method to set the app status.
 @param appStatus - Two possible enum values - APP_UDPATE (for app updates) and APP_INSTALL (for new installs)
 */
-(void)appStatus:(AppStatus)appStatus;

-(void)appStatus:(AppStatus)appStatus forAppID:(NSString* _Nullable)appID;

#pragma mark Track Event

/**
 Use this method to set a user attribute which is datetime or time.
 @param timestamp The timestamp in epoch format.
 */
-(void)setUserAttributeTimestamp:(double)timestamp forKey:(NSString *_Nonnull)key __deprecated_msg("Use setUserAttributeEpochTime:forKey of MOAnalytics instead.");

/**
 Use this method to set a user attribute which is NSDate instance.
 @param date The NSDate instance value to track.
 */
-(void)setUserAttributeDate:(NSDate* _Nonnull)date forKey:(NSString *_Nonnull)key;

/**
 Use this method to set a user attribute which is NSDate instance.
 @param dateStr Date String in ISO date format [yyyy-MM-dd'T'HH:mm:ss'Z'].
 */
-(void)setUserAttributeISODateString:(NSString* _Nonnull)dateStr forKey:(NSString *_Nonnull)key __deprecated_msg("Use setUserAttributeISODate:forKey of MOAnalytics instead.");

/**
 Use this method to set user attribute location.
 @param location MOGeoLocation instance for location coordinates
 */
-(void)setUserAttributeLocation:(MOGeoLocation* _Nonnull)location forKey:(NSString *_Nonnull)key __deprecated_msg("Use setLocation:forKey of MOAnalytics instead.");

#pragma mark Default User Attributes
/**
 Use this method to set a unique Identifier(ID) for a user. Please make sure you use this method wisely to only set the unique ID and not use it to update the unique ID, make use of `setAlias:` method for updating the unique ID for a user.
 @param uniqueID A Unique ID to filter the specific user from your user base. Please make sure this value is not hardcoded.
 @attention Please make sure not to use this method to update the unique ID of a logged in user, use setAlias: instead
 @version 3.3.0 and above
 */
-(void)setUserUniqueID:(id _Nullable )uniqueID __deprecated_msg("Use setUniqueID: of MOAnalytics instead.");

/**
 Use this method to track Email ID of a user.
 @param emailID Email ID value to be tracked.
 @version 3.3.0 and above
 */
-(void)setUserEmailID:(NSString*_Nullable)emailID __deprecated_msg("Use setEmailID: of MOAnalytics instead.");

/**
 Use this method to track User Name of a user.
 @param name User Name value to be tracked for the user.
 @version 3.3.0 and above
 */
-(void)setUserName:(NSString*_Nullable)name __deprecated_msg("Use setName: of MOAnalytics instead");

/**
 Use this method to track First Name of a user.
 @param firstName User First Name value to be tracked for the user.
 @version 3.3.0 and above
 */
-(void)setUserFirstName:(NSString*_Nullable)firstName __deprecated_msg("Use setFirstName: of MOAnalytics instead.");


/**
 Use this method to track Last Name of a user.
 @param lastName User last name value to be tracked for the user.
 @version 3.3.0 and above
 */
-(void)setUserLastName:(NSString*_Nullable)lastName __deprecated_msg("Use setLastName: of MOAnalytics instead.");


/**
 Use this method to track Phone Number of a user.
 @param phNumber Phone Number of user to be tracked.
 @version 3.3.0 and above
 */
-(void)setUserMobileNo:(id _Nullable )phNumber __deprecated_msg("Use setMobileNo: of MOAnalytics instead.");


/**
 Use this method to track gender of a user.
 @param gender UserGender value indicating if user is MALE or FEMALE.
 @version 3.3.0 and above
 */
-(void)setUserGender:(UserGender)gender __deprecated_msg("Use setGender: of MOAnalytics instead.");

/**
 Use this method to track Date of birth of a user.
 @param date NSDate instance of birthdate of user.
 @version 3.3.0 and above
 */
-(void)setUserDateOfBirth:(NSDate*_Nullable)date __deprecated_msg("Use setDateOfBirth: of MOAnalytics instead.");

/**
 Use this method to track location of a user.
@param location MOGeoLocation instance for location coordinates
 */
-(void)setUserLocation:(MOGeoLocation* _Nonnull)location __deprecated_msg("Use setLocation: of MOAnalytics instead.");

/**
 Use this method to track push preference set by a user.
 @param isPushEnabled A Bool value indicating if the user has enabled push preference in the app.
 @version 3.8.1 and above
 */
-(void)trackUserPushPreference:(BOOL)isPushEnabled;

-(void)trackUserPushPreference:(BOOL)isPushEnabled forAppID:(NSString* _Nullable)appID;

#pragma mark Process URL Method

/**
 Method to process URL for Analytics module source tracking
 @param url Deeplink URL to be processes
 */
-(void)processURL:(NSURL* _Nonnull)url;

#pragma mark- Utility Methods

/**
 Use this method to enable logs for the MoEngage SDK.
 */
+ (void)enableSDKLogs:(BOOL)enable;

+ (void)enableSDKLogs:(BOOL)enable forAppID:(NSString* _Nullable)appID;

+ (void)enableDefaultConsoleLogger:(BOOL)enable;

/**
 Method to dismiss the RichLanding Controller manually
 @param animate Bool value indicating if the dismissing the controller should be with animation
 */
-(void)dismissRichLandingWebViewControllerWithAnimation:(BOOL)animate;

/**
 Method to enable all the SDK features
 */
-(void)enableSDK;

-(void)enableSDKForAppID:(NSString* _Nullable)appID;

/**
 Method to disable all the SDK features
 */
-(void)disableSDK;

-(void)disableSDKForAppID:(NSString* _Nullable)appID;

#pragma mark- Default Config
///Method to obtain the default config
-(MOSDKConfig* _Nullable)getDefaultSDKConfiguration;
///Method to obtain the config for given appID
-(MOSDKConfig* _Nullable)getSDKConfigurationForAppID:(NSString* _Nullable)appID;
@end



