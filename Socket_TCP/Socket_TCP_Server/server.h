#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include<QTcpServer>//监听套接字
#include<QTcpSocket>//通信套接字

QT_BEGIN_NAMESPACE
namespace Ui {
class server;
}
QT_END_NAMESPACE

class server : public QWidget
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();

private slots:
    void on_buttonsend_clicked();

    void on_buttonclose_clicked();

private:
    Ui::server *ui;
    //声明两种套接字
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;
};

#endif // SERVER_H
