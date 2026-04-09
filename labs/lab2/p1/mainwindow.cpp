#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), q()
{
    ui->setupUi(this);
    q.print(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // del
{
    try {
        q.delete_last();
        q.print(ui->textEdit);
    } catch (const QueueEmptyException& e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}


void MainWindow::on_pushButton_2_clicked() // add
{
    Add add_win(&q);
    add_win.exec();
    q.print(ui->textEdit);
}


void MainWindow::on_pushButton_3_clicked() // sort
{
    try {
        q.sort_queue();
        q.print(ui->textEdit);
    } catch (const NoWordsException& e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

