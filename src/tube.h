#ifndef TUBE_H
#define TUBE_H
#include <QGraphicsObject>
#include <QPixmap>

enum length {Short, Medium, Long};	//管子长短类型

class tube : public QGraphicsObject
{
public:
	tube(length type, bool rev);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
private:
	length len;						//管子长短类型
	bool reverse;					//是否颠倒的管子，false为不倒置，true为倒置
	QPixmap m_pix_one;
};

#endif // TUBE_H
