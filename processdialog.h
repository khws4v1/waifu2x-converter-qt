#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>
#include <QProcess>
#include "waifu2xconverterqtsettings.h"

namespace Ui {
class ProcessDialog;
}

class ProcessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProcessDialog(const QString& inputFileName,
                           int threads,
                           double scaleRatio,
                           int noiseReductionLevel,
                           const QString& imageProcessingMode,
                           const QString& outputFileName,
                           const QString& modelDirectory,
                           QWidget *parent = nullptr);
    ~ProcessDialog();

private slots:
    void onProcessFinished();
    void appendConsoleText(QString text);

private:
    void init();

    Ui::ProcessDialog* ui;
    Waifu2xConverterQtSettings* m_settings;
    QProcess* m_process;
    QString m_inputFileName;
    int m_threads;
    double m_scaleRatio;
    int m_noiseReductionLevel;
    QString m_imageProcessingMode;
    QString m_outputFileName;
    QString m_modelDirectory;
};

#endif // PROCESSDIALOG_H
