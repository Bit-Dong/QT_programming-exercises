#include "saoma.h"
#include "ui_saoma.h"

saoma::saoma(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saoma)
{
    ui->setupUi(this);
    this->initView();

    ui->cameraCBox->setCurrentIndex(1);   //设置默认
    timer = new QTimer(this);
    cameraBtnSlot();   //直接启动摄像头
    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    timer->start(TIMER_DELAY);
}

saoma::~saoma()
{
    delete ui;
}

void saoma::initView()
{
    this->setWindowTitle("扫二维码");
    finder = new QCameraViewfinder();
    ui->cameraView->addWidget(finder);

    this->timerSlot();

    connect(ui->cameraBtn, SIGNAL(clicked(bool)), this, SLOT(cameraBtnSlot()));
}

void saoma::updateCameras()
{
    camerasInfo.clear();
    cameraNames.clear();
    cameraNames << "";
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        camerasInfo << cameraInfo;
        cameraNames << cameraInfo.description();
    }
}

void saoma::cameraBtnSlot()
{
    if(ui->cameraCBox->isEnabled())
        if(ui->cameraCBox->currentIndex() == 0)
            QMessageBox::information(this, "警告", "请选择一个摄像头");
        else
        {
            camera = new QCamera(camerasInfo[ui->cameraCBox->currentIndex()-1]);

            camera->setCaptureMode(QCamera::CaptureStillImage);


            connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(cameraStateSlot(QCamera::State)));
            //connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(cameraErrorSlot(QCamera::Error)));

            camera->setViewfinder(finder);
            camera->start();

            if(camera->state() == QCamera::ActiveState)
            {
                ui->cameraCBox->setEnabled(false);
                ui->cameraBtn->setText("关闭");
                finder->show();
            }
            else
                QMessageBox::information(this, "警告", "无法启动该摄像头");
        }
    else
    {
        finder->hide();
        ui->cameraCBox->setEnabled(true);
        ui->cameraBtn->setText("启动");
        delete camera;
    }
}



void saoma::cameraStateSlot(QCamera::State state)
{
    switch (state)
    {
    case QCamera::ActiveState:
        break;
    case QCamera::UnloadedState:
        if(!ui->cameraCBox->isEnabled())
        {
            this->finder->hide();
            ui->cameraCBox->setEnabled(true);
            ui->cameraBtn->setText("启动");

            delete camera;
        }
        break;
    case QCamera::LoadedState:
        break;
    }
}


void saoma::timerSlot()
{
    this->updateCameras();

    while(ui->cameraCBox->count() > cameraNames.size())
        ui->cameraCBox->removeItem(cameraNames.size());
    while(ui->cameraCBox->count() < cameraNames.size())
        ui->cameraCBox->addItem(NULL);
    for(int i = 0; i < cameraNames.size(); i++)
        ui->cameraCBox->setItemText(i, cameraNames[i]);
}
