#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include "waifu2xconvertercppoptions.h"
#include "optionpreferencesform.h"
#include <QFileDialog>
#include <QMessageBox>

using namespace Waifu2xConverterQt;

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

    for (const auto& opt : optionList()) {
        auto* form = findChild<OptionPreferencesForm *>(QString("option%1Widget").arg(optionToString(opt)));

        Q_ASSERT(form);
        if (form) {
            m_settings->setOptionIgnored(opt, form->isCheckedIgnoreBox());
            m_settings->setOptionString(opt, form->optionStringLineText());
            m_settings->setOptionArgument(opt, form->optionArgumentLineText());
        }
    }
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

    for (const auto& opt : optionList())
        ui->optionWidget->addWidget(new OptionPreferencesForm(opt, this));

    loadSettings();
}

void PreferencesDialog::loadSettings()
{
    ui->waifu2xCommandLine->setText(m_settings->waifu2xConverterCppCommand());
    ui->modelDirectoryLine->setText(m_settings->modelDirectory());
    ui->outputFilenameCheck->setChecked(m_settings->isUseCustomFileName());

    for (const auto& opt : optionList()) {
        auto* form = findChild<OptionPreferencesForm *>(QString("option%1Widget").arg(optionToString(opt)));

        Q_ASSERT(form);
        if (form) {
            form->setIgnoreBoxChecked(m_settings->isOptionIgnored(opt));
            form->setOptionStringLineText(m_settings->optionString(opt));
            form->setOptionArgumentLineText(m_settings->optionAtgument(opt));
        }
    }
}
