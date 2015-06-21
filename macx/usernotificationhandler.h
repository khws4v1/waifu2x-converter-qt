#import <Foundation/NSObject.h>

@interface UserNotificationHandler : NSObject
+ (void)sendNotification:(NSString *)title informativeText:(NSString *)informativeText;
@end
