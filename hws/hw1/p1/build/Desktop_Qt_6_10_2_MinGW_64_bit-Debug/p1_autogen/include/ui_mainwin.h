/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName("MainWin");
        MainWin->resize(217, 230);
        verticalLayout = new QVBoxLayout(MainWin);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(MainWin);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(MainWin);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MainWin);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_3 = new QPushButton(MainWin);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(MainWin);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_5 = new QPushButton(MainWin);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(MainWin);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_3->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_7 = new QPushButton(MainWin);
        pushButton_7->setObjectName("pushButton_7");

        verticalLayout->addWidget(pushButton_7);


        retranslateUi(MainWin);
        QObject::connect(pushButton_7, &QPushButton::clicked, MainWin, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QWidget *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWin", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWin", "\320\241", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWin", "=", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWin", "+", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWin", "*", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWin", "-", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWin", "/", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWin", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
