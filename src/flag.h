#ifndef FLAG_H
#define FLAG_H
#include <QGraphicsObject>
#include <QPixmap>

class flag : public QGraphicsObject
{
public:
	flag();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // FLAG_H
