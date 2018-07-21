#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include "gameboard.h"
#include "blocks.h"
#include "mario.h"
#include "coins.h"
#include "background.h"
#include "baseblock.h"
#include "questionmark.h"
#include "stone.h"
#include "monster.h"
#include "cloud.h"
#include "flower.h"
#include "tube.h"
#include "mushroom.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyScene();
    //实现左移右移的时候注意Mario若在0~500像素范围内金仅移动Mario
    //超出了相应坐标后，移动场景及其他物体的x坐标，而仅移动Mario的y坐标
    //这样就能实现场景游动的效果

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    GameBoard* getControl(){return control;}
    void moveView();

private:
    void initialize();
    //view* vie;
    QTimer *timer;
private:
    GameBoard* control;

<<<<<<< HEAD
private slots:
    void refresh();
=======
    void timerEvent(QTimerEvent* event);            //timerevent从gameboard改动到了myscene
    int timerId;

    int pos_x;                      //判断移动的参数
    bool isMoving;

>>>>>>> b1140cb7202a24023e6d21c247877873dc67701a
};

#endif // MYSCENE_H
