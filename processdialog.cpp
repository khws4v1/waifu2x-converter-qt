#include "processdialog.h"
#include "ui_processdialog.h"
#include "waifu2xconvertercppoptions.h"
#include <QDir>
#include <QtDebug>

#ifdef Q_OS_LINUX
#include "libnotifyhandler.h"
#endif
#ifdef Q_OS_MAC
#include "usernotificationwrapper.h"
#endif
using namespace Waifu2xConverterQt;

ProcessDialog::ProcessDialog(const QString& inputFileName,
                             int threads,
                             double scaleRatio,
                             int noiseReductionLevel,
                             const QString& imageProcessingMode,
                             const QString& outputFileName,
                             const QString &modelDirectory,
                             QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ProcessDialog),
    m_settings(new Waifu2xConverterQtSettings(this)),
    m_process(new QProcess(this)),
    m_inputFileName(inputFileName),
    m_threads(threads),
    m_scaleRatio(scaleRatio),
    m_noiseReductionLevel(noiseReductionLevel),
    m_imageProcessingMode(imageProcessingMode),
    m_outputFileName(outputFileName),
    m_modelDirectory(modelDirectory)
{
    ui->setupUi(this);
    init();
}

ProcessDialog::~ProcessDialog()
{
    if (m_process->state() == QProcess::Running) {
        m_process->kill();
        m_process->waitForFinished();
    }
    delete ui;
}

void ProcessDialog::onProcessFinished()
{
    if (m_process->exitStatus() == QProcess::NormalExit
            && m_process->exitCode() == 0) {
        ui->textLabel->setText(tr("Success!"));
        sendResultNotification(true);
    } else {
        ui->textLabel->setText(tr("An error occurred while converting image."));
        sendResultNotification(false);
    }
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(100);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void ProcessDialog::appendConsoleText(QString text)
{
    if (text.endsWith("\n")) text.chop(1);
    ui->consoleText->appendPlainText(text);
}

void ProcessDialog::sendResultNotification(bool isSuccessed)
{
    QString title;
    QString text;

    if (isSuccessed) {
        title = tr("Success!");
        text = tr("Image conversion was successful.");

#ifdef Q_OS_LINUX
    sendNotify(title.toUtf8().constData(),
               text.toUtf8().constData(),
               "image-x-generic");
#endif
#ifdef Q_OS_MAC
    UserNotificationWrapper::sendNotification(title, text);
#endif
    } else {
        title = tr("Error!");
        text = tr("An error occurred while converting image.");

#ifdef Q_OS_LINUX
        sendNotify(title.toUtf8().constData(),
                   text.toUtf8().constData(),
                   "dialog-error");
#endif
#ifdef Q_OS_MAC
        UserNotificationWrapper::sendNotification(title, text);
#endif
    }
}

void ProcessDialog::init()
{
    QDir dir(m_settings->waifu2xConverterCppCommand());
    QStringList args;

    dir.cdUp();

    if (!m_settings->isOptionIgnored(Jobs))
        args << m_settings->optionString(Jobs)
             << (m_settings->optionArgument(Jobs).isEmpty()
                 ? QString::number(m_threads)
                 : m_settings->optionArgument(Jobs));

    if (!m_settings->isOptionIgnored(ScaleRatio))
        args << m_settings->optionString(ScaleRatio)
             << (m_settings->optionArgument(ScaleRatio).isEmpty()
                 ? QString::number(m_scaleRatio)
                 : m_settings->optionArgument(ScaleRatio));

    if (!m_settings->isOptionIgnored(NoiseLevel))
        args << m_settings->optionString(NoiseLevel)
             << (m_settings->optionArgument(NoiseLevel).isEmpty()
                 ? QString::number(m_noiseReductionLevel)
                 : m_settings->optionArgument(NoiseLevel));

    if (!m_settings->isOptionIgnored(Mode))
        args << m_settings->optionString(Mode)
             << (m_settings->optionArgument(Mode).isEmpty()
                 ? m_imageProcessingMode
                 : m_settings->optionArgument(Mode));

    if (!m_settings->isOptionIgnored(InputFile))
        args << m_settings->optionString(InputFile)
             << (m_settings->optionArgument(InputFile).isEmpty()
                 ? m_inputFileName
                 : m_settings->optionArgument(InputFile));

    if (!m_settings->isOptionIgnored(OutputFile)
            && !m_outputFileName.isEmpty()
            && !m_settings->optionArgument(OutputFile).isEmpty())
        args << m_settings->optionString(OutputFile)
             << (m_settings->optionArgument(OutputFile).isEmpty()
                 ? m_outputFileName
                 : m_settings->optionArgument(OutputFile));

    if (!m_settings->isOptionIgnored(ModelDir)
            && !m_modelDirectory.isEmpty()
            && !m_settings->optionArgument(ModelDir).isEmpty())
        args << m_settings->optionString(ModelDir)
             << (m_settings->optionArgument(ModelDir).isEmpty()
                 ? m_modelDirectory
                 : m_settings->optionArgument(ModelDir));

    if (dir.exists())
        m_process->setWorkingDirectory(dir.absolutePath());
    m_process->start(m_settings->waifu2xConverterCppCommand(), args);

    ui->iconLabel->setPixmap(style()->standardPixmap(QStyle::SP_FileIcon));

    connect(m_process, &QProcess::readyReadStandardError, [&]() {
        QMetaObject::invokeMethod(this,
                                  "appendConsoleText",
                                  Q_ARG(QString,
                                        QString::fromUtf8(m_process->readAllStandardError())));
    });
    connect(m_process, &QProcess::readyReadStandardOutput, [&]() {
        QMetaObject::invokeMethod(this,
                                  "appendConsoleText",
                                  Q_ARG(QString,
                                        QString::fromUtf8(m_process->readAllStandardOutput())));
    });

    connect(m_process, SIGNAL(finished(int)), this, SLOT(onProcessFinished()));
}
