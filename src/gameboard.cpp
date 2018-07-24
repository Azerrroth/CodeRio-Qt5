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
    //timerId = startTimer(15);                     //开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称，暂时取消！
    player = new mario();
    back = new background("background.png");
	fla = new flag;
//    setItems("info.txt");
}


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

    if(!player->getJumping() && !isDowncollider())
    {
        player->moveBy(0,2);
        if(isDowncollider())
            player->setPixmap("Rstand.png");

    }

    if(player->getJumping() && !isUpcollider())
    {
        int temp = player->getJumpingTime();
        if(temp < 125)
        {
            player->moveBy(0,-2);
        }
        else {
            player->moveBy(0,2);
        }
        player->setJumpingTime(temp+1);

        if(isDowncollider())
        {
            player->setJumping(false);
            player->setJumpingTime(0);
            //落地变stand姿态
            player->setPixmap("Rstand.png");
        }

    }
    else if(player->getJumping() && isUpcollider())
    {
        int temp = player->getJumpingTime();
        player->setJumpingTime(250-temp);
        player->moveBy(0,2);
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
			   QString(typeid(*list.at(i)).name()) != "4tube")
			{
				continue;
			}
			else if(QString(typeid(*(list.at(i))).name()) == "6flower" ||
					QString(typeid(*(list.at(i))).name()) == "7monster")
			{
				player->setDie(true);
				continue;
			}
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
			   QString(typeid(*list.at(i)).name()) != "4tube")
			{
				continue;
			}
			else if(QString(typeid(*(list.at(i))).name()) == "6flower" ||
					QString(typeid(*(list.at(i))).name()) == "7monster")
			{
				player->setDie(true);
				continue;
			}
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
			   QString(typeid(*list.at(i)).name()) != "4tube")
			{
				continue;
			}
			else if(QString(typeid(*(list.at(i))).name()) == "6flower" ||
					QString(typeid(*(list.at(i))).name()) == "7monster")
			{
				player->setDie(true);
				continue;
			}
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
			   QString(typeid(*list.at(i)).name()) != "4tube")
			{
				continue;
			}
			else if(QString(typeid(*(list.at(i))).name()) == "6flower" ||
					QString(typeid(*(list.at(i))).name()) == "7monster")
			{
				player->setDie(true);
				continue;
			}
			if(list[i]->y() <= (player->y() + 50) &&
			   list[i]->y() >= (player->y() + 48))
			{
				return true;
			}
        }
		return false;
    }
}

bool GameBoard::monisLeft(monster* mon)
{
	QList<QGraphicsItem*> list = mon->collidingItems();
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
			if(list[i]->x() <= mon->x() &&
			   list[i]->y() <= mon->y())
			{
				return true;
			}
		}
		return false;
	}
}

bool GameBoard::monisRight(monster *mon)
{
	QList<QGraphicsItem*> list = mon->collidingItems();
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
			if(list[i]->x() >= mon->x() &&
			   list[i]->y() <= mon->y())
			{
				return true;
			}
		}
		return false;
	}
}

bool GameBoard::monisDown(monster *mon)
{
	QList<QGraphicsItem*> list = mon->collidingItems();			//是否这一行有问题？collidesItem()还是collidingItems()？
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
			if(list[i]->y() <= (mon->y() + 50) &&
			   list[i]->y() >= (mon->y() + 48))
			{
				return true;
			}
		}
		return false;
	}
}

