#include "GameArea.h"
#include <QTimerEvent>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>
#include <QPainter>
#include <QUuid>



GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    mScore = 0;
    mMoved = false;
    mPause = false;
    mDirection = MOVE_RIGHT;

    setMinimumSize(RECT_COLUMES*RECT_WIDTH, RECT_ROWS*RECT_HEIGHT);
}

void GameArea::NewGame()
{
    mScore = 0;
    mDirection = MOVE_RIGHT;

    mSnake.clear();
    mSnake.append(QPoint(11,9));
    mSnake.append(QPoint(10,9));
    mSnake.append(QPoint(9,9));

    NewFood();

    mTimerID = startTimer( GetScoreSpeed(mScore) );
}

void GameArea::NewFood()
{
    mFood = GetRandomPoint();
    while(HitSide(mFood) || HitSnake(mFood))
    {
        mFood = GetRandomPoint();
    }
}

QPoint GameArea::GetRandomPoint()
{
    qsrand(QUuid::createUuid().data1);
    int x = (qrand()%RECT_COLUMES);

    qsrand(QUuid::createUuid().data2);
    int y = (qrand()%RECT_ROWS);

    return QPoint(x,y);
}

void GameArea::KeyPressed(int key)
{
    if(key == Qt::Key_Space)
    {
        mPause = !mPause;
    }

    if(mMoved)
    {
        if(key == Qt::Key_Left)
        {
            if(mDirection == MOVE_UP || mDirection == MOVE_DOWN)
            {
                mDirection = MOVE_LEFT;
            }
        }
        else if(key == Qt::Key_Up)
        {
            if(mDirection == MOVE_LEFT || mDirection == MOVE_RIGHT)
            {
                mDirection = MOVE_UP;
            }
        }
        else if(key == Qt::Key_Right)
        {
            if(mDirection == MOVE_UP || mDirection == MOVE_DOWN)
            {
                mDirection = MOVE_RIGHT;
            }
        }
        else if(key == Qt::Key_Down)
        {
            if(mDirection == MOVE_LEFT || mDirection == MOVE_RIGHT)
            {
                mDirection = MOVE_DOWN;
            }
        }
    }
    mMoved = false;
}

void GameArea::paintEvent(QPaintEvent *)
{
    DrawSide();
    DrawSnake();
    DrawFood();

    update();
}

void GameArea::DrawSide()
{
    QPainter painter(this);
    painter.setBrush(QColor("#696969"));
    painter.setPen(Qt::NoPen);

    for(int i = 0;i<RECT_COLUMES; i++)
    {
        for (int j = 0; j<RECT_ROWS; j++)
        {
            if (i == 0 || i == RECT_COLUMES - 1 || j==0 || j==RECT_ROWS-1)
            {
                painter.drawRect( i*RECT_WIDTH,j*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
            }
        }
    }
}


void GameArea::DrawSnake()
{
    QPainter painter(this);
    painter.setBrush(QColor("#FFDEAD"));
    //    painter.setPen(QPen(QColor(Qt::black),1));
    painter.setPen(Qt::black);
    foreach (QPoint pt, mSnake)
    {
        painter.drawRect( pt.x()*RECT_WIDTH,pt.y()*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
    }
}

void GameArea::DrawFood()
{
    QPainter painter(this);
    painter.setBrush(QColor("#FF3333"));
//    painter.setPen(QPen(QColor(Qt::black),1));
    painter.setPen(Qt::black);
    painter.drawRect( mFood.x()*RECT_WIDTH,mFood.y()*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
}

void GameArea::timerEvent(QTimerEvent* e)
{
    if (e->timerId() == mTimerID)
    {
        if(mPause)
        {
            //暂停
            return;
        }
        QPoint pt = mSnake.first();
        if(mDirection == MOVE_LEFT)
        {
            pt.setX( pt.x() - 1);
        }
        else if(mDirection == MOVE_RIGHT)
        {
            pt.setX( pt.x() + 1);
        }
        else if(mDirection == MOVE_UP)
        {
            pt.setY( pt.y() - 1);
        }
        else if(mDirection == MOVE_DOWN)
        {
            pt.setY( pt.y() + 1);
        }

        if(HitSnake(pt))
        {
            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("撞到自己，游戏结束！"));
            NewGame();
            return;
        }

        mSnake.insert(0,pt);

        if (SnakeHitSide())
        {
            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("撞到围墙，游戏结束！"));
            NewGame();
            return;
        }

        if(HitSnake(mFood))
        {
            //吃掉食物，加分
            NewFood();
            mScore += 100;
            emit sigUpdateScore(mScore);

            killTimer(mTimerID);
            mTimerID = startTimer( GetScoreSpeed(mScore) );
        }
        else
        {
            mSnake.removeLast();
        }
        mMoved = true;
    }
}

bool GameArea::SnakeHitSide()
{
    foreach (QPoint pt, mSnake)
    {
        if(HitSide(pt))
        {
            return true;
        }
    }
    return false;
}

bool GameArea::HitSide(QPoint pt)
{
    int x = pt.x();
    int y = pt.y();
    if(x <= 0 || x >= RECT_COLUMES - 1 || y <= 0 || y >= RECT_ROWS - 1)
    {
        return true;
    }
    return false;
}

bool GameArea::HitSnake(QPoint pt)
{
    foreach (QPoint p, mSnake) {
        if(p == pt){
            return true;
        }
    }
    return false;
}

int GameArea::GetScoreSpeed(int nScore)
{
    //随得分变高，速度越来越快
    int level = nScore / 100;
    if(level > 10)
    {
        return 130;
    }
    return 400 - level * 30;
}

