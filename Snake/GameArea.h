#ifndef GAMEAREA_H
#define GAMEAREA_H

//#include "Item.h"
#include <QWidget>

#define RECT_COLUMES	20
#define RECT_ROWS		20
#define RECT_WIDTH		30
#define RECT_HEIGHT		30


enum MOVE_DIRECTION{
    MOVE_LEFT = 0,
    MOVE_UP,
    MOVE_RIGHT,
    MOVE_DOWN,
};

class GameArea : public QWidget
{
    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = nullptr);

    void NewGame();
    void NewFood();

    QPoint GetRandomPoint();
    void KeyPressed(int key);

signals:
    void sigUpdateScore(int nScore);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent*);

private:
    void DrawSide();        //画边框
    void DrawSnake();       //画蛇
    void DrawFood();        //画食物

    //获取不同分段对应的定时器时间，关卡越高，时间越快(短)
    int GetScoreSpeed(int nScore);

    bool SnakeHitSide();        //蛇是否出边框
    bool HitSide(QPoint pt);    //判断一个点是否出边框
    bool HitSnake(QPoint pt);   //判断一个点是否在蛇上



private:
    QList<QPoint> mSnake;       //蛇身体
    QPoint mFood;               //食物
    MOVE_DIRECTION mDirection;  //当前移动方向

    //mMoved:防止未移动时连续变向，导致出现直接掉头情况
    //每次变向后置false，产生移动才置true
    //下次变向前判断，上次变向后有过移动才能再变
    bool mMoved;

    bool mPause;        //是否暂停

    int mTimerID;       //定时器ID
    int mScore;         //得分

};

#endif
