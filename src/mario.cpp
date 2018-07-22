#include "mario.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <QCoreApplication>
#include <QTime>
#include <QDebug>

mario::mario(const QString pix_one)
{
    qDebug() << "mario was created" << endl;
    setFlag(QGraphicsItem::ItemIsFocusable);
    m_pix_one.load(pix_one);
    coins = 0;
    life = 5;
    jumpingTime = 0;
    start_y = 0;
    isJumping = false;
    isGoingLeft = false;
    isGoingRight = false;
}

QRectF mario::boundingRect() const
{
    double penWidth = 1;
    return QRectF(7.5 - penWidth / 2, 0 - penWidth / 2, 36 + penWidth, 50 + penWidth);
}

void mario::setMove(qreal x, qreal y)
{
    move_x = x;
    move_y = y;
}

void mario::move() {
    moveBy(move_x, move_y);
}

void mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pix_one);
}

void mario::setColor(const QColor &color)
{
    Q_UNUSED(color);
}

