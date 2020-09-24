//
//  BMFBaseCellConfigurator.m
//  Example
//
//  Created by Jose Manuel Sánchez Peñarroja on 02/04/14.
//  Copyright (c) 2014 José Manuel Sánchez. All rights reserved.
//

#import "BMFViewConfigurator.h"

static NSMutableArray *viewConfigurators = nil;

@implementation BMFViewConfigurator

+ (void) load {
	if (!viewConfigurators) {
		viewConfigurators = [NSMutableArray array];
	}
}

+ (NSArray *) registeredClasses {
	return [NSArray arrayWithArray:viewConfigurators];
}

+ (void) register {
	BMFAssertReturn([self conformsToProtocol:@protocol(BMFViewConfiguratorProtocol)]);
	
	[viewConfigurators addObject:self];
}

+ (void) unregister {
	BMFAssertReturn([self conformsToProtocol:@protocol(BMFViewConfiguratorProtocol)]);

	[viewConfigurators removeObject:self];
}

+ (Class<BMFViewConfiguratorProtocol>) configuratorForView:(id) view kind:(NSString *)kind item:(id) item inView:(id)containerView {
	NSArray *available = [self registeredClasses];
	
	Class<BMFViewConfiguratorProtocol> chosenConfiguratorClass = nil;
	NSInteger maxPriority = -1;
	
	for (Class<BMFViewConfiguratorProtocol> configuratorClass in available) {
		if ([configuratorClass canConfigure:view kind:kind withItem:item inView:containerView]) {
			NSInteger priority = [configuratorClass priority];
			if (priority>maxPriority) {
				maxPriority = priority;
				chosenConfiguratorClass = configuratorClass;
			}
		}
	}
	
	return chosenConfiguratorClass;
}

+ (NSInteger) priority {
	return BMFViewConfiguratorAppPriority;
}

@end
