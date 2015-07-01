#include "waifu2xconvertercppoptions.h"
#include <QString>

namespace Waifu2xConverterQt {
QString optionToString(const Option opt)
{
    switch (opt) {
    case Jobs:       return "Jobs";
    case ModelDir:   return "ModelDir";
    case ScaleRatio: return "ScaleRatio";
    case NoiseLevel: return "NoiseLevel";
    case Mode:       return "Mode";
    case OutputFile: return "OutputFile";
    case InputFile:  return "InputFile";
    default: return QString();
    }
}

QList<Option> optionList()
{
    return {Jobs, ModelDir, ScaleRatio, NoiseLevel, Mode, OutputFile, InputFile};
}
}
