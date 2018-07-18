#include "mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <QCoreApplication>
#include <QTime>
#include <QDebug>

mario::mario(const QString pix_one) : m_count(0)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    m_pix_one.load(pix_one);
}

QRectF mario::boundingRect() const{
    double penWidth = 1;
	return QRectF(7.5 - penWidth / 2, 0 - penWidth / 2, 35 + penWidth, 50 + penWidth);
}

void mario::setMove(qreal x, qreal y) {
	move_x = x;
	move_y = y;
}

void mario::move() {
	moveBy(move_x, move_y);
}

void mario::keyPressEvent(QKeyEvent *event)
{
	qDebug() << "key Press" << endl;
	qreal x = this->x();
	qreal y = this->y();
	QList<QGraphicsItem*>list = collidingItems();
	if(event->key()==Qt::Key_Space)
    {
		if(!list.empty()) {
			if(QString(typeid(*(list.at(0))).name()) == "6blocks"){
				list = collidingItems();
				bool flag = true;

				//up
				for(int i = 0; i < list.size(); i++) {
					if(this->y() > list[i]->y()) {
						flag = false;
						break;
					}
				}
				if(flag) {
					for(int i = 0; i < 100; i++) {

						list = collidingItems();
						bool flag1 = true;
						for(int i = 0; i < list.size(); i++) {
							if(this->y() > list[i]->y()) {
								flag1 = false;
								break;
							}
						}
						if(!flag1) break;
						up();
					}
				}

				//down
				list = collidingItems();
				if(list.empty()) {
					while (true) {
						down();
						list = collidingItems();
						if(!list.empty()) break;
					}
				}
			}
		}
    }

	else if(event->key() == Qt::Key_S && event->isAutoRepeat())
        changeState();
	else if(event->key() == Qt::Key_A && (!event->isAutoRepeat()))
	{

		list = collidingItems();
		if(list.empty()) {
			while(true){
				down();
				list = collidingItems();
				if(!list.empty()) break;
			}
		}
		else {
			bool flag = false;
			qDebug() <<  list.size();
			for(int i = 0; i < list.size(); i++) {
				if((this->y() == list[i]->y()) &&
					this->x() >= list[i]->x()){
					flag = true;
					break;
				}
			}
			if(!flag) {
				left();
			}
		}
	}
	else if(event->key() == Qt::Key_A && event->isAutoRepeat())
    {

		list = collidingItems();
		if(list.empty()) {
			while(true){
				down();
				list = collidingItems();
				if(!list.empty()) break;
			}
		}
		else {
			bool flag = false;
			for(int i = 0; i < list.size(); i++) {
				if((this->y() == list[i]->y()) &&
					this->x() >= list[i]->x()){
					flag = true;
					break;
				}
			}
			if(!flag) {
				left();
			}
		}
    }
	else if(event->key() == Qt::Key_D && (!event->isAutoRepeat()))
	{
		list = collidingItems();
		if(list.empty()) {
			while(true){
				down();
				list = collidingItems();
				if(!list.empty()) break;
			}
		}
		else {
			bool flag = false;
			for(int i =0 ; i < list.size(); i++) {
				if((this->x() <= list[i]->x()) &&
				   (this->y() == list[i]->y())) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				right();
			}
		}
	}
	else if(event->key() == Qt::Key_D && event->isAutoRepeat())
    {
		list = collidingItems();
		if(list.empty()) {
			while(true){
				down();
				list = collidingItems();
				if(!list.empty()) break;
			}
		}
		else {
			bool flag = false;
			for(int i =0 ; i < list.size(); i++) {
				if((this->x() <= list[i]->x()) &&
				   (this->y() == list[i]->y())) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				right();
			}
		}
    }
	else if(list.empty()){
		while(true){
			down();
			list = collidingItems();
			if(!list.empty()) break;
		}
	}

}

void mario::keyReleaseEvent(QKeyEvent *event)
{
	qDebug() << "key Release" << endl;
    if(event->key()==Qt::Key_Space && event->isAutoRepeat())
    {
        for(int i = 0;i <2000;i++)
        {
            moveBy(0,0.01);
        }
    }
    else if(event->key()==Qt::Key_S  && event->isAutoRepeat())
        moveBy(0,-20);
    else if(event->key()==Qt::Key_A)
        moveBy(20,0);
    else if(event->key()==Qt::Key_D)
        moveBy(-20,0);
}

void mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}

void mario::setColor(const QColor &color)
{
    Q_UNUSED(color);
}

void mario::up()
{
	moveBy(0, -2);
    QTime t;
    t.start();
	while(t.elapsed() < 3)
        QCoreApplication::processEvents();
}
void mario::down()
{
	moveBy(0, 2);
    QTime t;
    t.start();
	while(t.elapsed() < 3)
        QCoreApplication::processEvents();
}

void mario::left()
{
	moveBy(-5, 0);
    QTime t;
    t.start();
	while(t.elapsed() < 50)
        QCoreApplication::processEvents();
}

void mario::right()
{
	moveBy(5, 0);
    QTime t;
    t.start();
	while(t.elapsed() < 50)
        QCoreApplication::processEvents();
}

void mario::changeState()
{

}

/*void graphicsItem::upLeft()
{
    for(int i = 0;i <100;i++)
    {
        moveBy(2,-2);
        QTime t;
        t.start();
        while(t.elapsed()<10)
            QCoreApplication::processEvents();
    }
}

void graphicsItem::downLeft()
{
    for(int i = 0;i <100;i++)
    {
        moveBy(2,2);
        QTime t;
        t.start();
        while(t.elapsed()<10)
            QCoreApplication::processEvents();
    }
}*/
