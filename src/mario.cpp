#include "mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <iostream>
#include <QTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFont>
#include <QTextCodec>
#include <QtGui>


mario::mario(QGraphicsObject *parent)
    :QGraphicsObject (parent)
{
    qDebug() << "mario was created" << endl;
    setFlag(QGraphicsItem::ItemIsFocusable);
	m_pix_one.load("Rwalk1.png");//初始状态是向右站着
    coins = 0;
    life = 5;
    jumpingTime = 0;
    start_y = 0;
    isJumping = false;
    isGoingLeft = false;
    isGoingRight = false;
	isDie = false;


    //下面是动画内容

    QFile file("marioWalk.txt");//前两行是右，后两行是左
    if(file.open(QFile::ReadOnly))//打开存放图片文件名的txt文本文档，把文件名一行一行存到picList里
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            Walk.append(stream.readLine());
        }
        file.close();
    }
    else
    {
        qDebug()<<"no file was opened!!!"<<endl;
    }


    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(marioon_timer()));
	timer->start(110);

}

QRectF mario::boundingRect() const
{
    double penWidth = 1;
    return QRectF(7.5 - penWidth / 2, 0 - penWidth / 2, 36 + penWidth, 50 + penWidth);
}

void mario::setMove(qreal x, qreal y)
{
    move_x = x;
    move_y = y;
}

void mario::move() {
    moveBy(move_x, move_y);
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

//下面是动画部分---------------------


void mario::marioon_timer()
{
    if(Walk.count()==0)
	{
        return;}

    static int Rgo=0,Lgo=2;
    if(isJumping)//先判断跳起状态
    {
        if(isGoingLeft)//向左跳
            m_pix_one=QPixmap("Ljump.png");
        else
            m_pix_one=QPixmap("Rjump.png");
    }
    if(tempX==x()&&tempY==y())
        m_pix_one=QPixmap("Rstand.png");

    tempX=x();
    tempY=y();

    if(isGoingLeft&&!isGoingRight&&!isJumping)
    {
        m_pix_one=QPixmap(Walk[Lgo]);
        Lgo++;
    }
    else if(isGoingRight&&!isJumping)
    {
        m_pix_one=QPixmap(Walk[Rgo]);
        Rgo++;
    }

        update();
	if(Rgo>=4||Lgo>=4)
    {
        Rgo=0;
        Lgo=2;
    }
}
