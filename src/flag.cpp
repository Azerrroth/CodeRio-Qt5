#include "flag.h"
#include <QPixmap>
#include <QPainter>

flag::flag()
{
	m_pix_one.load("flag.png");
}

QRectF flag::boundingRect() const
{
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 49 + penwidth, 498 + penwidth);
}

void flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
