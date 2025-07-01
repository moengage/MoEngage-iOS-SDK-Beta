//
//  MoEngageInAppController.h
//  MoEngageInApps
//
//  Created by Chengappa C D on 20/10/21.
//  Copyright © 2021 MoEngage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <MoEngageCore/MoEngageCore-Swift.h>
#import "MoEngageInAppViewPayload.h"
#import "MoEngageInAppDataManager.h"
#if !TARGET_OS_TV
#import "MoEngageInAppContainerView.h"
#endif
#import "MoEngageInAppStatsTracking.h"

#import "MoEngageInAppCommonUtils.h"

@protocol MoEngageInAppNativeDelegate;
@class MoEngageInAppSelfHandledCampaign;
@class MoEngageInAppDataManager;
@class MoEngageInAppPrimaryContainerView;
@class MoEngageInAppActionHandler;
@class MoEngageInAppConfigurationHandler;
@class MoEngageInAppSelfHandledData;

@protocol MoEngageInAppNativeDelegate;
@class MoEngageInAppSelfHandledCampaign;
@class MoEngageInAppViewPayload;
@class MoEngageInAppPrimaryContainerView;
@class MoEngageAccountMeta;
@class MoEngageSDKInstance;
@class MoEngageInAppDataManager;
@class MoEngageSDKConfig;
@class MoEngageInAppCampaign;
@class MoEngageInAppCampaignMeta;
@class MoEngageInAppActionHandler;
@class  MoEngageTriggerEvaluatorManager;

NS_ASSUME_NONNULL_BEGIN

typedef void(^MOInAppTemplateRequestCompletionBlock)(MoEngageInAppViewPayload* _Nullable campaignPayload);
typedef void(^MOInAppViewCompletionBlock)(MoEngageInAppPrimaryContainerView* _Nullable inAppView, MoEngageInAppViewPayload* _Nullable campaignPayload);

typedef MoEngageNudgePosition(^nonIntrusiveInAppCompletion)(void);

typedef enum {
  MoEngageInAppSyncTypeAppOpen,
  MoEngageInAppSyncTypeImmediateSync,
} MoEngageInAppSyncType;

@interface MoEngageInAppController : NSObject

@property(nonatomic, strong) MoEngageAccountMeta* accountMeta;
@property(nonatomic, strong) MoEngageSDKInstance* configController;
@property(nonatomic, strong) MoEngageInAppDataManager* inAppDataManager;
#if !TARGET_OS_TV
@property(nonatomic, strong) MoEngageInAppConfigurationHandler* configurationHandler;
#endif
/// Delegate to get the MoEngageInAppNativeDelegate Protocol callbacks.
@property(nonatomic, weak, nullable) id<MoEngageInAppNativeDelegate> inAppNativeDelegate;
@property(nonatomic, assign) BOOL inAppFetchApiInProgress;
@property(nonatomic, assign) BOOL inAppFetchedSuccessfully;
@property(nonatomic, strong, nullable) NSDate* inAppSyncTimeInSession;
@property(nonatomic, strong) MoEngageTriggerEvaluatorManager* triggerEvaluator;
@property(nonatomic, strong) void(^_Nullable multipleSelfHandledInAppCompletion)(MoEngageInAppSelfHandledData* _Nullable campaignData);
@property(nonatomic, copy) void(^_Nullable selfHandledInAppCompletion)(MoEngageInAppSelfHandledCampaign* _Nullable inAppData,  MoEngageAccountMeta* _Nullable accountMeta);
@property(nonatomic, assign) BOOL hasSessionChanged;
#if !TARGET_OS_TV
@property(nonatomic, strong) NSMutableArray<nonIntrusiveInAppCompletion>* cachedNudgePosition;
@property(nonatomic, strong) NSHashTable<MoEngageInAppPrimaryContainerView*>* nudgeViewsArray;
#endif

@property (nullable, nonatomic, copy) NSString *lastSyncedUid;
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *lastSyncedIdentities;
@property (nonatomic, strong) NSOperationQueue *fetchQueue;

-(instancetype)initWithSDKInstance:(nonnull MoEngageSDKInstance *)sdkInstance;
-(instancetype _Nonnull)init NS_UNAVAILABLE;
-(void)initializeInAppController;

