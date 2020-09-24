//
//  BMFCompoundEvent.h
//  Pods
//
//  Created by Jose Manuel Sánchez Peñarroja on 24/04/14.
//
//

#import "BMFEvent.h"

@interface BMFCompoundEvent : BMFEvent

- (instancetype) initWithEvents:(NSArray *) events;
- (instancetype) init __attribute__((unavailable("Use initWithEvents: instead")));

@end
