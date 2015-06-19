#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include <QFileDialog>
#include <QMessageBox>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog),
    m_settings(new Waifu2xConverterQtSettings(this))
{
    ui->setupUi(this);
    init();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::saveSettings()
{
    m_settings->setWaifu2xConverterCppCommand(ui->waifu2xCommandLine->text());
    m_settings->setModelDirectory(ui->modelDirectoryLine->text());
    m_settings->setUseCustomFileName(ui->outputFilenameCheck->isChecked());
}

void PreferencesDialog::browseWaifu2xConverterCpp()
{
    QFileDialog dialog(this, tr("Select waifu2x-converter"));

    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if (dialog.exec() == QFileDialog::Accepted)
        ui->waifu2xCommandLine->setText(dialog.selectedFiles().first());
}

void PreferencesDialog::browseModelDirectory()
{
    QFileDialog dialog(this, tr("Select model directory"));

    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::DirectoryOnly);

    if (dialog.exec() == QFileDialog::Accepted)
        ui->modelDirectoryLine->setText(dialog.selectedFiles().first());
}

void PreferencesDialog::restoreDefaults()
{
    m_settings->restoreDefaults();
    loadSettings();
    QMessageBox::information(this,
                             "",
                             tr("Done."),
                             QMessageBox::Ok);
}

void PreferencesDialog::init()
{
    connect(this, SIGNAL(accepted()), this, SLOT(saveSettings()));
    connect(ui->browseButton, SIGNAL(clicked(bool)), this, SLOT(browseWaifu2xConverterCpp()));
    connect(ui->browseModelDirectoryButton, SIGNAL(clicked(bool)), this, SLOT(browseModelDirectory()));
    connect(ui->restoreButton, SIGNAL(clicked(bool)), this, SLOT(restoreDefaults()));

    loadSettings();
}

void PreferencesDialog::loadSettings()
{
    ui->waifu2xCommandLine->setText(m_settings->waifu2xConverterCppCommand());
    ui->modelDirectoryLine->setText(m_settings->modelDirectory());
    ui->outputFilenameCheck->setChecked(m_settings->isUseCustomFileName());
}
