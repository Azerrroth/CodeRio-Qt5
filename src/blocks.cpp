#include "blocks.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <QCoreApplication>
#include <QTime>
#include <QDebug>

blocks::blocks(const QString pix_one) {
    m_pix_one.load(pix_one);
}

QRectF blocks::boundingRect() const {
    double penwidth = 1;
    return QRect(0 - penwidth / 2, 0 - penwidth / 2,
                 49 + penwidth, 49 + penwidth);
}

void blocks::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pix_one);
}

void blocks::move(){
    moveBy(move_x, move_y);
}
