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
	void move();

private:
	QPixmap m_pix_one;
	qreal move_x;
	qreal move_y;
};

#endif // BLOCKS_H
