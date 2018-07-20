#include "tube.h"
#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>

tube::tube(length type)
{
	len = type;
}

QRectF tube::boundingRect() const {
	double penwidth = 1;
	switch (len) {
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
		m_pix_one.load("shortTube.png");
		break;
	case Medium:
		m_pix_one.load("mediumTube.png");
		break;
	case Long:
		m_pix_one.load("longTube.png");
		break;
	default:
		break;
	}
	painter->drawPixmap(0, 0, m_pix_one);
}
