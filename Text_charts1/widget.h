#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QValueAxis>
#include <QTimer>
#include <QChart>

QT_CHARTS_USE_NAMESPACE
#define MAX_X   10
#define MAX_Y   100

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *timerDrawLine;
    QChart *chart;
    QSplineSeries *lineSeries;
   // QLineSeries *lineSeries;

    void Chart_Init();
    void DrawLine();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
