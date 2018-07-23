#include "cloud.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsObject>

cloud::cloud()
{
	m_pix_one.load("cloud.png");
}

QRectF cloud::boundingRect() const {
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 199 + penwidth, 49 + penwidth);
}

void cloud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
