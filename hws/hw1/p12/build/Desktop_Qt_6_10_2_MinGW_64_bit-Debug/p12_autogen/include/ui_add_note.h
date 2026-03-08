/********************************************************************************
** Form generated from reading UI file 'add_note.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_NOTE_H
#define UI_ADD_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Add_note
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Add_note)
    {
        if (Add_note->objectName().isEmpty())
            Add_note->setObjectName("Add_note");
        Add_note->resize(334, 282);
        verticalLayout = new QVBoxLayout(Add_note);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Add_note);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(Add_note);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(Add_note);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEdit_2 = new QLineEdit(Add_note);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(Add_note);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit_3 = new QLineEdit(Add_note);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(Add_note);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_4 = new QLineEdit(Add_note);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton = new QPushButton(Add_note);
        pushButton->setObjectName("pushButton");

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(Add_note);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_5->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Add_note);
        QObject::connect(pushButton_2, &QPushButton::clicked, Add_note, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Add_note);
    } // setupUi

    void retranslateUi(QDialog *Add_note)
    {
        Add_note->setWindowTitle(QCoreApplication::translate("Add_note", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Add_note", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("Add_note", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("Add_note", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("Add_note", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Add_note", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Add_note", "\320\232\320\276\320\275\320\265\321\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_note: public Ui_Add_note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_NOTE_H
