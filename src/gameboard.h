//----------------------------------------------------------------------------
//		该类来管理场景中所有的类的实例对象，初始化，移动都会在该类中集成
//		同时也包含一个QTimer以及timeEvent函数，以实现实时刷新的功能
//		通过指针来操作mario，一系列blocks，以及background类的对象
//----------------------------------------------------------------------------

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "blocks.h"
#include "mario.h"
#include "coins.h"
#include "background.h"
#include "baseblock.h"
#include "questionmark.h"
#include "stone.h"
#include "monster.h"
#include "cloud.h"
#include "tube.h"
#include "flower.h"
#include "mushroom.h"
#include "flag.h"
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QList>
#include <string>
#include <vector>
using std::vector;
using std::string;

//枚举类型，标志着碰撞体的类型
enum colliderType
{
	Block,
	Boin,
	Mushroom,
	Flag,
	Monster,
	Turtles
};


class mario;
class blocks;
class background;

class GameBoard : public QObject
{
    Q_OBJECT
public:
    explicit GameBoard(QObject *parent = nullptr);



    void moveView();	//该函数移动除了马里奥之外的内容，包括背景及障碍物
    void moveMario();	//该函数移动马里奥
	void moveMonster();	//移动怪物

	//以下的几个函数是为了在MyScene中初始化用的，直接用get函数不能push进去，必须重新实现一个push
	void pushCoins(coins* coi) {coinlist.push_back(coi);}
	void pushQue(questionMark* que) {quelist.push_back(que);}
	void pushMushroom(mushroom* mos) {mushroomlist.push_back(mos);}
	void pushCloud(cloud* clo) {cloudlist.push_back(clo);}
	void pushMonster(monster* mon) {monsterlist.push_back(mon);}
	void pushFlower(flower* flo) {flowerlist.push_back(flo);}

	//提供访问的接口
	QList<blocks*> getBlocks() {return blocklist;}
	QList<coins*> getCoins() {return coinlist;}
	QList<baseblock*> getBase() {return baslist;}
	QList<questionMark*> getQue() {return quelist;}
	QList<stone*> getStone() {return stonelist;}
	QList<cloud*> getCloud() {return cloudlist;}
	QList<monster*> getMonster() {return monsterlist;}
	QList<tube*> getTube() {return tubelist;}
	QList<mushroom*> getMushroom() {return mushroomlist;}
	QList<flower*> getFlower() {return flowerlist;}
	background* getBack() {return back;}
	mario* getMario() {return player;}
	flag* getFlag() {return fla;}

    bool isLeftcollider();				//判断马里奥左边的碰撞物是否影响了马里奥前进
    bool isRightcollider();				//判断马里奥右边的碰撞物是否影响了马里奥前进
    bool isUpcollider();				//判断马里奥上边的碰撞物是否影响了马里奥前进
    bool isDowncollider();				//判断马里奥下边的碰撞物是否影响了马里奥前进
	
	//以下是怪物碰撞的判断，刚开始没想好，早知道里边应该加参数的。。。
	bool monisLeft(monster* mon);
	bool monisRight(monster* mon);
	bool monisDown(monster* mon);

    colliderType colType();				//返回与马里奥碰撞体的类名的函数

private:


	mario* player;
	background* back;
	flag* fla;
	//有一系列的障碍方块，故要用vector
	QList<blocks*> blocklist;
	QList<coins*> coinlist;
	QList<baseblock*> baslist;
	QList<questionMark*> quelist;
	QList<stone*> stonelist;
	QList<monster*> monsterlist;
	QList<cloud*> cloudlist;
	QList<tube*> tubelist;
	QList<mushroom*> mushroomlist;
	QList<flower*> flowerlist;
    //计时器，在构造函数中创建QTimer时把相应的值赋给它

    //int timerId;                          //暂时取消

    //把那些移动的操作都放在timeEvent实现
    //并且在该函数内部同时实现如果没有碰撞体就下落的功能

    //void timerEvent(QTimerEvent* event);                      //暂时取消

    //该函数应该在构造函数中调用，通过读取一个txt文件从而把所有的blocks和其他的内容初始化
    //并且同时把这些内容的位置确定
    //完成setPos操作
    void setItems(string file);
};

#endif // GAMEBOARD_H
