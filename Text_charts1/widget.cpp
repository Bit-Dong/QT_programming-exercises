#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Chart_Init();
    /*定时器*/
    timerDrawLine = new QTimer();
    timerDrawLine->start(500);
    connect(timerDrawLine,&QTimer::timeout,[=](){
        DrawLine();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Chart_Init()
{
    //初始化QChart的实例
    chart = new QChart();
    //初始化QSplineSeries的实例
    lineSeries = new QSplineSeries();

    //lineSeries = new QLineSeries();

    //设置曲线的名称
    lineSeries->setName("随机数测试曲线");
    //把曲线添加到QChart的实例chart中
    chart->addSeries(lineSeries);
    //声明并初始化X轴、两个Y轴
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();
    //设置坐标轴显示的范围
    axisX->setMin(0);
    axisX->setMax(MAX_X);
    axisY->setMin(0);
    axisY->setMax(MAX_Y);
    //设置坐标轴上的格点
    axisX->setTickCount(11);
    axisY->setTickCount(11);
    //设置坐标轴显示的名称
    QFont font("Microsoft YaHei",8,QFont::Normal);//微软雅黑。字体大小8
    axisX->setTitleFont(font);
    axisY->setTitleFont(font);
    axisX->setTitleText("X-Test");
    axisY->setTitleText("Y-Test");
    //设置网格不显示
    axisY->setGridLineVisible(false);
    //下方：Qt::AlignBottom，左边：Qt::AlignLeft
    //右边：Qt::AlignRight，上方：Qt::AlignTop
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    //把曲线关联到坐标轴
    lineSeries->attachAxis(axisX);
    lineSeries->attachAxis(axisY);
    //把chart显示到窗口上
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);      // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
}
void Widget::DrawLine()
{
    static int count = 0;
    if(count > MAX_X)
    {
        //当曲线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries->removePoints(0,lineSeries->count() - MAX_X);
        // 更新X轴的范围
        chart->axisX()->setMin(count - MAX_X);
        chart->axisX()->setMax(count);
    }
    //增加新的点到曲线末端
    lineSeries->append(count, rand()%99);//随机生成0到65的随机数
    count ++;
}
