#ifndef USERNOTIFICATIONWRAPPER_H
#define USERNOTIFICATIONWRAPPER_H

class QString;

class UserNotificationWrapper
{
public:
    static void sendNotification(const QString& title,
                                 const QString& informativeText);
};

#endif // USERNOTIFICATIONWRAPPER_H
