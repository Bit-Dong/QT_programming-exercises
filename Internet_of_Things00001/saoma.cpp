#include "saoma.h"
#include "ui_saoma.h"

saoma::saoma(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saoma)
{
    ui->setupUi(this);
    //摄像头信息获取
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        //if (cameraInfo.deviceName() == "/dev/video0") //Linux下选择方式
        camera = new QCamera(cameraInfo);
        qDebug()<<cameraInfo.deviceName();
    }
    //设置摄像头捕获模式
    camera->setCaptureMode(QCamera::CaptureStillImage);
    //图像回显
    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    this->setCentralWidget(viewfinder);

    //QCameraImageCapture 是获取摄像头捕捉的图片 相关类
    imageCapture = new QCameraImageCapture(camera);
    //绑定 捕获图片 信号 和 处理图片槽函数
    //connect(imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(takeImage(int,QImage)));

    //启动摄像头
    this->camera->start();
}

saoma::~saoma()
{
    delete ui;
}
