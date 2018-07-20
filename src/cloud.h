#ifndef CLOUD_H
#define CLOUD_H
#include <QGraphicsObject>
#include <QPixmap>

class cloud : public QGraphicsObject
{
public:
	cloud();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // CLOUD_H
