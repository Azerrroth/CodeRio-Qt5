#include "questionmark.h"
#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>

questionMark::questionMark()
{
	m_pix_one.load("queblock.png");
	isHitted = false;
}

QRectF questionMark::boundingRect() const {
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 49 + penwidth, 49 + penwidth);
}

void questionMark::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
