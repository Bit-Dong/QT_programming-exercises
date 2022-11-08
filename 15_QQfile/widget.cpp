#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>
#include<QFileDialog>     //文件对话框
#include<QFile>      //读文件
#include<QTextCodec>  //编码格式类
#include<QFileInfo>   //文件信息
#include<QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //实现功能：点击选取文件按钮，弹出文件对话框
    connect(ui->btn1,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\29054\\Desktop");
        ui->lineEdit->setText(path);   //将路径放入到lineEdit中

//        //编码格式类
//        QTextCodec *code=QTextCodec::codecForName("gbk");

        //读取内容放入到textEdit中     QFile默认支持的格式为 utf-8
        QFile file(path);    //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);    //只读
        QByteArray array=file.readAll();   //一次性读取文件全部内容

//        QByteArray array;
//        while(!file.atEnd())   //如果不是文章末尾
//        {
//            array+=file.readLink();    //按行读
//        }

        ui->textEdit->setText(array);    //将读取到的数据 放入textEdit中
        //ui->testEdit->setText(codec->toUnicode(array));

        file.close();     //对文件对象进行关闭

//        //2、进行写文件
//        file.open(QIODevice::Append);   //用追加方式进行写
//        file.write("\n啊啊啊啊");
//        file.close();


        //3、QFileInof 文件信息类
        QFileInfo info(path);

        qDebug()<<"大小："<<info.size()<<"  后缀名："<<info.suffix()<<"  文件名称："<<info.fileName()<<"  文件路径："<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}
