#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实现功能： 点击新建按钮，弹出一个对话框  (用信号和槽实现链接)
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分为俩类：模态对话框(不可以对其他窗口进行操作)  非模态对话框(可以对其他窗口进行操作)

        //1.模态对话框创建     有阻塞功能，关闭对话框后才会运行“模态对话框弹出了”
        QDialog dlg(this);
        dlg.resize(200,100);     //设置对话框大小，如果太小系统会提醒警告
        dlg.exec();         //exec()是以模态方式创建  exec()有阻塞作用
        qDebug()<<"模态对话框弹出了";
    });

    //实现功能： 点击打开按钮，弹出一个对话框  (用信号和槽实现链接)
    connect(ui->actionopen,&QAction::triggered,[=](){

        //2.非模态对话框创建   无阻塞功能，一运行对话框就会被销毁，所以需放入堆区创建(防止一闪而过)
        QDialog *dlg2=new QDialog(this);    //放入堆区创建
        dlg2->resize(200,100);
        dlg2->show();     //show() 是以非模态方式创建
        dlg2->setAttribute(Qt::WA_DeleteOnClose);  //Qt::WA_DeleteOnClose是55号属性  防止内存泄露
        qDebug()<<"非模态对话框弹出了";
    });


//消息对话框  (点击“消息”)

    connect(ui->actionmes,&QAction::triggered,[=](){
    //1.错误对话框
        //QMessageBox::critical(this,"critical","错误");

    //2.信息对话框
        //QMessageBox::information(this,"info","信息");

    //3.提问对话框
        //参数1：父类  参数2：设置标题  参数3：设置提示内容   参数4：按键类型  参数5：默认关联回车
        if(QMessageBox::Save==QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Save))
        {
            qDebug()<<"选择的是保存";
        }
        else
        {
            qDebug()<<"选择的是取消";
        }

     //4.警告对话框
       // QMessageBox::warning(this,"warning","警告");


//其他标准对话框
        //1.颜色对话框
      //  QColor color=QColorDialog::getColor(QColor(255,0,0));
      //  qDebug()<<"red = "<<color.red()<<"  green = "<<color.green()<<"  blue = "<<color.blue();

        //2.文件对话框  参数1：父亲  参数2：标题  参数3：默认打开路径  参数4：过滤文件格式
                       //返回值是 选取的路径
//        QString str=QFileDialog::getOpenFileName(this,"打开文件","D:\\QT\\QtCode","(*.txt)");
//        qDebug()<<str;

        //3.字体对话框
//        bool flag;
//        QFont font=QFontDialog::getFont(&flag,QFont("华文彩云",36));
//        qDebug()<<"字体："<<font.family().toUtf8().data()<<"  字号："<<font.pointSize()<<"  是否加粗："<<font.bold()<<"  是否倾斜："<<font.italic();


    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
