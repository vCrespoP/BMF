//
//  BMFAspectProtocol.h
//  Pods
//
//  Created by Jose Manuel Sánchez Peñarroja on 25/04/14.
//
//

#import <Foundation/Foundation.h>

@protocol BMFAspectProtocol <NSObject>

@optional

/// This can be used from IB
@property (nonatomic, weak) IBOutlet id owner;

@property (nonatomic, weak) id object;

@end
