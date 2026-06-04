#include "add.h"
#include "ui_add.h"
#include <QTextEdit>

Add::Add(contain_both_queues *Q, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add), q(Q)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != "") {
        bool is_int;
        q->add(ui->lineEdit->text());
        close();
    }
}


void Add::on_pushButton_2_clicked()
{
    close();
}

