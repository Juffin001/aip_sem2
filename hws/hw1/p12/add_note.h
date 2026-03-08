#ifndef ADD_NOTE_H
#define ADD_NOTE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Add_note;
}

class Add_note : public QDialog
{
    Q_OBJECT

public:
    explicit Add_note(MainWindow *mainWin, QWidget *parent = nullptr);
    ~Add_note();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_note *ui;
    MainWindow *m_mainWindow;
};

#endif // ADD_NOTE_H
