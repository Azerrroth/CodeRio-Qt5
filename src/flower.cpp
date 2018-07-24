#include "flower.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsObject>

flower::flower()
{
    m_pix_one.load("flower1.png");
    time = 0;
    picList.append("flower1.png");
    picList.append("flower2.png");

    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(flowerTimer()));
    timer->start(500);

}

QRectF flower::boundingRect() const {
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 49 + penwidth, 49 + penwidth);
}

void flower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}

void flower::flowerTimer()
{
    m_pix_one=QPixmap(picList[cnt]);
    cnt++;
    update();
    if(cnt>=picList.count())
        cnt=0;
}
