#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>

//Teacher 类  老师类
//Student 类  学生类
//下课后，老师会触发一个信号，饿了，学生相应信号，请客吃饭

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt=new Teacher(this);
    //创建一个学生对象
    this->st=new Student(this);

//    //老师饿了 学生请客吃饭的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);
//    //先用 connect 将老师和学生信号连接起来，再调用下课函数 使老师发出触发信号
//    //调用下课函数
//    classIsOver();

    //连接带参数的信号和槽
    //指针->地址   函数指针->函数地址
    //函数指针：函数返回值类型（*指针变量名）（函数参数列表）
    void(Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void(Student::*studentSlot)(QString)=&Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
  //  classIsOver();      //此函数使老师发出 饿了信号


    //点击一个 下课的按钮，再触发下课
    QPushButton * btn1 =new QPushButton("下课",this);
    this->resize(600,400);    //重置窗口大小

    //点击按钮 触发下课
   // connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

/*    //无参信号和槽连接
    void(Teacher::*teacherSignal2)(void)=&Teacher::hungry;
    void(Student::*studentSlot2)(void)=&Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);   //老师发出饿了信号后 学生做出反应
*/

    //信号连接信号
//    connect(btn,&QPushButton::clicked,zt,teacherSignal2);  //点击按钮后 老师响应饿了的信号

    //断开信号
//    disconnect(zt,teacherSignal2,st,studentSlot2);   //此行代码可以断开 老师和同学之间的连接信号
                                                    //即老师发出饿了信号后，学生不会做出反应


    //Lambda表达式
/*    QPushButton *btn3=new QPushButton("Over",this);
    btn3->move(100,0);
    [btn](){         //[]里面只添加了btn 表示下面{}里只会识别到btn的相关操作
        btn->setText("aaaa");
       // btn3->setText("bbbb");    //识别不到
    }();      //最后面加一个() 表示调用此表达式
*/



    //mutable关键字 用于修饰值传递的变量，修改的是拷贝，而不是本体
/*  QPushButton *mybtn=new QPushButton("one",this);
    QPushButton *mybtn2=new QPushButton("two",this);
    mybtn->move(100,0);
    mybtn2->move(100,100);
    int m=10;
    connect(mybtn,&QPushButton::clicked,this,[m]()mutable{m=100+10;qDebug()<<m;});   //点击“one” 输出m=110，即修改的是拷贝值
    connect(mybtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});    //点击“two” 输出m=10，即m的本体没有被修改
    qDebug()<<m;
*/

//    int ret=[]()->int{return 1000;}();
//    qDebug()<<"ret = "<<ret;

    //利用Lambda表达式 实现点击按钮 关闭窗口    最常用的表达式是： [=](){}
    QPushButton *btn2=new QPushButton("关闭",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,[=](){
//        this->close();     //关闭窗口
        emit zt->hungry("宫保鸡丁");    //点击“关闭”按钮 触发老师饿了信号
    });

}


void Widget::classIsOver()
{
    //下课函数，调用后 出发老师饿了的信号
    //emit zt->hungry();      //emit 触发自定义信号关键字
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}
