#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "add_note.h"
#include "contact.h"
#include "QVector"
#include "seach_note.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    bd_contacts()
{
    ui->setupUi(this);
    Contact a{"Магдеев", "Ильяз", "+789239", "Саратов"}, b{"Кожакин", "Михаил", "+923431", "ывфа"}, c{"Магдеев", "Андрей", "938274", "Тула"};
    bd_contacts.push_back(a);
    bd_contacts.push_back(b);
    bd_contacts.push_back(c);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    Add_note dlg(this);
    dlg.exec();
}
void MainWindow::add_note_void(Contact c) {
    bd_contacts.push_back(c);
}
int MainWindow::get_len_bd() {
    return bd_contacts.length();
}
Contact MainWindow::get_el(int ind) {
    return bd_contacts[ind];
}
void MainWindow::on_pushButton_2_clicked()
{
    seach_note dlg(this);
    dlg.exec();
}

void MainWindow::del_el(int ind) {
    bd_contacts.removeAt(ind);
}
