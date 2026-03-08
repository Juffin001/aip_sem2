#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextEdit>

class ConvDialog : public QDialog {
    Q_OBJECT
public:
    ConvDialog(QWidget *parent = nullptr);
    virtual ~ConvDialog() {}
protected:
    QLineEdit *input_LineEdit;
    QTextEdit *output_TextEdit;
    QPushButton *conv_button;
private slots:
    void clicked();
};

#endif
