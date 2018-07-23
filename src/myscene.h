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
    void moveMonster();	//移动怪物
    void moveFlower();

	void removeCoins();				//判断金币是否被碰撞的函数，若被玛丽奥碰撞则移除金币
	void judgeQue();				//判断问号方块是否被玛丽奥碰撞

private:
    void initialize();
    //view* vie;
    QTimer *timer;
private:
    GameBoard* control;

private slots:
    void refresh();

private:
    void timerEvent(QTimerEvent* event);            //timerevent从gameboard改动到了myscene
    int timerId;

    int pos_x;                      //判断移动的参数
    bool isMoving;


};

#endif // MYSCENE_H
