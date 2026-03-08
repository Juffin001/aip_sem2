#ifndef _CALC_DIALOG_H_
#define _CALC_DIALOG_H_

#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>

class CalcDialog : public QDialog
{
    Q_OBJECT
public:
    CalcDialog(QWidget *parent = nullptr);
    virtual ~CalcDialog() {}

protected:
    QSignalMapper *m_pSignalMapper;
    QLineEdit *m_pLineEdit;
    double m_Val;
    int m_Op;
    bool m_bPerf;

    void initNum();
    double getNumEdit();
    void setNumEdit(double num);
    void calcPrevOp(int curOp);
    void checkOpPerf();

private slots:
    void clicked(int id);
};

#endif
