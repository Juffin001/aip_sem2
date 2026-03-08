#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ConvDialog w;
    w.show();
    return app.exec();
}
