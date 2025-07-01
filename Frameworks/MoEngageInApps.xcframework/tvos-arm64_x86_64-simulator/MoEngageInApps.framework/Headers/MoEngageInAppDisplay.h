//
//  MoEngageInAppDisplay.h
//  MoEngageInApps
//
//  Created by Chengappa C D on 31/07/19.
//  Copyright © 2019 MoEngage. All rights reserved.
//

#import "MoEngageModelObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface MoEngageInAppDisplayRules : MoEngageModelObject <NSCoding>
@property(nonatomic, strong) NSArray<NSString *>* contexts;
@property(nonatomic, strong) NSArray<NSString *>* showInScreens;
@end

@interface MoEngageInAppDisplay : MoEngageModelObject <NSCoding>
@property(nonatomic, strong) MoEngageInAppDisplayRules* rules;
@property(nonatomic, assign) NSInteger delay;
@end

NS_ASSUME_NONNULL_END
