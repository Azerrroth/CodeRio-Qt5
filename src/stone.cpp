#include "stone.h"
#include <QPixmap>
#include <QPainter>

stone::stone()
{
	m_pix_one.load("stone.png");
}

QRectF stone::boundingRect() const {
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 49 + penwidth, 49 + penwidth);
}

void stone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
