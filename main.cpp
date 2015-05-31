#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (QLocale::system().language() == QLocale::Japanese) {
        auto* translator = new QTranslator();

        qDebug() << translator->load("waifu2x-converter-qt_ja",
                                    a.applicationDirPath());
        //translator.load("qt_ja", "i18n");
        a.installTranslator(translator);
    }


    MainWindow w;
    w.show();

    return a.exec();
}
