#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //1、pixmap绘图设备  专门为平台做了显示的优化
//    QPixmap pix(300,300);   //创建300x300绘图大小

//    //填充颜色
//    pix.fill(Qt::white);

//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));    //画笔颜色
//    painter.drawEllipse(QPoint(150,150),100,100);  //画圆

//    //保存
//    pix.save("D:\\QT\\Qt_PaintDevice\\pix.png");     //保存路径



//    //2、QImage 绘图设备  可以对像素进行访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    img.save("D:\\QT\\Qt_PaintDevice\\img.png");


    //3、QPicture 绘图设备  可以记录和重现绘制指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);  //开始往pic上画
    painter.setPen(QPen(Qt::cyan));    //cyan青色
    painter.drawEllipse(QPoint(150,150),100,100);
    painter.end();   //结束画画

    //保存
    pic.save("D:\\QT\\Qt_PaintDevice\\pic.nd");   //自定义nd后缀  文件无法打开，需要用我自己的代码在程序中打开

}

//绘图事件
void Widget::painterEvent(QPaintEvent *)
{
//    QPainter painter(this);   //创建画家

//    //利用QImage 对像素进行修改
//    QImage img;   //创建绘图设备
//    img.load(":/Saved Pictures/Mr.cat.png");    //在绘图设备上加载图片

//    //修改像素点
//    for(int i=50;i<100;i++)
//    {
//        for(int j=50;j<100;j++)
//        {
//            QRgb value=qRgb(100,100,100);
//            img.setPixel(i,j,value);
//        }
//    }

//    painter.drawImage(0,0,img);   //在(0,0)点上绘图


    //重现QPicture的绘图指令
    QPainter painter(this);   //创建画家
    QPicture pic;
    pic.load("D:\\QT\\Qt_PaintDevice\\pic.nd");   //加载图片路径
    painter.drawPicture(0,0,pic);   //在(0,0)点画出图片
}


Widget::~Widget()
{
    delete ui;
}
