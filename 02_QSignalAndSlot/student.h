#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期Qt版本，必须要写到public slots 下，高级版本可以写到 public或者全局下
    //返回值 void，需要声明，也需要实现
    //可以有参数，可以发生重载
    void treat();    // treat 请客的意思
    void treat(QString foodName);
};

#endif // STUDENT_H
