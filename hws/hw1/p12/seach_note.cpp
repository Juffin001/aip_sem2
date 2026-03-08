#include "seach_note.h"
#include "ui_seach_note.h"

seach_note::seach_note(MainWindow *mainWin, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seach_note),
    ind_found(-1),
    m_mainWindow(mainWin)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
}

seach_note::~seach_note()
{
    delete ui;
}

void seach_note::on_pushButton_clicked()
{
    QString last_name_search = ui->lineEdit->text();
    for (int i = ind_found + 1; i < m_mainWindow->get_len_bd(); ++i) {
        if (m_mainWindow->get_el(i).lastName == last_name_search) {
            ui->lineEdit->setText(m_mainWindow->get_el(i).lastName);
            ui->lineEdit_2->setText(m_mainWindow->get_el(i).firstName);
            ui->lineEdit_3->setText(m_mainWindow->get_el(i).phone);
            ui->lineEdit_4->setText(m_mainWindow->get_el(i).address);
            ind_found = i;
            return;
        }
    }
    if (ind_found > -1) {
        for (int i = 0; i < ind_found; ++i) {
            if (m_mainWindow->get_el(i).lastName == last_name_search) {
                ui->lineEdit->setText(m_mainWindow->get_el(i).lastName);
                ui->lineEdit_2->setText(m_mainWindow->get_el(i).firstName);
                ui->lineEdit_3->setText(m_mainWindow->get_el(i).phone);
                ui->lineEdit_4->setText(m_mainWindow->get_el(i).address);
                ind_found = i;
                return;
            }
        }
    }
}


void seach_note::on_pushButton_2_clicked()
{
    if (ind_found != -1) {
        m_mainWindow->del_el(ind_found);
    }
    ind_found = -1;
}

