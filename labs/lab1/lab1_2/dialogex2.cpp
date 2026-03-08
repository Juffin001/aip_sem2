#include <QOverload>
#include "dialogex2.h"
#include <QMessageBox>

DialogEx2::DialogEx2(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [=](int val) {
                textEdit->append(QString::number(val));
            });
    connect(pushButton, SIGNAL(clicked()), this, SLOT(onExitClicked()));
}

void DialogEx2::onExitClicked()
{
    if (QMessageBox::question(this, QString(), "Завершить приложение?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        exit(0);
    else
        show();
}