-(void)applicationEnteredForeground;
-(void)applicationInActive;
-(void)updateModule;
- (void)updateModuleWithSyncType:(MoEngageInAppSyncType)syncType previousIdentities:(NSDictionary<NSString *, NSString *> *)previousIdentities;
-(void)userReset:(void (^)(void))completionHandler;
-(void)resetLastSyncedUidAndIdentities;
#if !TARGET_OS_TV
-(void)showInAppViaPushWithInfo:(NSDictionary*)pushInfo;
-(void)orientationChanged;
#endif
-(void)keyboardShowed;
-(void)keyboardHidden;
-(void)syncInAppStatsData:(void (^)(void))completionHandler;
-(void)removeInAppStorageData:(void (^)(void))completionHandler;
- (void)sessionChanged;
-(void)inAppSyncCompleted;
-(BOOL)isInAppEnabled;
-(BOOL)shouldSyncInAppFetchType:(MoEngageInAppSyncType)syncType;;
-(void)clearExpiredInAppImages;
-(NSDictionary*)getCurrentScreenAndContextInfoDict;
- (NSArray<NSDictionary<NSString *, id> *> *)convertCampaignsToDictionaries:(NSArray<MoEngageInAppCampaignMeta *> *)campaigns;
-(NSMutableArray<MoEngageInAppCampaignMeta *>*)getEligibleCampaignForMultipleContext:(NSArray*)campaignsArray forSDKCampaignType:(MoEngageInAppSDKCampaignType)sdkCmpType inPrioratizingStage:(BOOL)inPrioratizing;
-(void)updateInAppStatusForControlGroupFailureWithCampaignMeta:(MoEngageInAppCampaignMeta*)campaignMeta;

#pragma mark- InApp Delegate Handling

-(void)setInAppDelegate:(id<MoEngageInAppNativeDelegate> _Nullable)delegate;
-(void)resetInAppDelegate;

#pragma mark- Contexts Methods

-(void)setCurrentInAppContexts:(NSArray*)contexts;
-(NSArray<NSString*>*)getCurrentInAppContexts;
-(void)invalidateInAppContexts;

#pragma mark- Show In-App Pop

-(void)showInApp;
-(void)blockInAppInViewController:(UIViewController* _Nonnull)viewcontroller;
-(void)fetchInAppWithCampaignID:(NSString*)campaignID;

#pragma mark- Nudge Campaign
#if !TARGET_OS_TV
-(NSMutableArray<MoEngageInAppCampaignMeta *>*)getNudgeCampaignsForPosition:(MoEngageNudgePosition)nudgePosition;
-(void)removeNudgeCampaignsNotToBeProcessed:(NSMutableArray<MoEngageInAppCampaignMeta *>*)checkedCampaigns;
-(void)showNudgeAtPosition:(MoEngageNudgePosition)nudgePosition;
#endif

#pragma mark- SelfHandled Campaign
-(MoEngageInAppSelfHandledCampaign*)getSelfHandledInfoForInAppPayload:(MoEngageInAppViewPayload*)inAppPayload;
-(void)getSelfHandledInAppWithCompletionBlock:(void(^)(MoEngageInAppSelfHandledCampaign* _Nullable campaignInfo, MoEngageAccountMeta* _Nullable accountMeta)) completionBlock;
-(void)selfHandledShownWithCampaignInfo:(MoEngageInAppSelfHandledCampaign*)campaignInfo;
-(void)selfHandledClickedWithCampaignInfo:(MoEngageInAppSelfHandledCampaign*)campaignInfo;
-(void)selfHandledDismissedWithCampaignInfo:(MoEngageInAppSelfHandledCampaign*)campaignInfo;


#pragma mark- Disable InApps
-(void)disableInApps;

#pragma mark- Action Handler
-(MoEngageInAppActionHandler*)getActionHandler;

#pragma mark- Fetch InApp Method
-(void)fetchInAppWithCampaignMeta:(MoEngageInAppCampaignMeta*)campaignMeta forPreview:(BOOL)forPreviewFlow withTriggerInfo:(NSDictionary* _Nullable)triggerInfoDict withCompletionBlock:(MOInAppTemplateRequestCompletionBlock)completionBlock;

#pragma mark- InApp Creation Methods
-(void)createInAppWithTemplatePayload:(MoEngageInAppViewPayload*)templatePayload  withCompletionBlock:(void (^_Nullable)(void))completionBlock;
-(void)createNativeInAppViewWithTemplatePayload:(MoEngageInAppViewPayload*)templatePayload withCompletionBlock:(void (^_Nullable)(void))completionBlock;
-(void)createNativeInAppViewWithPayload:(MoEngageInAppViewPayload*)templatePayload andCompletionBlock:(MOInAppViewCompletionBlock)completionBlock;
#if !TARGET_OS_TV
-(void)attachNudgeView:(MoEngageInAppPrimaryContainerView*)nudgeView withPayload:(MoEngageInAppViewPayload*)payload;
#endif

-(void)eventTrackedWithEventName:(NSString *)event andAttributes:(NSDictionary<NSString *,id> *)attrDict;

#pragma mark- InApp Tracking Methods
-(void)trackInAppStat:(MoEngageInAppStatType)statType forCampaigns:(NSArray<MoEngageInAppCampaignMeta*>*)campaignsArray;
@end

NS_ASSUME_NONNULL_END
