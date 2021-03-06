//***************************************************************************

// Copyright (C) 2005-2008 Realmac Software Ltd
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface RWFileReference : NSObject

@property (nonatomic, copy) NSString *path;
@property (nonatomic, retain) NSMutableData *alias;

+ (RWFileReference *)referenceTo:(NSString *)pathA relativeTo:(NSString *)pathB;

+ (RWFileReference *)referenceWithDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)propertyList;

- (void)setPath:(NSString *)pathA relativeTo:(NSString *)pathB;

- (BOOL)pathExists;

- (NSString *)resolveRelativeTo:(NSString *)path;

@end

//***************************************************************************
