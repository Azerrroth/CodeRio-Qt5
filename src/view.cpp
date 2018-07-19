#include "view.h"
#include <QDebug>
#include <QPainter>
#include <fstream>
#include <string>
#include "gameboard.h"

using std::string;
using std::fstream;

view::view()
{
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemIsMovable);
    control = new GameBoard;
    qDebug() << "view was created" << endl;
}

QRectF view::boundingRect() const{
	return QRectF(0, 0, 100, 100);
}

void view::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void view::keyPressEvent(QKeyEvent *event)
{
	qDebug() << "key" << endl;
    QList<QGraphicsItem*>list = control->getMario()->collidingItems();

    if(control->getMario()->x() < 300)
    { //300即为场景移动的分界处，小于300仅移动马里奥
        if(event->key() == Qt::Key_D)
        {
            /*bool flag = true;
            for(int i = 0; i < list.size(); i++) {
                if(list[i]->x() >= control->getMario()->x() &&
                   list[i]->y() <= control->getMario()->y())
                {//判断与该物体接触的物体是否阻挡了该物体右移，若阻挡了则不做处理
                    flag = false;
                    break;
                }
            }
            if(flag) {
                control->getMario()->setMove(4, 0);
            }*/

            control->getMario()->setGoingRight(true);           //只需要在按下时候改变右走状态的布尔值，而判断碰撞物在moveMario里面
        }
        else if(event->key() == Qt::Key_A)
        {
            if(control->getMario()->x() >= 0)                   //马里奥必须不能出场景
            {
                /*bool flag = true;

                for(int i = 0; i < list.size(); i++) {
                    if(list[i]->x() <= control->getMario()->x() &&
                       list[i]->y() <= control->getMario()->y())
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    control->getMario()->setMove(-4, 0);
                }*/

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
        //E按键的操控已经省去了
        //是否还要做一个s键蹲下？
    }

    else                                            //场景移动还未写
    {
        if(event->key() == Qt::Key_D)
        {

        }
        else if(event->key() == Qt::Key_A)
        {

        }
        /*else if(event->key() == Qt::Key_Q)
        {

        }
        else if(event->key() == Qt::Key_E)
        {

        }*/
        //暂时不需要Q和E了

        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
            //需要一个新的来操作场景的函数
        {

        }
    }
}

void view::keyReleaseEvent(QKeyEvent *event)
{
    if(control->getMario()->x() < 300)
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
        //暂时不需要Q和E了
        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
            //需要一个新的来操作场景的函数
        {

        }
    }
}
