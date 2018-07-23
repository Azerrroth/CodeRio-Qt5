#ifndef FLOWER_H
#define FLOWER_H
#include <QGraphicsObject>
#include <QPixmap>

class flower : public QGraphicsObject
{
public:
	flower();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);

    int getTime(){return time;}
    void setTime(int a){time = a;}

private:
	QPixmap m_pix_one;
    int time;
};

#endif // FLOWER_H
