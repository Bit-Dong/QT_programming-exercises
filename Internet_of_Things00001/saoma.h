#ifndef SAOMA_H
#define SAOMA_H

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
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    QImage image;
};

#endif // SAOMA_H
