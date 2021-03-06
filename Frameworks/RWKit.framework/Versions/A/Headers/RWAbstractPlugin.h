/*
    RWAbstractPlugin.h
    RapidWeaver Plugin Development Kit

    Copyright (c) 2004 Realmac Software Limited. All rights reserved.
*/

#import <Cocoa/Cocoa.h>

#import "RWKit/RWPluginProtocol.h"
#import "RWKit/RWDocumentProtocol.h"

@class RMHTML;
@class RWSharedStorage;

extern NSString *const kRWPluginChangedNotification;
extern NSString *const kRWPluginChangedInvertNotification;
extern NSString *const kRWPluginExportStatusNotification;
extern NSString *const kRWCurrentMediaChangedNotification;
extern NSString *const kRWPluginPageSettingsRequestNotification;
extern NSString *const kRWDoubleClickedMediaNotification;

@interface RWAbstractPlugin : NSObject <RWPlugin, NSCoding>

- (NSDocument <RWDocument> *)document;

- (NSObject <RWPage> *)page;

+ (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)params;
- (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)params;

- (NSString *)contentHTML:(NSDictionary *)params;
- (NSString *)sidebarHTML:(NSDictionary *)params;
- (NSString *)pageContentHeaders:(NSDictionary *)params;

- (void)broadcastPluginChanged;
- (void)broadcastPluginChangedInvert;
- (void)broadcastPluginExportStatus:(NSString *)message progress:(CGFloat)percent;
- (void)broadcastMediaChanged;
- (void)broadcastPluginSettingsRequest;

- (NSArray *)directoryContents:(NSString *)path;

- (NSString *)tempFilesDirectory:(NSString *)name;
+ (NSString *)tempFilesDirectory:(NSString *)name forPlugin:(RWAbstractPlugin *)plugin;
+ (NSString *)tempFilesDirectory:(NSString *)name forUniqueID:(NSString *)unique;

// Return paths for temporary file storage. These calls don't create the folder.
// Return paths of the form:
// --> path/to/tmp/RapidWeaver
// --> path/to/tmp/RapidWeaver/processID

+ (NSString *)pathToTempDirectory;
+ (NSString *)pathToAppTempDirectory; // Process ID version.

- (NSString *)pathToThemeFile:(NSString *)file params:(NSDictionary *)params correction:(NSInteger)depth;

- (NSMutableDictionary *)pluginSettingsValueForDisplay:(NSString *)display value:(id)value;

- (NSMutableString *)updatePageTemplate:(NSMutableString *)pageTemplate params:(NSDictionary *)params depth:(NSInteger)depth;

- (NSMutableDictionary *)contentOnlySubpageWithHTML:(NSString *)content name:(NSString *)name;
- (NSMutableDictionary *)contentOnlySubpageWithData:(NSData *)content name:(NSString *)name;
- (NSMutableDictionary *)contentOnlySubpageWithEntireHTML:(NSString *)content name:(NSString *)name;

- (NSMutableDictionary *)customSubpageWithData:(NSData *)content name:(NSString *)name destination:(NSString *)destination;

- (void)cancelExport;

- (NSMutableDictionary *)pluginDefaults;
- (void)setPluginDefaults:(NSDictionary *)defaults;

- (RWSharedStorage *)sharedPluginStorage;

#pragma mark Resource Access & Linking

// Returns a flat list of site resources.

- (NSArray *)resourceInfoList;

// Returns a URL string that takes into account the user's current link setting as specified in the preferences.
// Passing nil will result in an empty string being returned.
// Note: Results are only valid if called during export!

- (NSString *)linkForResourceWithIdentifier:(NSString *)identifier;

#pragma mark NSURL Bookmark Support

- (NSString *)registerFileURL:(NSURL *)fileURL error:(NSError **)error;
- (void)removeFileReferenceForToken:(NSString *)token;
- (NSURL *)fileURLForToken:(NSString *)token error:(NSError **)error;

@end
