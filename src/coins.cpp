#include "coins.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <QCoreApplication>
#include <QTime>
#include <QDebug>


coins::coins(const QString pix_one)
{
	m_pix_one.load(pix_one);
}

QRectF coins::boundingRect() const {
	double penwidth = 1;
	return QRect(0 - penwidth / 2, 0 - penwidth / 2,
				 48 + penwidth, 48 + penwidth);
}

void coins::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, m_pix_one);
}
