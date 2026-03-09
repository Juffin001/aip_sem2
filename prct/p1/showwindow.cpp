#include "showwindow.h"
#include "ui_showwindow.h"
#include <QVariant>

ShowWindow::ShowWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowWindow)
{
    ui->setupUi(this);
}

ShowWindow::~ShowWindow()
{
    delete ui;
}

void ShowWindow::on_pushButton_clicked()
{
    close();
}

void ShowWindow::showVector(std::vector<std::string> v) {
    QString ans;
    for (int i = 0; i < v.size(); ++i) {
        ans += v[i];
        ans += "\n";
    }
    ui->textEdit->setText(ans);
}

void ShowWindow::showPainting(std::vector<Painting> v) {
    QString ans;
    for (int i = 0; i < v.size(); ++i) {
        ans += v[i].title + " ";
        ans += v[i].artist + " ";
        ans += QString::number(v[i].year) + " ";
        ans += v[i].location + " ";
        ans += "\n";
    }
    ui->textEdit->setText(ans);
}
