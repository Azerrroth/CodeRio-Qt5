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

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
	timerId = startTimer(15);	//开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称，
}

void GameBoard::setItems(const QString file)
{
	fstream in(":informations.txt");
	string str;
	while(getline(in, str))
	{
		int x = atoi(const_cast<char*>(str.substr(3, 7).c_str()));
		int y = atoi(const_cast<char*>(str.substr(10, 7).c_str()));
		
		if(str.substr(0, 3) == "BLO") 
		{		
			blocks* block = new blocks(":picture/block.png");
			block->setPos(x, y);
			blocklist.push_back(block);
		}
		
		else if(str.substr(0, 3) == "COI") 
		{
			coins* coin = new coins(":picture.coin.png");
			coin->setPos(x, y);
			coinlist.push_back(coin);
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

void GameBoard::timerEvent(QTimerEvent *event)
{
	moveView();
	moveMario();
}

void GameBoard::moveView()
{
	back->move();
	for(int i = 0; i < blocklist.size(); i++)
	{
		blocklist[i]->move();
	}
}

void GameBoard::moveMario()
{
	player->move();
}

bool GameBoard::isLeftcollider()
{
	QList<QGraphicsItem*> list = player->collidingItems();
	if(list.isEmpty()) return false;
	else
	{
		for(int i = 0; i < list.size(); i++)
		{
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
			if(list[i]->y() <= player->y())
				return true;
		}
		return false;
	}
}

bool GameBoard::isDowncollider()
{
	QList<QGraphicsItem*> list = player->collidesItem();
	if(list.isEmpty()) return false;
	else
	{
		for(int i = 0; i < list.size(); i++)
		{
			if(list[i]->y() >= player->y())
				return true;
		}
		return false;
	}
}
