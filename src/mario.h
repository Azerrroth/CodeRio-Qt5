//--------------------------------------------------------------------------
//		该类是主人物类，通过继承于QGraphicsObject来实现图形的功能
//					move_x和move_y是移动坐标的增量
//			 只需要调用从基类继承而来的moveBy函数即可实现移动
//--------------------------------------------------------------------------

#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H
#include <QGraphicsObject>
#include <QPixmap>

class mario:public QGraphicsObject
{
public:
	mario(const QString pix);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(const QColor &color);
	void move();

	void setMove(qreal x, qreal y);

protected:


private:
    QPixmap m_pix_one;
	qreal move_x;
	qreal move_y;
    bool mPressFlag_Space;
    int m_count;
};
#endif // GRAPHICSITEM_H
