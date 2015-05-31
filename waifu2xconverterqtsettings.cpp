#include "waifu2xconverterqtsettings.h"

#include <QApplication>

waifu2xConverterQtSettings::waifu2xConverterQtSettings(QObject *parent)
    : QSettings(QSettings::IniFormat,
                QSettings::UserScope,
                QApplication::organizationName(),
                QApplication::applicationName(),
                parent)
{

}

