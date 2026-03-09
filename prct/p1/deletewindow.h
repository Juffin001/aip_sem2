#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    void setGallery(GalleryDatabase* G);
    ~DeleteWindow();
    void delete_painting(QString s);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteWindow *ui;
    GalleryDatabase *gb;

};

#endif // DELETEWINDOW_H
