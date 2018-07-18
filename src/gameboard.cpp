#include "gameboard.h"
#include "mario.h"
#include "blocks.h"
#include <QTimer>

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
	timerId = startTimer(15);//开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称，
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
