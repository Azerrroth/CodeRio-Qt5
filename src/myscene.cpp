#include "myscene.h"
#include "view.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <QDebug>

using std::fstream;
using std::string;

MyScene::MyScene()
{
    //vie = new view;
    //addItem(vie);
    //vie->setPos(0, 0);
    control=new GameBoard;
    initialize();
    setSceneRect(0, 0, 1450, 800);
}

void MyScene::initialize()
{
    addItem(getControl()->getBack());
    getControl()->getBack()->setPos(0, 0);
    getControl()->getBack()->setZValue(-100);

    addItem(getControl()->getMario());
    getControl()->getMario()->setPos(100, 700);

    fstream in("info.txt");
    string str;
    while (getline(in, str))
    {
        int x = atoi(const_cast<char*>(str.substr(3, 5).c_str()));
        int y = atoi(const_cast<char*>(str.substr(8, 3).c_str()));

        if(str.substr(0, 3) == "BLO")
        {
            blocks* blo = new blocks;
            this->addItem(blo);
            blo->setPos(x, y);
            getControl()->getBlocks().push_back(blo);
        }
        else if(str.substr() == "COI")
        {
            coins* coi = new coins;
            this->addItem(coi);
            coi->setPos(x, y);
            getControl()->getCoins().push_back(coi);
        }
        else if(str.substr(0, 3) == "MON")
        {
			monster* mon = new monster;
			this->addItem(mon);
			mon->setPos(x, y);
			getControl()->getMonster().push_back(mon);
        }

        else if(str.substr(0, 3) == "MUS")
        {
			mushroom* mus = new mushroom;
			this->addItem(mus);
			mus->setPos(x, y);
			getControl()->getMushroom().push_back(mus);
        }
		else if(str.substr(0, 3) == "CLO")
        {
			cloud* clo = new cloud;
			this->addItem(clo);
			clo->setPos(x, y);
			getControl()->getCloud().push_back(clo);
        }
		else if(str.substr(0, 3) == "STO")
		{
			stone* sto = new stone;
			this->addItem(sto);
			sto->setPos(x, y);
			getControl()->getStone().push_back(sto);
		}
		else if(str.substr(0, 3) == "QUE")
		{
			questionMark* que = new questionMark;
			this->addItem(que);
			que->setPos(x, y);
			getControl()->getQue().push_back(que);
		}
		else if(str.substr(0, 3) == "BAS")
		{
			baseblock* bas = new baseblock;
			this->addItem(bas);
			bas->setPos(x, y);
			getControl()->getBase().push_back(bas);
		}
		else if(str.substr(0, 3) == "TUB")
		{

		}
		else if(str.substr(0, 3) == "FLO")
		{

		}
		else if(str.substr(0, 3) == "FLA")
		{

		}
    }
}
void MyScene::keyPressEvent(QKeyEvent *event)
{
   qDebug() << "key" << endl;
    QList<QGraphicsItem*>list = control->getMario()->collidingItems();

    if(control->getMario()->x() <= 500 && control->getMario()->x() > 0)
    { //300即为场景移动的分界处，小于300仅移动马里奥
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(true);           //只需要在按下时候改变右走状态的布尔值，而判断碰撞物在moveMario里面
        }
        else if(event->key() == Qt::Key_A)
        {
            if(control->getMario()->x() >= 0)                   //马里奥必须不能出场景
            {
                control->getMario()->setGoingLeft(true);        //只需要在按下时候改变左走状态的布尔值，而判断碰撞物在moveMario里面
            }
        }
        else if(event->key() == Qt::Key_Space)      //改变布尔值，跳起来判断为isJumping = true
        {
            if(control->isDowncollider())           //在下方有东西的时候才能跳
            {
                control->getMario()->setJumping(true);
            }
        }
    }
    else if(control->getMario()->x() <= 0)
    {
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(true);
        }
    }
    else                                            //场景移动还未写
    {
        if(event->key() == Qt::Key_D)
        {

        }
        else if(event->key() == Qt::Key_A)
        {

        }
        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
        {

        }
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if(control->getMario()->x() <= 500 && control->getMario()->x() > 0)
    {
        if(event->key() == Qt::Key_Space)           //留个空槽，这个暂时没用
        {

        }
        else if(event->key() == Qt::Key_A)          //松开a键传停止左走的信号
        {
            control->getMario()->setGoingLeft(false);
        }
        else if(event->key() == Qt::Key_D)          //松开d键传停止右走的信号
        {
            control->getMario()->setGoingRight(false);
        }
    }
    else                                            //和移动场景相关的
    {
        if(event->key() == Qt::Key_D)
        {

        }
        else if(event->key() == Qt::Key_A)
        {

        }
        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
        {

        }
    }
}
