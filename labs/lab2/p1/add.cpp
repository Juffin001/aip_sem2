#include "add.h"
#include "ui_add.h"
#include <QTextEdit>

Add::Add(Queue *Q, QWidget *parent)
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
        ui->lineEdit->text().toInt(&is_int);
        if (is_int) {
            Num *el = new Num(ui->lineEdit->text());
            q->add(el);
        }
        else {
            Str *el = new Str(ui->lineEdit->text());
            q->add(el);
        }
        close();
    }
}


void Add::on_pushButton_2_clicked()
{
    close();
}

