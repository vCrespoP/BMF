//
//  BMFFlattenSectionsDataStore.h
//  Example
//
//  Created by Jose Manuel Sánchez Peñarroja on 11/04/14.
//  Copyright (c) 2014 José Manuel Sánchez. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BMFDataStoreCombinerStore.h"

@interface BMFFlattenSectionsDataStore : BMFDataStoreCombinerStore

@property (nonatomic, copy) NSString *sectionHeaderTitle;
@property (nonatomic, copy) NSString *sectionFooterTitle;

@end
