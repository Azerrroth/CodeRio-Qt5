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

//枚举类型，标志着碰撞体的类型
enum colliderType
{
	blocks,
	coins,
	mushrooms,
	flag,
	monsters,
	turtles
};


class mario;
class blocs;
class background;

class GameBoard : public QObject
{
	Q_OBJECT
public:
	explicit GameBoard(QObject *parent = nullptr);

	//该函数应该在主函数中调用，通过读取一个txt文件从而把所有的blocks和其他的内容初始化
	//并且同时把这些内容的位置确定
	//完成setPos操作
	void setBlock(const QString file, qreal pos_x, qreal pos_y);

	void moveView();	//该函数移动除了马里奥之外的内容，包括背景及障碍物
	void moveMario();	//该函数移动马里奥

	mario* getMario() {return player;}
	QVector<blocks*> getBlocks() {return blocklist;}
	background* getBack() {return back;}

	bool isLeftcollider();				//判断马里奥左边的碰撞物是否影响了马里奥前进
	bool isRightcollider();				//判断马里奥右边的碰撞物是否影响了马里奥前进
	bool isUpcollider();				//判断马里奥上边的碰撞物是否影响了马里奥前进
	bool isDowncollider();				//判断马里奥下边的碰撞物是否影响了马里奥前进

	colliderType colType();				//返回与马里奥碰撞体的类名的函数

private:

	mario* player;

	//有一系列的障碍方块，故要用vector
	QVector<blocks*> blocklist;
	background* back;

	//计时器，在构造函数中创建QTimer时把相应的值赋给它
	int timerId;

	//把那些移动的操作都放在timeEvent实现
	//并且在该函数内部同时实现如果没有碰撞体就下落的功能
	void timerEvent(QTimerEvent* event);
};

#endif // GAMEBOARD_H
