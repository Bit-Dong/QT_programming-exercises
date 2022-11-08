#include "mainwindow.h"
#include<QMenuBar>     //菜单栏
#include<QToolBar>     //工具栏
#include<QStatusBar>   //状态栏
#include<QPushButton>   //按钮
#include<QLabel>        //控件
#include<QDockWidget>   //铆接部件(浮动窗口)
#include<QTextEdit>     //文本编辑
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);   //重置窗口大小

    //菜单栏  最多只能有一个
    QMenuBar *bar=menuBar();//创建菜单栏
    setMenuBar(bar);   //将菜单栏放入窗口中

    //创建菜单
    QMenu *fileMenu=bar->addMenu("文件");
    QMenu *editMenu=bar->addMenu("编辑");

    //创建 菜单项
    //1.“文件”的菜单项
    QAction *newAction= fileMenu->addAction("新建");   //addAction()返回值是 QAction *  newAction接收“新建”
    fileMenu->addSeparator();   //添加分割线
    QAction *openAction= fileMenu->addAction("打开");   //用openAction 接收“打开”
    //2.“编辑”的菜单项
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");


    //创建工具栏 可以有多个
    QToolBar *toolBar=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);   //将工具栏放到窗口左边

    //后期设置 设置工具栏只允许在左右俩边停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);   //设置浮动   关闭浮动（默认开启）  即不允许工具栏在上下位置浮动
    toolBar->setMovable(false);   //设置移动(总开关)   关闭移动(默认开启)  即不允许拖动工具栏

    //在工具栏中设置内容
    toolBar->addAction(newAction);   //newAction 接收的是“新建”
    toolBar->addSeparator();   //添加分隔符
    toolBar->addAction(openAction);  //openAction 接收的是“打开”

    //在工具栏中添加控件(按钮)
    QPushButton *btn=new QPushButton("帮助",this);   //创建一个控件
    toolBar->addWidget(btn);   //将控件添加到工具栏中

    //状态栏  最多有一个
    QStatusBar *stBar=statusBar();   //创建状态栏
    setStatusBar(stBar);    //将状态栏设置到窗口中
    QLabel *label=new QLabel("左侧提示信息",this);    //创建标签控件
    stBar->addWidget(label);    //将标签控件放置stBar状态栏中   addWidget()默认放置在左下角

    QLabel *label2=new QLabel("右侧提示信息",this);    //创建标签控件
    stBar->addPermanentWidget(label2);    //将标签控件放置stBar状态栏中   addPermanentWidget()默认放置在右下角

    //铆接部件(浮动窗口) 可以有多个
    QDockWidget *dockWidget=new QDockWidget("浮动窗口1",this);    //创建浮动窗口1
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);    //将浮动窗口设置在(中心部件)下面
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);   //设置后期浮动窗口停靠区域 这里设置为允许上下停靠

    QDockWidget *dockWidget2=new QDockWidget("浮动窗口2",this);    //创建浮动窗口2
    addDockWidget(Qt::RightDockWidgetArea,dockWidget2);    //将浮动窗口2设置在(中心部件)右边
    dockWidget2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);   //设置后期浮动窗口2停靠区域 这里设置为允许左右停靠

    //设置中心部件  最多只能有一个
    QTextEdit *edit=new QTextEdit(this);     //创建中心部件
    setCentralWidget(edit);    //将中心部件放入到窗口中去
}

MainWindow::~MainWindow()
{

}
