//
//  MoEngageInAppDebuggingService.h
//  MoEngageInApps
//
//  Created by Chengappa C D on 01/11/21.
//  Copyright © 2021 MoEngage. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MoEngageInAppDebuggingService : NSObject

-(void)getGeneralInAppsListForInstanceID:(NSString* _Nullable)instanceID withCompletionBlock:(void(^_Nullable)(NSArray* _Nullable generalInAppList))completionBlock;
-(void)getTriggerInAppsListForInstanceID:(NSString* _Nullable)instanceID withCompletionBlock:(void(^_Nullable)(NSArray* _Nullable triggerInAppList))completionBlock;
-(void)getEmbeddedInAppsListForInstanceID:(NSString*_Nullable)instanceID withCompletionBlock:(void (^ _Nullable)(NSMutableDictionary * _Nullable))completionBlock;
-(void)getSelfHandledInAppListForInstanceID:(NSString* _Nullable)instanceID withCompletionBlock:(void(^_Nullable)(NSArray* _Nullable selfHandledInAppList))completionBlock;
-(void)getInAppStateListForInstanceID:(NSString* _Nullable)instanceID withCompletionBlock:(void(^_Nullable)(NSArray* _Nullable inAppStateList))completionBlock;
-(void)getInAppStateForCID:(NSString* _Nullable)cid forInstanceID:(NSString* _Nullable)instanceID withCompletionBlock:(void(^_Nullable)(NSDictionary* _Nullable inAppState))completionBlock;
-(void)getSessionTriggerInAppsListForInstanceID:(NSString*)instanceID withCompletionBlock:(void (^ _Nullable)(NSArray * _Nullable))completionBlock;
NS_ASSUME_NONNULL_BEGIN
+(instancetype)sharedInstance;
-(void)previewGeneralInAppForCID:(NSString*)cid forInstanceID:(NSString* _Nullable)instanceID;
#if !TARGET_OS_TV
-(void)previewEmbeddedInAppForCID:(NSString*)cid forInstanceID:(NSString* _Nullable)instanceID;
#endif
-(void)previewSessionTriggerInAppForCID:(NSString*)cid forInstanceID:(NSString*)instanceID;
-(void)previewSelfHandledInAppForCID:(NSString*)cid forInstanceID:(NSString* _Nullable)instanceID;
-(void)previewTriggerInAppForCID:(NSString*)cid forInstanceID:(NSString* _Nullable)instanceID;

@end

NS_ASSUME_NONNULL_END
