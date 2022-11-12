#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setFixedSize(1000,800);
    resize(RECT_COLUMES*RECT_WIDTH + 300, RECT_ROWS*RECT_HEIGHT);

    int nMaxScore = GetHistoryMaxScore();
    ui->labelMaxScore->setText(QString::number(nMaxScore));

    connect(ui->widgetGameArea,&GameArea::sigUpdateScore,this,&MainWindow::slotUpdateScore);

    ui->widgetGameArea->NewGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    ui->widgetGameArea->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
}

void MainWindow::slotUpdateScore(int nScore)
{
    ui->labelScore->setText(QString::number(nScore));

    //每增加分数都判断是否超当前最高，如果超了就更新
    //本来准备在游戏结束时，与最高分比较，但是这样万一玩到很高分了，异常结束结果导致没更新，比较遗憾
    if(nScore > GetHistoryMaxScore())
    {
        ui->labelMaxScore->setText(QString::number(nScore));
        SaveHistoryMaxScore(nScore);
    }
}

int MainWindow::GetHistoryMaxScore()
{
    QString path = QCoreApplication::applicationDirPath() + "/snake.ini";
    QSettings s(path,QSettings::IniFormat);
    return s.value("Main/MaxScore", 0).toInt();
}

void MainWindow::SaveHistoryMaxScore(int nScore)
{
    QString path = QCoreApplication::applicationDirPath() + "/snake.ini";
    QSettings s(path,QSettings::IniFormat);
    s.setValue("Main/MaxScore", nScore);
}



