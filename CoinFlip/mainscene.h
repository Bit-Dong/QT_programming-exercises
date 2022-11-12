#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"chooselevelscene.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //重现paintEvent事件  画背景图
    void paintEvent(QPaintEvent *);

    ChooseLevelScene *chooseSence=NULL;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
