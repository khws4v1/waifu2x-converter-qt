#ifndef WAIFU2XCONVERTERQTSETTINGS_H
#define WAIFU2XCONVERTERQTSETTINGS_H

#include "waifu2xconvertercppoptions.h"
#include <QSettings>
#include <QApplication>
#include <QDir>

class Waifu2xConverterQtSettings : public QSettings
{
public:
    Waifu2xConverterQtSettings(QObject* parent = nullptr);

    inline void restoreDefaults()
    {
        for (const QString& key : allKeys()) remove(key);
    }

    inline void setWaifu2xConverterCppCommand(const QString& command)
    {
        setValue("Waifu2xConverterCppCommand", command);
    }
    inline QString waifu2xConverterCppCommand() const
    {
        return value("Waifu2xConverterCppCommand").toString();
    }

    inline void setThreadsCount(int count)
    {
        setValue("ThreadsCount", count);
    }
    inline int threadsCount() const
    {
        return value("ThreadsCount", 4).toInt();
    }

    inline void setScaleRatio(double ratio)
    {
        setValue("ScaleRatio", ratio);
    }
    inline double scaleRatio() const
    {
        return value("ScaleRatio", 2.0).toDouble();
    }

    inline void setNoiseReductionLevel(int level)
    {
        setValue("NoiseReductionLevel", level);
    }
    inline int noiseReductionLevel() const
    {
        return value("NoiseReductionLavel", 1).toInt();
    }

    inline void setImageProcessingMode(const QString& mode)
    {
        setValue("ImageProcessingMode", mode);
    }
    inline QString imageProcessingMode() const
    {
        return value("ImageProcessingMode", "noise_scale").toString();
    }

    inline void setUseCustomFileName(bool on)
    {
        setValue("UseCustomFileName", on);
    }
    inline bool isUseCustomFileName() const
    {
        return value("UseCustomFileName").toBool();
    }

    inline void setModelDirectory(const QString& dir)
    {
        setValue("ModelDirectory", dir);
    }
    inline QString modelDirectory() const
    {
        return value("ModelDirectory").toString();
    }

    inline void setOptionIgnored(const Waifu2xConverterQt::Option opt, const bool isIgnore)
    {
        setValue(QString("Ignore%1").arg(Waifu2xConverterQt::optionToString(opt)), isIgnore);
    }
    inline bool isOptionIgnored(const Waifu2xConverterQt::Option opt) const
    {
        return value(QString("Ignore%1").arg(Waifu2xConverterQt::optionToString(opt)), false).toBool();
    }

    inline void setOptionString(const Waifu2xConverterQt::Option opt, const QString& string)
    {
        setValue(QString("%1String").arg(Waifu2xConverterQt::optionToString(opt)), string);
    }
    inline QString optionString(const Waifu2xConverterQt::Option opt) const
    {
        return value(QString("%1String").arg(Waifu2xConverterQt::optionToString(opt))).toString().isEmpty()
                ? defaultOptionString(opt)
                : value(QString("%1String").arg(Waifu2xConverterQt::optionToString(opt))).toString();
    }

    inline void setOptionArgument(const Waifu2xConverterQt::Option opt, const QString& arg)
    {
        setValue(QString("%1Argument").arg(Waifu2xConverterQt::optionToString(opt)), arg);
    }
    inline QString optionArgument(const Waifu2xConverterQt::Option opt)
    {
        return value(QString("%1Argument").arg(Waifu2xConverterQt::optionToString(opt)), "").toString();
    }

    static QString defaultOptionString(const Waifu2xConverterQt::Option opt);
};

#endif // WAIFU2XCONVERTERQTSETTINGS_H
