#include "coins.h"
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


coins::coins(QGraphicsObject *parent)
    :QGraphicsObject(parent)
{
    QFile file("coin.txt");
    if(file.open(QFile::ReadOnly))//打开存放图片文件名的txt文本文档，把文件名一行一行存到picList里
    {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            picList.append(stream.readLine());
        }
        file.close();
    }
    else
    {
        qDebug()<<"no file was opened!!!"<<endl;
    }
    timer=new QTimer;
	coinExist = true;
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer()));
    timer->start(100);

}

coins::~coins()
{
    delete timer;
}

void coins::on_timer()//timer计时器出发的槽函数
{
    if(picList.count()==0)
    {
        return;
    }
    if(!coinExist)
        remove();
    static int cnt=0;
    m_pix_one=QPixmap(picList[cnt]);
    cnt++;
    update();
    if(cnt>=picList.count())
        cnt=0;
}

void coins::remove()//金币被吃以后消失
{
    m_pix_one=QPixmap("");
    update();
    timer->stop();
}

void coins::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 10, m_pix_one);
}


QRectF coins::boundingRect() const
{
    double penwidth = 1;
	if(coinExist) return QRect(0 - penwidth / 2, 0 - penwidth / 2,
							   48 + penwidth, 48 + penwidth);
	else return QRect(0, 0, 0, 0);

}


