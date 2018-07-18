//----------------------------------------------------------------------------
//							该类是控制键盘事件类
//					所有相关的键盘事件函数都会在下方声明
//							该类继承自QWidget
//				通过内部的GameBoard指针操作场景内容的变化
//---------------------------------------------------------------------------
#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "gameboard.h"

class GameBoard;

class view : public QWidget
{
	Q_OBJECT
public:
	explicit view(QWidget *parent = nullptr);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	GameBoard* control;
	void keyPressEvent(QKeyEvent* event);
};

#endif // VIEW_H
