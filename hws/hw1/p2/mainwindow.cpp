#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow() {
    this->setWindowTitle("Вращение объектов");
    QVBoxLayout *layout = new QVBoxLayout(this);
    area = new Area( this );
    btn = new QPushButton("Завершить",this );
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
}
