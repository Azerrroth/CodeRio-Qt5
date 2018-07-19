//--------------------------------------------------------------------------
//		该类是方块障碍物类，通过继承于QGraphicsObject来实现图形的功能
//					move_x和move_y是移动坐标的增量
//			 只需要调用从基类继承而来的moveBy函数即可实现移动
//--------------------------------------------------------------------------

#ifndef BLOCKS_H
#define BLOCKS_H
#include <QGraphicsObject>

class blocks : public QGraphicsObject
{
public:
	blocks(const QString pix);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);

	//在类外因为不能访问private，故用一个公有的move()函数来调用moveBy()，实现在类外部移动
	void move();
	//设置位移的值
	void setMove(qreal x, qreal y);

private:
	QPixmap m_pix_one;
	qreal move_x;
	qreal move_y;
};

#endif // BLOCKS_H
