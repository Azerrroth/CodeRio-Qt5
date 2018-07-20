#ifndef BASEBLOCK_H
#define BASEBLOCK_H
#include <QGraphicsObject>
#include <QPixmap>

class baseblock : public QGraphicsObject
{
public:
	baseblock();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // BASEBLOCK_H
