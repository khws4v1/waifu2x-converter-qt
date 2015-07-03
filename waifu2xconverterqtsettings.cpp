#include "waifu2xconverterqtsettings.h"
#include <QApplication>

using namespace Waifu2xConverterQt;

Waifu2xConverterQtSettings::Waifu2xConverterQtSettings(QObject *parent)
    : QSettings(QSettings::IniFormat,
                QSettings::UserScope,
                QApplication::organizationName(),
                QApplication::applicationName(),
                parent)
{

}

QString Waifu2xConverterQtSettings::defaultOptionString(const Option opt)
{
    switch (opt) {
    case Jobs:       return "-j";
    case ModelDir:   return "--model_dir";
    case ScaleRatio: return "--scale_ratio";
    case NoiseLevel: return "--noise_level";
    case Mode:       return "-m";
    case OutputFile: return "-o";
    case InputFile:  return "-i";
    default:         return QString();
    }
}
