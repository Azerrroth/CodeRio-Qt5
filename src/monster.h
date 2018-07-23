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

    bool getGoingLeft() { return isGoingLeft; }
    bool getGoingRight() { return isGoingRight; }
    void setGoingLeft(bool a) { isGoingLeft = a; }
    void setGoingRight(bool a) { isGoingRight = a; }

private:
	QPixmap m_pix_one;

    bool isGoingLeft;
    bool isGoingRight;
};

#endif // MONSTER_H
