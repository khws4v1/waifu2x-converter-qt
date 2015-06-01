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
    m_settings->setWaifu2xConverterCppLocation(ui->locationLine->text());
    m_settings->setUseCustomFileName(ui->outputFilenameCheck->isChecked());
}

void PreferencesDialog::browseWaifu2xConverterCpp()
{
    QFileDialog dialog(this, tr("Select waifu2x-converter-cpp location"));

    dialog.selectFile("waifu2x-converter-cpp");
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if (dialog.exec() == QFileDialog::Accepted)
        ui->locationLine->setText(dialog.selectedFiles().first());
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
    connect(ui->restoreButton, SIGNAL(clicked(bool)), this, SLOT(restoreDefaults()));

    loadSettings();
}

void PreferencesDialog::loadSettings()
{
    ui->locationLine->setText(m_settings->waifu2xConverterCppLocation());
    ui->outputFilenameCheck->setChecked(m_settings->isUseCustomFileName());
}
