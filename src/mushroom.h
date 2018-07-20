#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <QGraphicsObject>
#include <QPixmap>

class mushroom : public QGraphicsObject
{
public:
	mushroom();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
	bool isHitted;
};

#endif // MUSHROOM_H
