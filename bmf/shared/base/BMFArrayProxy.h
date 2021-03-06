//
//  BMFProxy.h
//  BMF
//
//  Created by Jose Manuel Sánchez Peñarroja on 10/03/14.
//  Copyright (c) 2014 José Manuel Sánchez. All rights reserved.
//

#import <Foundation/Foundation.h>

//#import "BMFTypes.h"

#import "BMFAspectProtocol.h"

#if TARGET_OS_IPHONE
#import "BMFViewControllerBehaviorProtocol.h"
#import "BMFBehaviorsViewControllerProtocol.h"
#endif

@class RACSignal;

@interface BMFArrayProxy : NSObject <BMFAspectProtocol
#if TARGET_OS_IPHONE
,BMFViewControllerBehaviorProtocol>
#else
>
#endif

#if TARGET_OS_IPHONE
@property (nonatomic, weak) IBOutlet UIViewController<BMFBehaviorsViewControllerProtocol> *owner;
#endif

@property (nonatomic, weak) id object;

@property (nonatomic, readonly) NSMutableSet *destinationObjects;

/// This block is called every time a destination object is added or removed. Here you should assign nil as delegate, and then assign the delegate again. This is needed because Apple caches the response of respondsToSelector on assignment
//@property (nonatomic, copy) BMFActionBlock destinationsChangedBlock;

/// Signal that sends a next every time the destinationObjects change
@property (nonatomic, readonly) RACSignal *destinationsSignal;
//+ (RACSignal *) destinationsSignal;

- (void) addDestinationObject:(id) object;
- (void) removeDestinationObject:(id) object;
- (void) removeAllDestinationObjects;

- (BOOL) conformsToProtocol:(Protocol *)aProtocol;

/// Call this method to use the arrayproxy as a delegate of an object. If you set the delegate directly it might cache the respondsToSelector calls and if some destinationObjects are added later they won't get called
- (void) makeDelegateOf:(id)object withSelector:(SEL)selector;
- (void) removeDelegateOf:(id)object withSelector:(SEL)selector;

- (instancetype)init;
+ (instancetype)new;

@end
