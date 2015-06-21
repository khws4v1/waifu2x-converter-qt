#include "libnotifyhandler.h"
#include <libnotify/notify.h>

void sendNotify(const char *summary, const char *body, const char *icon)
{
    NotifyNotification *notification;

    if (!notify_is_initted())
        notify_init("waifu2x-converter-qt");

    notification = notify_notification_new(summary,
                                           body,
                                           icon);
    notify_notification_show(notification,
                             NULL);
}

