//
//  BMFViewsAnimationBehavior.h
//  Pods
//
//  Created by Jose Manuel Sánchez Peñarroja on 24/12/14.
//
//

#import <Foundation/Foundation.h>

@protocol BMFAnimationBehaviorProtocol <NSObject>

- (IBAction)runAnimation:(id)sender;

@end

@protocol BMFViewsAnimationBehaviorProtocol <BMFAnimationBehaviorProtocol>

@property (nonatomic, strong) IBOutletCollection(UIView) NSArray *views;

@end
