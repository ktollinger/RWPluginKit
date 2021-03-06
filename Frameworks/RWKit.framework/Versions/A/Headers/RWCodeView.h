//
//  RWCodeView.h
//  RapidWeaver
//
//  Created by Simon Maddox on 05/12/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//

#import <Cocoa/Cocoa.h>
#import "RWCodeHighlightingController.h"

@interface RWCodeView : NSView

@property (nonatomic, retain) NSString *string;
@property (nonatomic, readonly) IBOutlet NSTextView *textView;
@property (nonatomic, assign) IBOutlet id delegate;

- (void)setShowLineNumbers:(BOOL)flag;
- (void)setLanguage:(NSString *)language;
- (void)setHasBorder:(BOOL)hasBorder;
- (void)setEditable:(BOOL)editable;

@end
