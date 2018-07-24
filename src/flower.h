#ifndef FLOWER_H
#define FLOWER_H
#include <QGraphicsObject>
#include <QPixmap>
#include <QTimer>
class flower : public QGraphicsObject
{
    Q_OBJECT
public:
	flower();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setColor(const QColor &color);

    int getTime(){return time;}
    void setTime(int a){time = a;}

private:
	QPixmap m_pix_one;
    QStringList picList;//动画每张图片的列表
    QTimer *timer;//计时器
    int time;
    int cnt=0;

private slots:
    void flowerTimer();//计时器触发的槽函数

};

#endif // FLOWER_H
