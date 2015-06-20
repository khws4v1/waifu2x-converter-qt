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

Waifu2xConverterQtSettings::ArgmentSettings Waifu2xConverterQtSettings::defaultArgmentSettings()
{
    ArgmentSettings s;

    s.jobs.argmentString = "-j";
    s.modelDirectory.argmentString = "--model_dir";
    s.scaleRatio.argmentString = "--scale_ratio";
    s.noiseLevel.argmentString = "--noise_level";
    s.mode.argmentString = "-m";
    s.outputFile.argmentString = "-o";
    s.inputFile.argmentString = "-i";

    return s;
}
