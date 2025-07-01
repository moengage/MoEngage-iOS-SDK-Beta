//
//  MoEngageInAppDelegate.h
//  MoEngageCore
//
//  Created by Rakshitha on 28/04/22.
//  Copyright © 2022 MoEngage. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MoEngageSDKInstance;

/// This class is used for internal purpose. Do not call any of the methods explicitly.
///  :nodoc:
@interface MoEngageInAppDelegate: NSObject

-(void)trackEvent:(NSString*)eventName withEventAttribute:(NSDictionary*)eventAttribute forSDKInstance:(MoEngageSDKInstance*)sdkInstance;
-(void)logout:(MoEngageSDKInstance*)sdkInstance withCompletionHandler:(void(^)(void))completionHandler;
-(void)updateModule:(MoEngageSDKInstance*)sdkInstance;
-(void)initializeInApp:(MoEngageSDKInstance*)sdkInstance;

-(void)applicationEnteredForeground:(MoEngageSDKInstance*)sdkInstance;
-(void)applicationWillResignActive:(MoEngageSDKInstance*)sdkInstance;
-(void)keyboardWillShow:(MoEngageSDKInstance*)sdkInstance;
-(void)keyboardDidHide:(MoEngageSDKInstance*)sdkInstance;
-(void)StatusBarOrientationChanged:(MoEngageSDKInstance*)sdkInstance;
-(void)showInAppViaPush:(NSNotification*)notification;
-(void)migrateDataFromPreviousVersionsForSDKInstance:(MoEngageSDKInstance*)sdkInstance;
-(void)migrateDataFromNoNEncryptionToEncryptionForSDKInstance:(MoEngageSDKInstance*)sdkInstance currentSDKInstance:(MoEngageSDKInstance*) sdkInstance;
-(void)removeEncryptedFolder:(MoEngageSDKInstance*)sdkInstance;
-(void)syncInAppStatsDataForSDKInstance:(MoEngageSDKInstance*)sdkInstance withCompletionHandler:(void(^)(void))completionHandler;
-(void)removeInAppStorageDataForSDKInstance:(MoEngageSDKInstance*)sdkInstance withCompletionHandler:(void(^)(void))completionHandler;
/// Handle callback for environment change.
/// - Parameter sdkInstance: The instance to migrate.
-(void)migrateEnvironmentForSDK:(MoEngageSDKInstance*)sdkInstance;
/// Handle callback for SDK deinitialization.
/// - Parameter sdkInstance: The instance to deinitialize.
-(void)deinitialize:(MoEngageSDKInstance*)sdkInstance;

/// Identities updated callback.
///
/// - Parameters:
///   - old: The identities before update.
///   - new: The identities after update.
///   - sdkInstance: The instance to update for.
-(void)identitiesUpdatedFrom:(NSDictionary<NSString*, NSString*>*)old to:(NSDictionary<NSString*, NSString*>*)new sdkInstance:(MoEngageSDKInstance*)sdkInstance;

/// Unique updated callback.
///
/// - Parameters:
///   - previousId: The uniqueId before update.
///   - newId: The uniqueId after update.
///   - sdkInstance: The instance to update for.
- (void)userUniqueIdUpdatedForSDKInstance:(MoEngageSDKInstance *)sdkInstance fromPreviousId:(nullable NSString *)previousId toNewId:(NSString *)newId;

/// Callback on new session created
/// - Parameter sdkInstance: The instance  for which new session createds
-(void)userSessionCreated:(MoEngageSDKInstance*)sdkInstance;

@end

