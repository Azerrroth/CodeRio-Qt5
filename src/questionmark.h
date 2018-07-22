#ifndef QUESTIONMARK_H
#define QUESTIONMARK_H
#include <QGraphicsObject>
#include <QPixmap>

class questionMark : public QGraphicsObject
{
public:
	questionMark();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);
	bool getHit() {return isHitted;}
	void setHit(bool bo) {isHitted = bo;}
private:
	QPixmap m_pix_one;
	bool isHitted;		//是否被玛丽奥碰撞
};

#endif // QUESTIONMARK_H
