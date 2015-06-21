#include "usernotificationwrapper.h"
#include <QtMacExtras>
#import "usernotificationhandler.h"

void UserNotificationWrapper::sendNotification(const QString &title,
                                               const QString &informativeText)
{
    [UserNotificationHandler sendNotification:title.toNSString()
      informativeText:informativeText.toNSString()];
}
