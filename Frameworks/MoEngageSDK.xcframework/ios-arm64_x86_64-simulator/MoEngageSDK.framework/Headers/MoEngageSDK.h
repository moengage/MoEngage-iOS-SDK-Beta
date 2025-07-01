//
//  MoEngageSDK.h
//  MoEngageSDK
//
//  Created by Rakshitha on 12/10/22.
//  Copyright © 2022 MoEngage. All rights reserved.
//

// In this header, you should import all the public headers of your framework using statements like #import <MoEngageSDK/PublicHeader.h>
#if !defined(__has_include)
#error "MoEngageSDK.h won't be able to import all the modules if your compiler doesn't support __has_include. Please import the headers individually."
#else

#import <MoEngageCore/MoEngageCore-Swift.h>

#if __has_include(<MoEngageSDK/MoEngageSDK-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-umbrella.h>
#elif TARGET_OS_IOS && __has_include(<MoEngageSDK/MoEngageSDK-framework-iOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-framework-iOS-umbrella.h>
#elif TARGET_OS_TV && __has_include(<MoEngageSDK/MoEngageSDK-framework-tvOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-framework-tvOS-umbrella.h>
#elif TARGET_OS_IOS && __has_include(<MoEngageSDK/MoEngageSDK-library-iOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-library-iOS-umbrella.h>
#elif TARGET_OS_TV && __has_include(<MoEngageSDK/MoEngageSDK-library-tvOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-library-tvOS-umbrella.h>
#elif TARGET_OS_IOS && __has_include(<MoEngageSDK/MoEngageSDK-iOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-iOS-umbrella.h>
#elif TARGET_OS_TV && __has_include(<MoEngageSDK/MoEngageSDK-tvOS-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-tvOS-umbrella.h>
#elif __has_include(<MoEngageSDK/MoEngageSDK-framework-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-framework-umbrella.h>
#elif __has_include(<MoEngageSDK/MoEngageSDK-library-umbrella.h>)
#import <MoEngageSDK/MoEngageSDK-library-umbrella.h>
#else
#error Umbrella header not found use "@import" to import module
#endif

#if __has_include(<MoEngageMessaging/MoEngageMessaging-Swift.h>)
#import <MoEngageMessaging/MoEngageMessaging-Swift.h>
#endif

#endif

