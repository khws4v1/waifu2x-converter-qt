#ifndef LIBNOTIFYHANDLER_H
#define LIBNOTIFYHANDLER_H

#ifdef __cplusplus
extern "C" {
#endif
void sendNotify(const char *summary,
                const char *body,
                const char *icon);
#ifdef __cplusplus
}
#endif

#endif // LIBNOTIFYHANDLER_H
