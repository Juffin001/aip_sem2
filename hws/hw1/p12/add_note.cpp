#include "add_note.h"
#include "ui_add_note.h"

Add_note::Add_note(MainWindow *mainWin, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_note),
    m_mainWindow(mainWin)
{
    ui->setupUi(this);
}

Add_note::~Add_note()
{
    delete ui;
}
//Добавить запись
void Add_note::on_pushButton_clicked()
{
    Contact c;
    c.lastName = ui->lineEdit->text();
    c.firstName = ui->lineEdit_2->text();
    c.phone = ui->lineEdit_3->text();
    c.address = ui->lineEdit_4->text();
    m_mainWindow->add_note_void(c);
}

