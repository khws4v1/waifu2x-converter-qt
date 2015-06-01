#include "waifu2xconverterqtsettings.h"

#include <QApplication>

Waifu2xConverterQtSettings::Waifu2xConverterQtSettings(QObject *parent)
    : QSettings(QSettings::IniFormat,
                QSettings::UserScope,
                QApplication::organizationName(),
                QApplication::applicationName(),
                parent)
{

}
