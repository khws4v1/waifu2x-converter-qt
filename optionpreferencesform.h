#ifndef OPTIONPREFERENCESFORM_H
#define OPTIONPREFERENCESFORM_H

#include <QWidget>
#include "waifu2xconvertercppoptions.h"

namespace Ui {
class OptionPreferencesForm;
}

class OptionPreferencesForm : public QWidget
{
    Q_OBJECT

public:
    explicit OptionPreferencesForm(const Waifu2xConverterQt::Option opt, QWidget *parent = nullptr);
    ~OptionPreferencesForm();

    Waifu2xConverterQt::Option option() const;
    bool isCheckedIgnoreBox() const;
    QString optionStringLineText() const;
    QString optionArgumentLineText() const;

public slots:
    void setIgnoreBoxChecked(bool checked);
    void setOptionStringLineText(const QString& string);
    void setOptionArgumentLineText(const QString& argument);

private:
    Ui::OptionPreferencesForm *ui;
    Waifu2xConverterQt::Option m_option;
};

#endif // OPTIONPREFERENCESFORM_H
