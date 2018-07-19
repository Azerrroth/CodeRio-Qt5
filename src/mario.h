//--------------------------------------------------------------------------
//		该类是主人物类，通过继承于QGraphicsObject来实现图形的功能
//					move_x和move_y是移动坐标的增量
//			 只需要调用从基类继承而来的moveBy函数即可实现移动
//--------------------------------------------------------------------------

#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H
#include <QGraphicsObject>
#include <QPixmap>

class mario: public QGraphicsObject
{
public:
	mario(const QString pix = "mario.png");
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setColor(const QColor &color);

    void move();                            //在类外因为不能访问private，故用一个公有的move()函数来调用moveBy()，实现在类外部移
    void setMove(qreal x, qreal y);             //设置位移的值

    bool getGoingLeft() { return isGoingLeft; }         //给gameboard中的moveMario提供一个接口，判断是否发出往左的指令
    bool getGoingRight() { return isGoingRight; }       //给gameboard中的moveMario提供一个接口，判断是否发出往右的指令
    bool getJumping() { return isJumping; }             //给gameboard中的moveMario提供一个接口，判断是否发出往右的指令

    bool setGoingLeft(bool a) { isGoingLeft = a; }      //给gameboard中的moveMario提供一个接口，改变isGoingLeft的值
    bool setGoingRight(bool a) { isGoingRight = a; }    //给gameboard中的moveMario提供一个接口，改变isGoingRight的值
    bool setJumping(bool a) { isJumping = a; }          //给gameboard中的moveMario提供一个接口，改变isJumping的值

    void set_start_x(int a) { start_x = a;}             //从这往下到get_y_Relative()都是跳跃相关数值获取和设定
    void set_start_y(int a) { start_y = a;}

    int get_start_x() { return start_x; }
    int get_start_y() { return start_y; }

    void set_x_Relative(int a) { x_Relative = a; }
    void set_y_Relative(int a) { y_Relative = a; }

    int get_x_Relative() { return x_Relative; }
    int get_y_Relayive() { return y_Relative; }

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

    int start_x;                //以下四个变量都是跳跃相关变量
    int start_y;
    int x_Relative;
    int y_Relative;

};
#endif // GRAPHICSITEM_H
