////----------------------------------------------------------------------------
////							该类是控制键盘事件类
////					所有相关的键盘事件函数都会在下方声明
////							该类继承自QWidget
////				通过内部的GameBoard指针操作场景内容的变化
////---------------------------------------------------------------------------
//#ifndef VIEW_H
//#define VIEW_H

//#include "globalapplication.h"
//#include <QWidget>
//#include <QKeyEvent>
//#include <QGraphicsObject>
//#include <QGraphicsView>
//#include "gameboard.h"
//class GameBoard;

//class view : public QGraphicsObject
//{
//    Q_OBJECT
//public:
//    explicit view();
//    GameBoard* getControl() { return control; }
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);private:
//    //实现左移右移的时候注意Mario若在0~300像素范围内金仅移动Mario
//    //超出了相应坐标后，移动场景及其他物体的x坐标，而仅移动Mario的y坐标
//    //这样就能实现场景游动的效果

//    void keyPressEvent(QKeyEvent* event);
//    void keyReleaseEvent(QKeyEvent* event);

//private:
//    GameBoard* control;
//};

//#endif // VIEW_H
