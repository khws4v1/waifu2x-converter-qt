#import "usernotificationhandler.h"
#import <Cocoa/Cocoa.h>

@implementation UserNotificationHandler

+ (void)sendNotification:(NSString *)title informativeText:(NSString *)informativeText
{
    NSUserNotification *notification = [[NSUserNotification alloc] init];
    notification.title = title;
    notification.informativeText = informativeText;
    notification.soundName = NSUserNotificationDefaultSoundName;
    [[NSUserNotificationCenter defaultUserNotificationCenter] deliverNotification:notification];
}

@end
