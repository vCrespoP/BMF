//
//  TNFileLoader.m
//  DataSources
//
//  Created by José Manuel Sánchez on 22/10/13.
//  Copyright (c) 2013 treenovum. All rights reserved.
//

#import "BMFFileLoader.h"

#import "BMF.h"

@implementation BMFFileLoader {
	BOOL shouldCancel;
}

@synthesize progress = _progress;

- (id)init {
    self = [super init];
    if (self) {
		_progress = [[BMFProgress alloc] init];
		_progress.progressMessage = BMFLocalized(@"Load File", nil);
    }
    return self;
}

- (void) cancel {
	shouldCancel = YES;
	
	[_progress stop:[NSError errorWithDomain:@"com.bmf.UserCancel" code:BMFErrorCancelled userInfo:@{ NSLocalizedDescriptionKey : BMFLocalized(@"Cancelled", nil) }]];
}

- (void) load:(BMFCompletionBlock) completionBlock {
	
	BMFAssertReturn(self.fileUrl);
	BMFAssertReturn(completionBlock);
	
	
	[self.progress start:self.fileUrl.absoluteString];
	
	dispatch_async(dispatch_get_global_queue(0, 0), ^{
		
		NSError *error = nil;
		id object = [NSData dataWithContentsOfURL:_fileUrl options:0 error:&error];
		
		dispatch_async(dispatch_get_main_queue(), ^{
			
			[self.progress stop:error];
			
			if (shouldCancel) {
				shouldCancel = NO;
				completionBlock(nil,[NSError errorWithDomain:@"Loader" code:BMFErrorCancelled userInfo:@{ NSLocalizedDescriptionKey : BMFLocalized(@"Action cancelled", nil) }]);
				return;
			}
			
			completionBlock(object,error);
		});
	});
	
}

@end
