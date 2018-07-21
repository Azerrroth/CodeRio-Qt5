#ifndef FLOWER_H
#define FLOWER_H
#include <QGraphicsObject>
#include <QPixmap>

class flower : public QGraphicsObject
{
public:
	flower();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // FLOWER_H
