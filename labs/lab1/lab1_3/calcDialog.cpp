#include <QVector>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <cmath>
#include "calcDialog.h"

#define DIV  10
#define MUL  11
#define MINUS 12
#define PLUS  13
#define INVERSE 15
#define DOT   16
#define EQ    20
#define BKSP  30
#define CLR   31
#define CLR_ALL 32
#define SIN   50
#define COS   51
#define POW   52
#define LOG   53
#define GRID_KEYS 16

struct BtnDescr {
    QString text;
    int id;
    BtnDescr() : id(0) {}
    BtnDescr(const QString &str, int i) : text(str), id(i) {}
};

QVector<BtnDescr> _btnDescr;

void InitBtnDescrArray()
{
    _btnDescr.clear();
    _btnDescr.push_back(BtnDescr("7", 7));
    _btnDescr.push_back(BtnDescr("8", 8));
    _btnDescr.push_back(BtnDescr("9", 9));
    _btnDescr.push_back(BtnDescr("/", DIV));
    _btnDescr.push_back(BtnDescr("4", 4));
    _btnDescr.push_back(BtnDescr("5", 5));
    _btnDescr.push_back(BtnDescr("6", 6));
    _btnDescr.push_back(BtnDescr("*", MUL));
    _btnDescr.push_back(BtnDescr("1", 1));
    _btnDescr.push_back(BtnDescr("2", 2));
    _btnDescr.push_back(BtnDescr("3", 3));
    _btnDescr.push_back(BtnDescr("-", MINUS));
    _btnDescr.push_back(BtnDescr("0", 0));
    _btnDescr.push_back(BtnDescr("-/+", INVERSE));
    _btnDescr.push_back(BtnDescr(".", DOT));
    _btnDescr.push_back(BtnDescr("+", PLUS));
    _btnDescr.push_back(BtnDescr("<-", BKSP));
    _btnDescr.push_back(BtnDescr("CE", CLR));
    _btnDescr.push_back(BtnDescr("C", CLR_ALL));
    _btnDescr.push_back(BtnDescr("=", EQ));
    _btnDescr.push_back(BtnDescr("sin", SIN));
    _btnDescr.push_back(BtnDescr("cos", COS));
    _btnDescr.push_back(BtnDescr("x^y", POW));
    _btnDescr.push_back(BtnDescr("log_y(x)", LOG));
}
CalcDialog::CalcDialog(QWidget *parent)
    : QDialog(parent)
{
    initNum();
    InitBtnDescrArray();

    m_pLineEdit = new QLineEdit(this);
    m_pLineEdit->setReadOnly(true);
    m_pLineEdit->setAlignment(Qt::AlignRight);
    QGridLayout *gridLayout = new QGridLayout();
    QHBoxLayout *bccKeysLayout = new QHBoxLayout();
    QHBoxLayout *mainKeysLayout = new QHBoxLayout();
    QVBoxLayout *leftButtonsLayout = new QVBoxLayout();
    QVBoxLayout *dlgLayout = new QVBoxLayout();
    QPushButton *eqButton = nullptr;
    for (int i = 0; i < _btnDescr.size(); ++i) {
        QPushButton *button = new QPushButton(_btnDescr[i].text, this);
        if (_btnDescr[i].id < 10 || _btnDescr[i].id >= DIV) {
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        }
        if (_btnDescr[i].id >= 10) {
            QFont fnt = button->font();
            fnt.setPointSize(fnt.pointSize() + 4);
            button->setFont(fnt);
        }
        connect(button, &QPushButton::clicked, this, [this, id = _btnDescr[i].id]() {
            clicked(id);
        });
        int id = _btnDescr[i].id;
        if (id == SIN || id == COS || id == POW || id == LOG) {
            leftButtonsLayout->addWidget(button);
        }
        else if (i < GRID_KEYS) {
            int row = i / 4;
            int col = i % 4;
            gridLayout->addWidget(button, row, col);
        }
        else if (i < GRID_KEYS + 3) {
            bccKeysLayout->addWidget(button);
        }
        else if (id == EQ) {
            eqButton = button;
        }
    }
    mainKeysLayout->addLayout(leftButtonsLayout);
    mainKeysLayout->addLayout(gridLayout);
    if (eqButton) {
        mainKeysLayout->addWidget(eqButton);
    }
    dlgLayout->addWidget(m_pLineEdit);
    dlgLayout->addLayout(bccKeysLayout);
    dlgLayout->addLayout(mainKeysLayout);
    setLayout(dlgLayout);
    setNumEdit(0.0);
}
void CalcDialog::clicked(int id)
{
    switch (id) {
    case INVERSE: {
        setNumEdit(-getNumEdit());
        break;
    }
    case DOT: {
        checkOpPerf();
        QString str = m_pLineEdit->text();
        if (!str.contains('.')) {
            str.append('.');
            bool ok;
            str.toDouble(&ok);
            if (ok) m_pLineEdit->setText(str);
        }
        break;
    }
    case SIN:
    case COS: {
        double val = getNumEdit();
        double res = (id == SIN) ? sin(val) : cos(val);
        setNumEdit(res);
        m_bPerf = true;
        break;
    }
    case DIV:
    case MUL:
    case PLUS:
    case MINUS:
    case POW:
    case LOG:
    case EQ: {
        calcPrevOp(id);
        break;
    }
    case CLR_ALL:
        initNum();
        [[fallthrough]];
    case CLR: {
        setNumEdit(0.0);
        break;
    }
    case BKSP: {
        checkOpPerf();
        QString str = m_pLineEdit->text();
        if (!str.isEmpty()) {
            str.chop(1);
            m_pLineEdit->setText(str);
        }
        break;
    }
    default: {
        checkOpPerf();
        QString str = m_pLineEdit->text();
        if (str == "0") {
            str = QString::number(id);
        } else {
            str += QString::number(id);
        }
        m_pLineEdit->setText(str);
        break;
    }
    }
}
double CalcDialog::getNumEdit()
{
    return m_pLineEdit->text().toDouble();
}
void CalcDialog::setNumEdit(double num)
{
    QString str;
    str.setNum(num, 'g', 12);
    m_pLineEdit->setText(str);
}
void CalcDialog::calcPrevOp(int curOp)
{
    double num = getNumEdit();
    switch (m_Op) {
    case DIV:
        if (num != 0.0)
            m_Val /= num;
        else
            m_Val = 0.0;
        break;
    case MUL:
        m_Val *= num;
        break;
    case PLUS:
        m_Val += num;
        break;
    case MINUS:
        m_Val -= num;
        break;
    case POW:
        m_Val = std::pow(m_Val, num);
        break;
    case LOG:
        if (m_Val > 0 && m_Val != 1 && num > 0) {
            m_Val = std::log(num) / std::log(m_Val);
        } else {
            m_Val = 0.0;
        }
        break;
    case EQ:
        m_Val = num;
        break;
    default:
        m_Val = num;
        break;
    }
    m_Op = curOp;
    setNumEdit(m_Val);
    m_bPerf = true;
}
void CalcDialog::checkOpPerf()
{
    if (m_bPerf) {
        m_pLineEdit->clear();
        m_bPerf = false;
    }
}
void CalcDialog::initNum()
{
    m_bPerf = false;
    m_Val = 0.0;
    m_Op = EQ;
}
