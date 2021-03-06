//
//  NSDictionary+BMFUtils.h
//  BMF
//
//  Created by Jose Manuel Sánchez Peñarroja on 30/01/14.
//  Copyright (c) 2014 treenovum. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BMFTypes.h"

@interface NSDictionary (BMF)

/// Tries to get the value for each key in order and stops as soon as it gets one
- (id) BMF_firstValueForKeys:(NSArray *) keys;

- (NSDictionary *) BMF_map:(BMFMapBlock)block;

- (NSDictionary *) BMF_filter:(BMFFilterBlock)block;

@end
