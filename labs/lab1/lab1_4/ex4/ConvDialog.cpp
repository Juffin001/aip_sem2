#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "mainwindow.h"

ConvDialog::ConvDialog(QWidget *parent)
    : QDialog(parent) {
    input_LineEdit = new QLineEdit(this);
    input_LineEdit->setReadOnly(false);
    output_TextEdit = new QTextEdit(this);
    output_TextEdit->setReadOnly(true);
    QPushButton *conv_button = new QPushButton("Convert", this);
    connect(conv_button, &QPushButton::clicked, this, &ConvDialog::clicked);

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->addWidget(input_LineEdit);
    mainlayout->addWidget(conv_button);
    mainlayout->addWidget(output_TextEdit);
    setLayout(mainlayout);
}
void ConvDialog::clicked() {
    QString txt = input_LineEdit->text();
    QString base_text = "input: " + txt;
    QString lower_text = "all lower: " + txt.toLower();
    QString upper_text = "ALL UPPER: " + txt.toUpper();
    QString final_text = base_text + "\n" + lower_text + "\n" + upper_text;
    output_TextEdit->setText(final_text);
}
