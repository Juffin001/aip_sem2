#ifndef YEARCHARTDIALOG_H
#define YEARCHARTDIALOG_H

#include <QDialog>
#include <map>

class QChartView;

class YearChartDialog : public QDialog
{
    Q_OBJECT
public:
    explicit YearChartDialog(const std::map<int, int>& data, const QString& artistName, QWidget *parent = nullptr);
private:
    void setupChart(const std::map<int, int>& data, const QString& artistName);
    QChartView *chartView;
};

#endif // YEARCHARTDIALOG_H
