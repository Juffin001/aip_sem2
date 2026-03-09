#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "painting.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();
    void setgallery(GalleryDatabase *G);
    void add();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddWindow *ui;
    GalleryDatabase *gb;
};

#endif // ADDWINDOW_H
