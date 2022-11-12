#ifndef LINESERIES_H
#define LINESERIES_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QTimer>
//#include <QChart>

QT_CHARTS_USE_NAMESPACE
#define MAX_X   10
#define MAX_Y   100

namespace Ui {
class lineseries;
}

class lineseries : public QWidget
{
    Q_OBJECT

public:
    explicit lineseries(QWidget *parent = nullptr);
    ~lineseries();

    QTimer *timerDrawLine;
    QTimer *timerDrawLine1;
    QChart *chart;
    QChart *chart1;
    QSplineSeries *lineSeries;
    QLineSeries *lineSeries1;

    void Chart_Init();
    void DrawLine();

    void Chart_Init1();
    void DrawLine1();


private:
    Ui::lineseries *ui;
};

#endif // LINESERIES_H
