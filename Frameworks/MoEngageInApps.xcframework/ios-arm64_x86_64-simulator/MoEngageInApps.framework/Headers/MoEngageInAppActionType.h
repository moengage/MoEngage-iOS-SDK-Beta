//
//  MoEngageInAppActionType.h
//  MoEngageInApps
//
//  Created by Chengappa C D on 06/11/19.
//  Copyright © 2019 MoEngage. All rights reserved.
//

#import "MoEngageModelObject.h"

/// MoEngageInAppActionType defines the action type performed by the inApp click
typedef enum MoEngageInAppActionType: NSUInteger {
    NavigationAction,
    CustomAction
} MoEngageInAppActionType;
