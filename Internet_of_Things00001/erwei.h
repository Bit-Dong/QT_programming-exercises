#ifndef ERWEI_H
#define ERWEI_H

#include <QWidget>
#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QBuffer>
#include <QThread>
#include <QTimer>
#include <QLabel>

namespace Ui {
class erwei;
}

class erwei : public QWidget
{
    Q_OBJECT

public:
    explicit erwei(QWidget *parent = nullptr);
    ~erwei();

private:
    Ui::erwei *ui;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    QImage image;

};

#endif // ERWEI_H
