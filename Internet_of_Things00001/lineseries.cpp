#include "lineseries.h"
#include "ui_lineseries.h"

lineseries::lineseries(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lineseries)
{
    ui->setupUi(this);

    Chart_Init();
    Chart_Init1();
    /*定时器*/
    timerDrawLine = new QTimer();
    timerDrawLine->start(500);
    connect(timerDrawLine,&QTimer::timeout,[=](){
        DrawLine();
    });
}

lineseries::~lineseries()
{
    delete ui;
}


void lineseries::Chart_Init()
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
    ui->graphicsView1->setChart(chart);
    ui->graphicsView1->setRenderHint(QPainter::Antialiasing);      // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
}
void lineseries::DrawLine()
{
    static int count = 0;
    if(count > MAX_X)
    {
        //当曲线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries->removePoints(0,lineSeries->count() - MAX_X);
        // 更新X轴的范围
        chart->axisX()->setMin(count - MAX_X);
        chart->axisX()->setMax(count);

        //当折线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries1->removePoints(0,lineSeries1->count() - MAX_X);
        // 更新X轴的范围
        chart1->axisX()->setMin(count - MAX_X);
        chart1->axisX()->setMax(count);
    }

    //增加新的点到曲线末端
    int ht=rand()%94+2;
    lineSeries->append(count, ht);//随机生成2到95的随机数
    lineSeries1->append(count, ht);
    count ++;
}



void lineseries::Chart_Init1()
{
    //初始化QChart的实例
    chart1 = new QChart();
    //初始化QSplineSeries的实例
    lineSeries1 = new QLineSeries();

    //设置曲线的名称
    lineSeries1->setName("随机数测试折线");
    //把折线添加到QChart的实例chart中
    chart1->addSeries(lineSeries1);
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
    chart1->addAxis(axisX, Qt::AlignBottom);
    chart1->addAxis(axisY, Qt::AlignLeft);
    //把折线关联到坐标轴
    lineSeries1->attachAxis(axisX);
    lineSeries1->attachAxis(axisY);
    //把chart显示到窗口上
    ui->graphicsView2->setChart(chart1);
    ui->graphicsView2->setRenderHint(QPainter::Antialiasing);      // 设置渲染：抗锯齿，如果不设置那么折线就显得不平滑
}
void lineseries::DrawLine1()
{
//    static int count1 = 0;
//    if(count1 > MAX_X)
//    {
//        //当折线上最早的点超出X轴的范围时，剔除最早的点，
//        lineSeries1->removePoints(0,lineSeries1->count() - MAX_X);
//        // 更新X轴的范围
//        chart1->axisX()->setMin(count1 - MAX_X);
//        chart1->axisX()->setMax(count1);
//    }
//    //增加新的点到折线末端
//    lineSeries1->append(count1, rand()%99);//随机生成0到98的随机数
//    count1 ++;
}
