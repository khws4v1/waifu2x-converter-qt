#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include "waifu2xconverterqtsettings.h"

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();

private slots:
    void saveSettings();
    void browseWaifu2xConverterCpp();

private:
    void init();

    Ui::PreferencesDialog *ui;
    Waifu2xConverterQtSettings* m_settings;
};

#endif // PREFERENCESDIALOG_H
