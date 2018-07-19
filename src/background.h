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
#include <QPixmap>

class background : public QGraphicsObject
{
public:
	background(const QString pix);
	//在类外因为不能访问private，故用一个公有的move()函数来调用moveBy()，实现在类外部移动
	void move();
	//设置位移的值
	void setMove(qreal x, qreal y);
	//在返回矩形时，返回一个大小为0的矩形，这样的话可以实现无论何时都不会视为碰撞
	//如果不能通过设置大小为0来避免碰撞的话，应该通过判断类型名称来避免
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QPixmap m_pix_one;
	qreal move_x;
	qreal move_y;
};

#endif // BACKGROUND_H
