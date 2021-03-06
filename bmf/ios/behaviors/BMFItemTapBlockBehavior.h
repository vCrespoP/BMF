//
//  BMFItemTapBlockBehavior.h
//  BMF
//
//  Created by Jose Manuel Sánchez Peñarroja on 10/03/14.
//  Copyright (c) 2014 José Manuel Sánchez. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BMFTypes.h"
#import "BMFItemTapBehavior.h"

@interface BMFItemTapBlockBehavior : BMFItemTapBehavior

@property (nonatomic, copy) BMFItemActionBlock itemTapBlock;
@property (nonatomic, copy) BMFItemActionBlock accessoryItemTapBlock;

- (instancetype) initWithView:(UIView *)view tapBlock:(BMFItemActionBlock)tapBlock;

@end
