#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "waifu2xconverterqtsettings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void browseImage();
    void processImage(const QString& imageFileName);

private:
    void init();
    QString browseSaveLocation(const QString& inputImageFileName);
    void closeEvent(QCloseEvent*);
    void save();

    Ui::MainWindow *ui;
    Waifu2xConverterQtSettings* m_settings;
};

#endif // MAINWINDOW_H
