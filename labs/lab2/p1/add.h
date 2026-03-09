#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "queue.h"

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(Queue *Q, QWidget *parent = nullptr);
    ~Add();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add *ui;
    Queue *q;

};

#endif // ADD_H
