#ifndef WAIFU2XCONVERTERQTSETTINGS_H
#define WAIFU2XCONVERTERQTSETTINGS_H

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

    void setWaifu2xConverterCppCommand(const QString& command)
    {
        setValue("Waifu2xConverterCppCommand", command);
    }
    QString waifu2xConverterCppCommand() const
    {
        return value("Waifu2xConverterCppCommandn").toString();
    }

    void setThreadsCount(int count)
    {
        setValue("ThreadsCount", count);
    }
    int threadsCount() const
    {
        return value("ThreadsCount", 4).toInt();
    }

    void setScaleRatio(double ratio)
    {
        setValue("ScaleRatio", ratio);
    }
    double scaleRatio() const
    {
        return value("ScaleRatio", 2.0).toDouble();
    }

    void setNoiseReductionLevel(int level)
    {
        setValue("NoiseReductionLevel", level);
    }
    int noiseReductionLevel() const
    {
        return value("NoiseReductionLavel", 1).toInt();
    }

    void setImageProcessingMode(const QString& mode)
    {
        setValue("ImageProcessingMode", mode);
    }
    QString imageProcessingMode() const
    {
        return value("ImageProcessingMode", "noise_scale").toString();
    }

    void setUseCustomFileName(bool on)
    {
        setValue("UseCustomFileName", on);
    }
    bool isUseCustomFileName() const
    {
        return value("UseCustomFileName").toBool();
    }

    void setModelDirectory(const QString& dir)
    {
        setValue("ModelDirectory", dir);
    }
    QString modelDirectory() const
    {
        return value("ModelDirectory").toString();
    }
};

#endif // WAIFU2XCONVERTERQTSETTINGS_H
