#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsObject>
#include <QPixmap>

class monster : public QGraphicsObject
{
public:
	monster();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	QPixmap m_pix_one;
};

#endif // MONSTER_H
