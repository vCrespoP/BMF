//
//  BMFActionSheetActivity.h
//  BMF
//
//  Created by Jose Manuel Sánchez Peñarroja on 14/03/14.
//  Copyright (c) 2014 José Manuel Sánchez. All rights reserved.
//

#import "BMFActivity.h"

typedef enum : NSUInteger {
    BMFActionSheetActivityShowInView,
    BMFActionSheetActivityShowFromTabBar,
    BMFActionSheetActivityShowFromBarButtonItem,
    BMFActionSheetActivityShowFromToolbar,
	BMFActionSheetActivityShowFromRect,
} BMFActionSheetActivityShowMode;

/// This activity uses its children activities to fill an actionsheet
@interface BMFActionSheetActivity : BMFActivity

/// YES by default
@property (nonatomic, assign) BOOL showsCancelButton;

/// BMFActionSheetActivityShowInView by default
@property (nonatomic, assign) BMFActionSheetActivityShowMode showMode;

/// YES by default
@property (nonatomic, assign) BOOL showAnimated;

/// For when showMode is BMFActionSheetActivityShowFromBarButtonItem
@property (nonatomic, weak) UIBarButtonItem *barButtonItem;

/// For when showMode is BMFActionSheetActivityShowFromToolbar
@property (nonatomic, weak) UIToolbar *toolbar;

/// For when showMode is BMFActionSheetActivityShowFromRect
@property (nonatomic, assign) CGRect rect;

/// For when showMode is BMFActionSheetActivityShowFromView and BMFActionSheetActivityShowFromRect. If not set it will default to the viewController.view
@property (nonatomic, weak) UIView *containerView;

@end
