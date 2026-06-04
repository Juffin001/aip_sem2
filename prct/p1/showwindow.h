#ifndef SHOWWINDOW_H
#define SHOWWINDOW_H

#include <QDialog>
#include "painting.h"

namespace Ui {
class ShowWindow;
}

class ShowWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowWindow(QWidget *parent = nullptr);
    ~ShowWindow();
    void showVector(std::vector<std::string> v);
    void showPainting(std::vector<Painting> v);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowWindow *ui;
};

#endif // SHOWWINDOW_H
