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
    player = new mario("mario.png");
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

    if(player->getGoingLeft()
            && !player->getJumping()            //玩家不是跳的时候才行
            && !isLeftcollider())              //左侧没有物体才能走
    {
        player->moveBy(-2,0);
    }
    else if(player->getGoingRight()
            && !player->getJumping()            //玩家不是跳的时候才行
			&& !isRightcollider())               //右侧没有物体才能走
    {
        player->moveBy(2,0);
    }

    if(player->getJumping() && !isUpcollider())                         //核心思想是通过自己写出的物理规则，模拟出可能出现的跳跃轨迹，映射到坐标上
        //还没解决跳到一半碰上障碍物的问题！！
    {
        if(player->getGoingLeft()
                && !isLeftcollider())           //左侧不能有阻挡
        {
            if(player->get_y_Relative() >= -191)
            {
            player->set_start_x(player->pos().x());
            player->set_start_y(player->pos().y());
            int remember_x = player->get_x_Relative();
            int remember_y = player->get_y_Relative();

            int temp_x_position = remember_x + 2;
            int temp_y_position = (-0.02*(temp_x_position*temp_x_position)+200);
            player->set_x_Relative(temp_x_position);
            player->set_y_Relative(temp_y_position);

            qDebug() << player->pos().x() << player->pos().y();               //这一行是调试用信息，可删去
            qDebug() << player->get_y_Relative();

            player->setPos(player->get_start_x()-(temp_x_position-remember_x),player->get_start_y()-temp_y_position+remember_y);        //描绘坐标点
            }

            else if(player->get_y_Relative() < -191)
            {
                qDebug() << "working";
                player->moveBy(0,0.5);
            }

            if(isDowncollider() == true)                                                    //若底部碰上物体，便初始化
            {
                qDebug() << "get down";
                player->setJumping(false);
                player->set_x_Relative(-100);
                player->set_y_Relative(0);
            }
        }
        else if(player->getGoingRight()
                && !isRightcollider())          //右侧不能有阻挡
        {
            if(player->get_y_Relative() >= -191)
            {
            player->set_start_x(player->pos().x());
            player->set_start_y(player->pos().y());
            int remember_x = player->get_x_Relative();
            int remember_y = player->get_y_Relative();

            int temp_x_position = remember_x + 2;
            int temp_y_position = (-0.02*(temp_x_position*temp_x_position)+200);
            player->set_x_Relative(temp_x_position);
            player->set_y_Relative(temp_y_position);

            qDebug() << player->pos().x() << player->pos().y();               //这一行是调试用信息，可删去
            qDebug() << player->get_y_Relative();

            player->setPos(player->get_start_x()+(temp_x_position-remember_x),player->get_start_y()-temp_y_position+remember_y);        //描绘坐标点
            }
            else if(player->get_y_Relative() < -191)
            {
                qDebug() << "working";
                player->moveBy(0,0.5);
            }

            if(isDowncollider() == true)                                                    //若底部碰上物体，便初始化
            {
                qDebug() << "get down";
                player->setJumping(false);
                player->set_x_Relative(-100);
                player->set_y_Relative(0);
            }
        }
        else if(player->getJumping())
        {
            if(player->get_y_Relative() >= -191)
            {
            player->set_start_x(player->pos().x());
            player->set_start_y(player->pos().y());
            int remember_x = player->get_x_Relative();
            int remember_y = player->get_y_Relative();

            int temp_x_position = remember_x + 2;
            int temp_y_position = (-0.02*(temp_x_position*temp_x_position)+200);
            player->set_x_Relative(temp_x_position);
            player->set_y_Relative(temp_y_position);

            qDebug() << player->pos().x() << player->pos().y();               //这两行是调试用信息，可删去
            qDebug() << player->get_y_Relative();
            Q_UNUSED(remember_x);

            player->setPos(player->get_start_x(),player->get_start_y()-temp_y_position+remember_y);                                     //描绘坐标点
            }
            else if(player->get_y_Relative() < -191)
            {
                qDebug() << "working";
                player->moveBy(0,0.5);
            }

            if(isDowncollider() == true)                                                    //若底部碰上物体，便初始化
            {
                qDebug() << "get down";
                player->setJumping(false);
                player->set_x_Relative(-100);
                player->set_y_Relative(0);
            }
        }
    }

    else if(player->getJumping() && (isUpcollider()||isLeftcollider()||isRightcollider()))  //应该会在这里解决跳的过程中碰上东西的问题
        //用了垂直下落的代码，还未在这个条件下进行测试！！
    {
        if(player->get_y_Relative() >= -191)
        {
        player->set_start_x(player->pos().x());
        player->set_start_y(player->pos().y());
        int remember_x = player->get_x_Relative();
        int remember_y = player->get_y_Relative();

        int temp_x_position = remember_x + 2;
        int temp_y_position = (-0.02*(temp_x_position*temp_x_position)+200);
        player->set_x_Relative(temp_x_position);
        player->set_y_Relative(temp_y_position);

        qDebug() << player->pos().x() << player->pos().y();               //这两行是调试用信息，可删去
        qDebug() << player->get_y_Relative();
        Q_UNUSED(remember_x);

        player->setPos(player->get_start_x(),player->get_start_y()-temp_y_position+remember_y);                                     //描绘坐标点
        }
        else if(player->get_y_Relative() < -191)
        {
            qDebug() << "working";
            player->moveBy(0,0.5);
        }
        qDebug() << player->get_y_Relative();
        if(isDowncollider() == true)                                                    //若底部碰上物体，便初始化
        {
            qDebug() << "get down";
            player->setJumping(false);
            player->set_x_Relative(-100);
            player->set_y_Relative(0);
        }
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
