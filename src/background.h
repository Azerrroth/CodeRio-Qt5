//--------------------------------------------------------------------------
//		该类是背景类，通过继承于QGraphicsObject来实现图形的功能
//					move_x和move_y是移动坐标的增量
//				因为场景的移动实际上只有x方向上的移动
//						所以一般move_y都为0
//			 只需要调用从基类继承而来的moveBy函数即可实现移动
//--------------------------------------------------------------------------

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QGraphicsObject>

class background : public QGraphicsObject
{
public:
	background(const QString pix);
	void move();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
	qreal move_x;
	qreal move_y;
};

#endif // BACKGROUND_H
