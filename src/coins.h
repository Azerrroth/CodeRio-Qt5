#ifndef COINS_H
#define COINS_H
#include <QGraphicsObject>


class coins : public QGraphicsObject
{
public:
	coins(const QString pix);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);

	//吃到金币后金币消失
	void remove();

private:
	QPixmap m_pix_one;
};

#endif // COINS_H
