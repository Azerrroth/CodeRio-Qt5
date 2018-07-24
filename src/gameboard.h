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
    inline void pushCoins(coins* coi) {coinlist.push_back(coi);}
    inline void pushQue(questionMark* que) {quelist.push_back(que);}
    inline void pushMushroom(mushroom* mos) {mushroomlist.push_back(mos);}
    inline void pushCloud(cloud* clo) {cloudlist.push_back(clo);}
    inline void pushMonster(monster* mon) {monsterlist.push_back(mon);}
    inline void pushFlower(flower* flo) {flowerlist.push_back(flo);}
    inline void pushStone(stone* sto){stonelist.append(sto);}
    inline void pushBase(baseblock* bas){baslist.append(bas);}
    inline void pushTube(tube* tub){tubelist.append(tub);}
    inline void pushBlock(blocks* blo){blocklist.append(blo);}


    //提供访问的接口
    inline QList<blocks*> getBlocks() {return blocklist;}
    inline QList<coins*> getCoins() {return coinlist;}
    inline QList<baseblock*> getBase() {return baslist;}
    inline QList<questionMark*> getQue() {return quelist;}
    inline QList<stone*> getStone() {return stonelist;}
    inline QList<cloud*> getCloud() {return cloudlist;}
    inline QList<monster*> getMonster() {return monsterlist;}
    inline QList<tube*> getTube() {return tubelist;}
    inline QList<mushroom*> getMushroom() {return mushroomlist;}
    inline QList<flower*> getFlower() {return flowerlist;}
	background* getBack() {return back;}
	mario* getMario() {return player;}
	flag* getFlag() {return fla;}

    bool isLeftcollider();				//判断马里奥左边的碰撞物是否影响了马里奥前进
    bool isRightcollider();				//判断马里奥右边的碰撞物是否影响了马里奥前进
    bool isUpcollider();				//判断马里奥上边的碰撞物是否影响了马里奥前进
    bool isDowncollider();				//判断马里奥下边的碰撞物是否影响了马里奥前进
	
	//以下是怪物碰撞的判断
	bool monisLeft(monster* mon);
	bool monisRight(monster* mon);
	bool monisDown(monster* mon);

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
};

#endif // GAMEBOARD_H
