#ifndef STONE_H
#define STONE_H
#include <QGraphicsObject>
#include <QPixmap>


class stone : public QGraphicsObject
{
public:
	stone();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // STONE_H
