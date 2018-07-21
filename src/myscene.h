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
public:
    MyScene();
    //实现左移右移的时候注意Mario若在0~300像素范围内金仅移动Mario
    //超出了相应坐标后，移动场景及其他物体的x坐标，而仅移动Mario的y坐标
    //这样就能实现场景游动的效果

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    GameBoard* getControl(){return control;}
    void moveView();

private:
    void initialize();
    //view* vie;

private:
    GameBoard* control;

    void timerEvent(QTimerEvent* event);            //timerevent从gameboard改动到了myscene
    int timerId;

    int pos_x;                      //判断移动的参数
    bool isMoving;

};

#endif // MYSCENE_H
