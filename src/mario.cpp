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
    setFlag(QGraphicsItem::ItemIsFocusable);
	m_pix_one.load("src/Rwalk1.png");//初始状态是向右站着
    coins = 0;
    life = 5;
    jumpingTime = 0;
    start_y = 0;
    isJumping = false;
    isGoingLeft = false;
	isGoingRight = false;
	isDie = false;
    haveDead =false;


    //下面是动画内容

	QFile file("src/marioWalk.txt");//前两行是右，后两行是左
    if(file.open(QFile::ReadOnly))//打开存放图片文件名的txt文本文档，把文件名一行一行存到picList里
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            Walk.append(stream.readLine());
        }
        file.close();
    }
    connect(this,SIGNAL(haveCoin()),this,SLOT(coinSound()));
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(mario_timer()));
    timer->start(110);

    timerSound=new QTimer;
    connect(timerSound,SIGNAL(timeout()),this,SLOT(mario_sound()));
    timerSound->start(5000);

    timerDie=new QTimer;
    connect(timerDie,SIGNAL(timeout()),this,SLOT(die_timer()));


}

mario::~mario()
{
    delete timer;
    delete coin;
    delete timerSound;
    delete timerDie;
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


void mario::mario_timer()
{
    if(!isDie)
    {
        if(Walk.count()==0)
        {
            return;}

        static int Rgo=0,Lgo=4;
        if(isJumping)//先判断跳起状态
        {
            if(isGoingLeft)//向左跳
				m_pix_one=QPixmap("src/Ljump.png");
            else
				m_pix_one=QPixmap("src/Rjump.png");
        }
        if(tempX==x()&&tempY==y())
			m_pix_one=QPixmap("src/Rstand.png");

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
        if(Rgo>=4||Lgo>=8)
        {
            Rgo=0;
            Lgo=4;
        }
    }
    else
    {
		m_pix_one=QPixmap("src/Die.png");
        update();
    }
    if(isDie&&!haveDead)
    {
        haveDead=true;
        timerDie->start(10);
        timer->stop();
        if(this->y()>=700)
            dieSpeed=12;
        else if(this->y()>=500&&this->y()<700)
            dieSpeed=10;
        else if(this->y()>=400&&this->y()<500)
            dieSpeed=8;
        else if(this->y()>=0&&this->y()<400)
            dieSpeed=5;
    }
}
void mario::die_timer()
{
    if(!isDie)
        return;
    if(this->y()<=850)
    {
		if(true)
            //往下掉
        {
            this->moveBy(0,-(dieSpeed-0.098*i));
        }
    }
    else
    {
        timerDie->stop();
    }
    i++;
}


//下面是音效部分
void mario::coinSound()
{
	coin=new Sound("src/getCoin.mp3");
    temp[countPoint]=coin;
    countPoint++;
}

void mario::mario_sound()
{
    if(countPoint)
    {
        for(int i=countPoint;i<countPoint;i++)
            delete temp[i];
        countPoint=0;
    }

}
