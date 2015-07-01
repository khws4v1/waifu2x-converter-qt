#ifndef WAIFU2XCONVERTERCPPOPTIONS_H
#define WAIFU2XCONVERTERCPPOPTIONS_H

#include <QList>

namespace Waifu2xConverterQt {
enum Option {
    Jobs,
    ModelDir,
    ScaleRatio,
    NoiseLevel,
    Mode,
    OutputFile,
    InputFile,
};

QString optionToString(const Option opt);
QList<Option> optionList();
}

#endif // WAIFU2XCONVERTERCPPOPTIONS_H
