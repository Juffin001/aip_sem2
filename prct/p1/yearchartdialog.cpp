#include "yearchartdialog.h"
#include <QtCharts>
#include <QVBoxLayout>

YearChartDialog::YearChartDialog(const std::map<int, int>& data, const QString& artistName, QWidget *parent)
    : QDialog(parent)
{
    setupChart(data, artistName);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
    setWindowTitle("График количества полотен по годам");
    resize(800, 600);
}

void YearChartDialog::setupChart(const std::map<int, int>& data, const QString& artistName)
{
    QBarSet *set = new QBarSet("Количество картин");
    QStringList categories;

    for (const auto& pair : data) {
        *set << pair.second;
        categories << QString::number(pair.first);
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Количество полотен художника %1 по годам").arg(artistName));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Год");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    axisY->setTitleText("Количество");
    axisY->setTickCount(6);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
