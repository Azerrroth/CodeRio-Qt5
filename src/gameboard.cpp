#include "gameboard.h"
#include "mario.h"
#include "blocks.h"
#include "coins.h"
#include <QTimer>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using std::fstream;
using std::string;
#include <QDebug>           //用于生成调试用信息，在生成可执行文件时删去

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
    qDebug() << "GameBoard was created" << endl;
    //timerId = startTimer(15);                     //开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称，暂时取消！
    player = new mario();
    back = new background("background.png");
	fla = new flag;
    setItems("info.txt");
}

void GameBoard::setItems(string file)
{
    fstream in(file);
    string str;
    while(getline(in, str))
    {
        int x = atoi(const_cast<char*>(str.substr(3, 7).c_str()));
        int y = atoi(const_cast<char*>(str.substr(10, 7).c_str()));

        if(str.substr(0, 3) == "BLO")
        {
            blocks* block = new blocks("block.png");
            block->setPos(x, y);
            blocklist.push_back(block);
        }

        else if(str.substr(0, 3) == "COI")
        {
            //			coins* coin = new coins(":picture.coin.png");
            //			coin->setPos(x, y);
            //			coinlist.push_back(coin);
        }
        else if(str.substr(0, 3) == "MON")
        {

        }
        else if(str.substr(0, 3) == "FLA")
        {

        }
        else if(str.substr(0, 3) == "MUS")
        {

        }
        else if(str.substr(0, 3) == "TUR")
        {

        }
    }

}

/*void GameBoard::timerEvent(QTimerEvent *event)
{
    if(player->x() <= 0) { player->setGoingLeft(false); }
    //	moveView();
    back->update();
    moveMario();
}*/

/*void GameBoard::moveView()
{
    back->move();
    for(int i = 0; i < blocklist.size(); i++)
    {
        blocklist[i]->move();
    }
}*/
//应该暂时用不到这个move函数

void GameBoard::moveMario()
{

    if(player->getGoingLeft()            //玩家不是跳的时候才行
            && !isLeftcollider())              //左侧没有物体才能走
    {
        player->moveBy(-1,0);
    }
    else if(player->getGoingRight()            //玩家不是跳的时候才行
			&& !isRightcollider())               //右侧没有物体才能走
    {
        player->moveBy(1,0);
    }

    if(player->getJumping() && !isUpcollider())
    {
        int temp = player->getJumpingTime();
        if(temp <300)
        {
            player->moveBy(0,-1);
        }
        else {
            player->moveBy(0,1);
        }
        player->setJumpingTime(temp+1);

        if(isDowncollider())
        {
            player->setJumping(false);
            player->setJumpingTime(0);
        }

    }
    else if(player->getJumping() && isUpcollider())
    {
        int temp = player->getJumpingTime();
        player->setJumpingTime(600-temp);
        player->moveBy(0,1);
    }
}

bool GameBoard::isLeftcollider()
{
    QList<QGraphicsItem*> list = player->collidingItems();
    if(list.isEmpty()) return false;
    else
    {
        for(int i = 0; i < list.size(); i++)
        {
			if(QString(typeid(*(list.at(i))).name()) != "6blocks" &&
			   QString(typeid(*list.at(i)).name()) != "9baseblock" &&
			   QString(typeid(*list.at(i)).name()) != "12questionMark" &&
			   QString(typeid(*list.at(i)).name()) != "5stone" &&
			   QString(typeid(*list.at(i)).name()) != "5cloud" &&
			   QString(typeid(*list.at(i)).name()) != "4tube") continue;
            if(list[i]->x() <= player->x() &&
                    list[i]->y() <= player->y())
            {
                return true;
            }
        }
        return false;
    }
}

bool GameBoard::isRightcollider()
{
    QList<QGraphicsItem*> list = player->collidingItems();
    if(list.isEmpty()) return false;
    else
    {

        for(int i = 0; i < list.size(); i++)
        {
			if(QString(typeid(*(list.at(i))).name()) != "6blocks" &&
			   QString(typeid(*list.at(i)).name()) != "9baseblock" &&
			   QString(typeid(*list.at(i)).name()) != "12questionMark" &&
			   QString(typeid(*list.at(i)).name()) != "5stone" &&
			   QString(typeid(*list.at(i)).name()) != "5cloud" &&
			   QString(typeid(*list.at(i)).name()) != "4tube") continue;
            if(list[i]->x() >= player->x() &&
                    list[i]->y() <= player->y())
            {
                return true;
            }
        }
        return false;
    }
}

bool GameBoard::isUpcollider()
{
    QList<QGraphicsItem*> list = player->collidingItems();
    if(list.isEmpty()) return false;
    else
    {

        for(int i = 0; i < list.size(); i++)
        {
			if(QString(typeid(*(list.at(i))).name()) != "6blocks" &&
			   QString(typeid(*list.at(i)).name()) != "9baseblock" &&
			   QString(typeid(*list.at(i)).name()) != "12questionMark" &&
			   QString(typeid(*list.at(i)).name()) != "5stone" &&
			   QString(typeid(*list.at(i)).name()) != "5cloud" &&
			   QString(typeid(*list.at(i)).name()) != "4tube") continue;
               if(list[i]->y() >= (player->y() - 50) &&
                  list[i]->y() <= (player->y() - 45) &&
				  list[i]->x() ) return true;
        }
        return false;
    }
}

bool GameBoard::isDowncollider()
{
    QList<QGraphicsItem*> list = player->collidingItems();			//是否这一行有问题？collidesItem()还是collidingItems()？
    //回复楼上：的确有问题，少了个s
    if(list.isEmpty()) return false;
    else
    {
        for(int i = 0; i < list.size(); i++)
        {
			if(QString(typeid(*(list.at(i))).name()) != "6blocks" &&
			   QString(typeid(*list.at(i)).name()) != "9baseblock" &&
			   QString(typeid(*list.at(i)).name()) != "12questionMark" &&
			   QString(typeid(*list.at(i)).name()) != "5stone" &&
			   QString(typeid(*list.at(i)).name()) != "5cloud" &&
			   QString(typeid(*list.at(i)).name()) != "4tube") continue;
			qDebug() << "block";
			qDebug() << player->y() << " " << list[i]->y();
			if(list[i]->y() <= (player->y() + 50) &&
			   list[i]->y() >= (player->y() + 48))
			{
				qDebug() << "DownTrue";
				return true;
			}
        }
		return false;
    }
}
