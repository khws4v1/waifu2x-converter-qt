#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (QLocale::system().language() == QLocale::Japanese) {
        auto* qtTranslator = new QTranslator(&a);
        auto* waifu2xConverterQtTranslator = new QTranslator(&a);

        qtTranslator->load("qt_ja", a.applicationDirPath());
        waifu2xConverterQtTranslator->load("waifu2x-converter-qt_ja",
                                           a.applicationDirPath());
        a.installTranslator(qtTranslator);
        a.installTranslator(waifu2xConverterQtTranslator);
    }


    MainWindow w;
    w.show();

    return a.exec();
}
