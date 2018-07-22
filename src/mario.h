//--------------------------------------------------------------------------
//		该类是主人物类，通过继承于QGraphicsObject来实现图形的功能
//					move_x和move_y是移动坐标的增量
//			 只需要调用从基类继承而来的moveBy函数即可实现移动
//--------------------------------------------------------------------------

#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H
#include <QGraphicsObject>

class mario: public QGraphicsObject
{
    Q_OBJECT
public:
    mario(QGraphicsObject *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(const QColor &color);

    void move();                            //在类外因为不能访问private，故用一个公有的move()函数来调用moveBy()，实现在类外部移
    void setMove(qreal x, qreal y);             //设置位移的值

    bool getGoingLeft() { return isGoingLeft; }         //给gameboard中的moveMario提供一个接口，判断是否发出往左的指令
    bool getGoingRight() { return isGoingRight; }       //给gameboard中的moveMario提供一个接口，判断是否发出往右的指令
    bool getJumping() { return isJumping; }             //给gameboard中的moveMario提供一个接口，判断是否发出往右的指令

    void setGoingLeft(bool a) { isGoingLeft = a; }      //给gameboard中的moveMario提供一个接口，改变isGoingLeft的值
    void setGoingRight(bool a) { isGoingRight = a; }    //给gameboard中的moveMario提供一个接口，改变isGoingRight的值
    void setJumping(bool a) { isJumping = a; }          //给gameboard中的moveMario提供一个接口，改变isJumping的值

    int getJumpingTime(){ return jumpingTime; }
    void setJumpingTime(int a) { jumpingTime = a; }

    int getStart_y() { return start_y; }
    void setStart_y(int a) { start_y = a; }

protected:


private:
    QPixmap m_pix_one;
    qreal move_x;
    qreal move_y;

    int coins;      //金币
    int life;       //生命

    bool isJumping;             //判断是否跳起的状态
    bool isGoingLeft;           //判断是否往左
    bool isGoingRight;          //判断是否往右

    int jumpingTime;
    int start_y;

    //下面是关于动画的
    QStringList Walk;
    QTimer *timer;//计时器

private slots:
    void marioon_timer();
};
#endif // GRAPHICSITEM_H
