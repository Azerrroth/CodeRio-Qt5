//----------------------------------------------------------------------------
//		该类来管理场景中所有的类的实例对象，初始化，移动都会在该类中集成
//		同时也包含一个QTimer以及timeEvent函数，以实现实时刷新的功能
//		通过指针来操作mario，一系列blocks，以及background类的对象
//----------------------------------------------------------------------------

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "blocks.h"
#include "mario.h"
#include "background.h"
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QObject>
#include <QString>


class mario;
class blocs;
class background;

class GameBoard : public QObject
{
	Q_OBJECT
public:
	explicit GameBoard(QObject *parent = nullptr);

	void setBlock(const QString file, qreal pos_x, qreal pos_y);
	void moveView();//该函数移动除了马里奥之外的内容，包括背景及障碍物
	void moveMario();//该函数移动马里奥

	mario* getMario() {return player;}
	QVector<blocks*> getBlocks() {return blocklist;}
	background* getBack() {return back;}

private:
	mario* player;
	QVector<blocks*> blocklist;
	background* back;
	int timerId;

	void timerEvent(QTimerEvent* event);
};

#endif // GAMEBOARD_H
