#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteWindow), gb()
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::setGallery(GalleryDatabase* G) {
    gb = G;
}

void DeleteWindow::delete_painting(QString s) {
    for (int i = 0; i < gb->paintings.size(); ++i) {
        if (gb->paintings[i].title == s) {
            gb->paintings.erase(gb->paintings.begin() + i);
            break;
        }
    }
}

void DeleteWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "") {
        delete_painting(ui->lineEdit->text());
        close();
    }
}

