#include "tube.h"
#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>

tube::tube(length type, bool rev)
{
	len = type;
	reverse = rev;
}

QRectF tube::boundingRect() const {
	double penwidth = 1;
	switch (len) {					//根据不同长短来返回不同大小矩形
	case Short:
		return QRect(0 - penwidth / 2, 0 - penwidth / 2,
					 49 + penwidth, 49 + penwidth);
		break;
	case Medium:
		return QRect(0 - penwidth / 2, 0 - penwidth / 2,
					 49 + penwidth, 99 + penwidth);
		break;
	case Long:
		return QRect(0 - penwidth / 2, 0 - penwidth / 2,
					 49 + penwidth, 199 + penwidth);
		break;
	default:
		break;
	}
}

void tube::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	switch (len) {
	case Short:
	{
		if(!reverse) m_pix_one.load("src/shortTube.png");
		else m_pix_one.load("src/_shortTube.png");
		break;
	}
	case Medium:
	{
		if(!reverse) m_pix_one.load("src/mediumTube.png");
		else m_pix_one.load("src/_mediumTube.png");
		break;
	}
	case Long:
	{
		if(!reverse) m_pix_one.load("src/longTube.png");
		else m_pix_one.load("src/_longTube.png");
		break;
	}
	default:
		break;
	}
	painter->drawPixmap(0, 0, m_pix_one);
}
