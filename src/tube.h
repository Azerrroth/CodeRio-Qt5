#ifndef TUBE_H
#define TUBE_H
#include <QGraphicsObject>
#include <QPixmap>

enum length {Short, Medium, Long};//管子长短类型

class tube : public QGraphicsObject
{
public:
	tube(length type);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	length len;
	QPixmap m_pix_one;
};

#endif // TUBE_H
