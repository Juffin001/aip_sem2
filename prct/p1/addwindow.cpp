#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddWindow), gb()
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::setgallery(GalleryDatabase *G) {
    gb = G;
}

void AddWindow::add() {
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_4->text() != "") {
        Painting new_painting = {ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toStdString()};
        gb->paintings.push_back(new_painting);
    }
}

void AddWindow::on_pushButton_clicked()
{
    add();
    close();
}

