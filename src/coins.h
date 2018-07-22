#ifndef COINS_H
#define COINS_H
#include <QGraphicsObject>

class coins : public QGraphicsObject
{
    Q_OBJECT

public:
    coins(QGraphicsObject *parent=nullptr);
    ~coins();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    inline bool getCoinExist(){return coinExist;}//看金币是不是还存在
	void setExist() {coinExist = false;}

    //吃到金币后金币消失
    void remove();

private:
    QPixmap m_pix_one;
    QStringList picList;//动画每张图片的列表
    QTimer *timer;//计时器
	bool coinExist;

private slots:
    void on_timer();//计时器触发的槽函数
};

#endif // COINS_H
