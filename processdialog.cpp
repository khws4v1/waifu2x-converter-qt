#include "processdialog.h"
#include "ui_processdialog.h"
#include <QDir>
#include <QtDebug>

ProcessDialog::ProcessDialog(const QString& inputFileName,
                             int threads,
                             double scaleRatio,
                             int noiseReductionLevel,
                             const QString& imageProcessingMode,
                             const QString& outputFileName,
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
    m_outputFileName(outputFileName)
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
    if (m_process->exitStatus() == QProcess::NormalExit)
        ui->textLabel->setText(tr("Success!"));
    else
        ui->textLabel->setText(tr("An error occurred while converting image."));
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(100);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Close);
}

void ProcessDialog::appendConsoleText(QString text)
{
    if (text.endsWith("\n")) text.chop(1);
    ui->consoleText->appendPlainText(text);
}

void ProcessDialog::init()
{
    QDir dir(m_settings->waifu2xConverterCppCommand());
    QStringList args;

    dir.cdUp();

    args << "-j" << QString::number(m_threads);
    if (m_imageProcessingMode.contains("scale"))
        args << "--scale_ratio" << QString::number(m_scaleRatio);
    if (m_imageProcessingMode.contains("noise"))
        args << "--noise_level" << QString::number(m_noiseReductionLevel);
    args << "-m" << m_imageProcessingMode;
    args << "-i" << m_inputFileName;
    if (!m_outputFileName.isEmpty())
        args << QString("-o %1").arg(m_outputFileName);
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
