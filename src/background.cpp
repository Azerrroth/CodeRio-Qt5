#include "background.h"

background::background(const QString pix)
{
	m_pix_one.load(pix_one);
}


void background::move() {
	moveBy(move_x, move_y);
}

QRectF background::boundingRect() const {
	return QRectF(0, 0, 0, 0);			//我们不希望背景与mario碰撞，因此把返回的矩设为0
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
