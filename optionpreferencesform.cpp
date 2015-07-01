#include "optionpreferencesform.h"
#include "ui_optionpreferencesform.h"

using namespace Waifu2xConverterQt;

OptionPreferencesForm::OptionPreferencesForm(const Option opt, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionPreferencesForm)
{
    ui->setupUi(this);

    setObjectName(QString("option%1Widget").arg(optionToString(opt)));
}

OptionPreferencesForm::~OptionPreferencesForm()
{
    delete ui;
}

Option OptionPreferencesForm::option() const
{
    return m_option;
}

bool OptionPreferencesForm::isCheckedIgnoreBox() const
{
    return ui->ignoreBox->isChecked();
}

QString OptionPreferencesForm::optionStringLineText() const
{
    return ui->stringLine->text();
}

QString OptionPreferencesForm::optionArgumentLineText() const
{
    return ui->argumentLine->text();
}

void OptionPreferencesForm::setIgnoreBoxChecked(bool checked)
{
    ui->ignoreBox->setChecked(checked);
}

void OptionPreferencesForm::setOptionStringLineText(const QString &string)
{
    ui->stringLine->setText(string);
}

void OptionPreferencesForm::setOptionArgumentLineText(const QString &argument)
{
    ui->argumentLine->setText(argument);
}
