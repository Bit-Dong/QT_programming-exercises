#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->actionnew->setIcon(QIcon("C:/Users/29054/Pictures/Saved Pictures/Mr.cat"));

    //使用添加Qt资源的方式将图标加上去  语法： “ : + 前缀名 + 文件名 ”
    ui->actionnew->setIcon(QIcon(":/Saved Pictures/Mr.cat.jpg"));
    ui->actionopen->setIcon(QIcon(":/Saved Pictures/sunset_glow.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
