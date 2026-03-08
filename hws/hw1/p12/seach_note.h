#ifndef SEACH_NOTE_H
#define SEACH_NOTE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class seach_note;
}

class seach_note : public QDialog
{
    Q_OBJECT

public:
    explicit seach_note(MainWindow *mainWin, QWidget *parent = nullptr);
    ~seach_note();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::seach_note *ui;
    MainWindow *m_mainWindow;
    int ind_found;
};

#endif // SEACH_NOTE_H
