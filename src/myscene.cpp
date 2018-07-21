#include "myscene.h"
#include "view.h"
#include "flag.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <QDebug>

using std::fstream;
using std::string;

MyScene::MyScene()
{
    //vie = new view;
    //addItem(vie);
    //vie->setPos(0, 0);
    timerId = startTimer(15);	//开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称
    pos_x = 0;
    isMoving = false;
    control=new GameBoard;
    initialize();
    setSceneRect(0, 0, 1450, 800);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(refresh()));
    timer->start(3);

}

void MyScene::refresh()
{
    update();
    advance();
}

void MyScene::initialize()
{
    addItem(getControl()->getBack());
    getControl()->getBack()->setPos(0, 0);
    getControl()->getBack()->setZValue(-100);

    addItem(getControl()->getMario());
    getControl()->getMario()->setPos(100, 650);

	addItem(getControl()->getFlag());
	getControl()->getFlag()->setPos(21150, 150);

    {
        coins* coi = new coins;
        this->addItem(coi);
        coi->setPos(200, -200000);
        getControl()->getCoins().push_back(coi);
    }

    fstream in("info.txt");
    string str;
    while (getline(in, str))
    {
        int x = atoi(const_cast<char*>(str.substr(3, 5).c_str()));
        int y = atoi(const_cast<char*>(str.substr(8, 3).c_str()));

        if(str.substr(0, 3) == "BLO")
        {
            blocks* blo = new blocks;
            this->addItem(blo);
            blo->setPos(x, y);
            getControl()->getBlocks().push_back(blo);
        }
        else if(str.substr(0,3) == "COI")
        {
            coins* coi = new coins;
            this->addItem(coi);
            coi->setPos(x, y);
            getControl()->getCoins().push_back(coi);
        }
        else if(str.substr(0, 3) == "MON")
        {
			monster* mon = new monster;
			this->addItem(mon);
			mon->setPos(x, y);
			getControl()->getMonster().push_back(mon);
        }

        else if(str.substr(0, 3) == "MUS")
        {
			mushroom* mus = new mushroom;
			this->addItem(mus);
			mus->setPos(x, y);
			getControl()->getMushroom().push_back(mus);
        }
		else if(str.substr(0, 3) == "CLO")
        {
			cloud* clo = new cloud;
			this->addItem(clo);
			clo->setPos(x, y);
			getControl()->getCloud().push_back(clo);
        }
		else if(str.substr(0, 3) == "STO")
		{
			stone* sto = new stone;
			this->addItem(sto);
			sto->setPos(x, y);
			getControl()->getStone().push_back(sto);
		}
		else if(str.substr(0, 3) == "QUE")
		{
			questionMark* que = new questionMark;
			this->addItem(que);
			que->setPos(x, y);
			getControl()->getQue().push_back(que);
		}
		else if(str.substr(0, 3) == "BAS")
		{
			baseblock* bas = new baseblock;
			this->addItem(bas);
			bas->setPos(x, y);
			getControl()->getBase().push_back(bas);
		}
		else if(str[0] == 'T')
		{
			if(str[1] == 'T')
			{
				if(str[2] == 'S')
				{
					tube* tub = new tube(Short, true);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
				else if(str[2] == 'M')
				{
					tube* tub = new tube(Medium, true);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
				else if(str[2] == 'L')
				{
					tube* tub = new tube(Long, true);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
			}
			else if(str[1] == 'F')
			{
				if(str[2] == 'S')
				{
					tube* tub = new tube(Short, false);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
				else if(str[2] == 'M')
				{
					tube* tub = new tube(Medium, false);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
				else if(str[2] == 'L')
				{
					tube* tub = new tube(Long, false);
					this->addItem(tub);
					tub->setPos(x, y);
					getControl()->getTube().push_back(tub);
				}
			}
		}
		else if(str.substr(0, 3) == "FLO")
		{
			flower* flo = new flower;
			this->addItem(flo);
			flo->setPos(x, y);
			getControl()->getFlower().push_back(flo);
		}
		else if(str.substr(0, 3) == "FLA")
		{

		}
    }
}
void MyScene::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "key" << endl;
    QList<QGraphicsItem*>list = control->getMario()->collidingItems();

    if(control->getMario()->x() > pos_x && control->getMario()->x() < pos_x + 500)
    {
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(true);           //只需要在按下时候改变右走状态的布尔值，而判断碰撞物在moveMario里面
        }
        else if(event->key() == Qt::Key_A)
        {
            if(control->getMario()->x() >= 0)                   //马里奥必须不能出场景
            {
                control->getMario()->setGoingLeft(true);        //只需要在按下时候改变左走状态的布尔值，而判断碰撞物在moveMario里面
            }
        }
        else if(event->key() == Qt::Key_Space)      //改变布尔值，跳起来判断为isJumping = true
        {
            if(control->isDowncollider())           //在下方有东西的时候才能跳
            {
                control->getMario()->setJumping(true);
            }
        }
    }
    else if(control->getMario()->x() <= pos_x)
    {
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(true);
        }
    }
    else if(control->getMario()->x() >= pos_x + 500)                                           //场景移动还未写
    {
        qDebug() << "set";                      //调试信息
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(true);
            isMoving = true;
        }
        else if(event->key() == Qt::Key_A)
        {
            isMoving = false;
            control->getMario()->setGoingLeft(true);
        }
        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
                                                    //7.21 18：13分更新：或许可以使用isJumping，因为机制与预想的已经不同了
        {

        }
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if(control->getMario()->x() > pos_x && control->getMario()->x() < pos_x + 500)
    {
        if(event->key() == Qt::Key_Space)           //留个空槽，这个暂时没用
        {

        }
        else if(event->key() == Qt::Key_A)          //松开a键传停止左走的信号
        {
            control->getMario()->setGoingLeft(false);
        }
        else if(event->key() == Qt::Key_D)          //松开d键传停止右走的信号
        {
            control->getMario()->setGoingRight(false);
        }
    }
    else if(control->getMario()->x() <= pos_x)
    {
        if(event->key() == Qt::Key_D)
        {
            control->getMario()->setGoingRight(false);
        }
    }
    else if(control->getMario()->x() >= pos_x + 500)                                           //和移动场景相关的
    {
        qDebug() << "unset";            //调试信息
        if(event->key() == Qt::Key_D)
        { 
            control->getMario()->setGoingRight(false);
            isMoving = false;
        }
        else if(event->key() == Qt::Key_A)
        {
            control->getMario()->setGoingLeft(false);
        }
        else if(event->key() == Qt::Key_Space)      //这个不能改变isJumping，否则会出现马里奥斜跳和场景移动同时出现的状况
                                                    //7.21 18：13分更新：或许可以使用isJumping，因为机制与预想的已经不同了
        {

        }
    }
}

void MyScene::timerEvent(QTimerEvent *event)                //timerevent改动到了这里
{
    Q_UNUSED(event);
    if(control->getMario()->x() <= 0) { control->getMario()->setGoingLeft(false); }
    control->getBack()->update();
    control->moveMario();
    moveView();
}

void MyScene::moveView()                                    //场景移动相关函数
{
    if(isMoving)
    {
        qDebug() << "moveView";                             //调试信息
        pos_x += 2;
        setSceneRect(pos_x,0,1450,800);
        int temp = pos_x;
        control->getBack()->setPos(temp,0);
    }
}
