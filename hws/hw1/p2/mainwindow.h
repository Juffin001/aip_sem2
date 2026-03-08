#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "area.h"

class MainWindow : public QWidget {
protected:
    Area * area;
    QPushButton * btn;
public:
    MainWindow();
};

#endif
