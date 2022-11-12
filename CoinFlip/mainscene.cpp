#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<QSound>  //多媒体模块下的音效头文件

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置窗口固定大小
    setFixedSize(320,588);

    //设置窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置窗口标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //准备开始按钮的音效
    QSound *startSound=new QSound(":/res/TapButtonSound.wav");
    //startSound->setLoops(10);   //代表循环次数，如果是-1代表无线循环
    startSound->play();

    //开始按钮
    MyPushButton *startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.35,this->height()*0.7);   //移动到合适的位置

    //实例化选择关卡场景
    chooseSence=new ChooseLevelScene;

    //监听选择关卡的返回按钮信号
    connect(chooseSence,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseSence->geometry());
        chooseSence->hide();    //将选择关卡隐藏掉
        this->show();   //重新显示主场景
    });

    //点击start按钮 实现弹跳效果
    connect(startBtn,&MyPushButton::clicked,[=](){

        //播放开始音效资源
        startSound->play();

        //弹跳效果
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){    //延时500ms在进行以下操作

            //设置chooseScene场景的位置
            chooseSence->setGeometry(this->geometry());

            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseSence->show();
        });


    });

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);   //声明画家
    //1、画背景图
    QPixmap pix;   //声明对象
    pix.load(":/res/PlayLevelSceneBg.png");   //在对象中加载图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);   //画背景图

    //2、画背景上图标
    pix.load(":/res/Title.png");   //加载图片
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);  //因图标有点大，所以在这里按比例缩小一倍
    painter.drawPixmap(10,30,pix);    //画上图标
}

MainScene::~MainScene()
{
    delete ui;
}
