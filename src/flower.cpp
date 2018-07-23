#include "flower.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsObject>

flower::flower()
{
	m_pix_one.load("flower.png");
    time = 0;
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
