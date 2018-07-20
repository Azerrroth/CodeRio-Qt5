#include "baseblock.h"
#include <QPainter>
baseblock::baseblock()
{
	m_pix_one.load("baseblock.png");
}

QRectF baseblock::boundingRect() const
{
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 49 + penwidth, 99 + penwidth);
}

void baseblock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
