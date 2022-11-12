#ifndef SAOMA_H
#define SAOMA_H

#include <QMainWindow>
#include <QStringList>
#include <QList>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraImageCapture>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QFileInfo>
#define TIMER_DELAY 1000

namespace Ui {
class saoma;
}

class saoma : public QMainWindow
{
    Q_OBJECT

public:
    explicit saoma(QWidget *parent = nullptr);
    ~saoma();

private:
    Ui::saoma *ui;
    QStringList cameraNames;            // 所有摄像头设备名称
    QList<QCameraInfo> camerasInfo;     // 所有摄像头设备集合

    QCamera *camera;                    // 摄像头对象
    QCameraViewfinder *finder;          // 摄像头显示控件

    QTimer *timer;                      // 定时器对象，用于定时更新摄像头设备


    void initView();
    void updateCameras();               // 更新摄像头设备

private slots:
    void cameraBtnSlot();

//    void cameraCaptureSlot(int id, QImage image);
//    void captureErrorSlot(int id, QCameraImageCapture::Error error, QString errorString);
    void cameraStateSlot(QCamera::State state);
//    void cameraErrorSlot(QCamera::Error error);

    void timerSlot();
};

#endif // SAOMA_H
