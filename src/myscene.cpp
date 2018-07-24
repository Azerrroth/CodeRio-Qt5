#include "myscene.h"
#include "view.h"
#include "flag.h"
#include "sound.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <QDebug>
using std::fstream;
using std::string;

MyScene::MyScene()
{
    //    PushButton* item=new PushButton(this);
    //    item->setText("This is just a test Button");
    //    item->setGeometry(50,50,100,50);
    //    item->show();

    //vie = new view;
    //addItem(vie);
    //vie->setPos(0, 0);
    timerId = startTimer(5);	//开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称
	pos_x = 0;
    isMoving = false;
    control=new GameBoard;
    initialize();
	setSceneRect(0, 0, 1450, 800);

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(refresh()));
    timer->start(3);

}

void MyScene::spcialDie()
{
	if(getControl()->getMario()->y() >= 850)
		getControl()->getMario()->setDie(true);
	else if(getControl()->getMario()->y() <= 45);
	QList<QGraphicsItem*> list = getControl()->getMario()->collidingItems();
	for(int i = 0; i < list.size(); i++)
	{
		if(QString(typeid(*list.at(i)).name()) == "6flower" ||
		   QString(typeid(*list.at(i)).name()) == "7monster")
		{
			getControl()->getMario()->setDie(true);
			break;
		}
	}
}

void MyScene::removeCoins()
{
	for(int i = 0; i < getControl()->getCoins().size(); i++)
	{
		if(getControl()->getCoins().at(i)->x() >= pos_x &&
		   getControl()->getCoins().at(i)->x() <= pos_x + 1450)
		{
			QList<QGraphicsItem*> list =
					getControl()->getCoins().at(i)->collidingItems();
			if(!list.isEmpty())
			{
				for(int j = 0; j < list.size(); j++)
				{
					if(QString(typeid(*list.at(j)).name()) == "5mario")
					{
						getControl()->getCoins().at(i)->remove();
						getControl()->getCoins().at(i)->setExist();
                        //delete getControl()->getCoins().at(i);
						getControl()->getMario()->addCoinNum();
						break;
					}
				}
			}
		}
	}
}

void MyScene::judgeQue()
{
	for(int i = 0; i < getControl()->getQue().size(); i++)
	{
		if(getControl()->getQue().at(i)->x() >= pos_x &&
		   getControl()->getQue().at(i)->x() <= pos_x + 1450)
		{
			QList<QGraphicsItem*> list =
					getControl()->getQue().at(i)->collidingItems();
			if(!list.empty())
			{
				for(int j = 0; j < list.size(); j++)
				{
					if(getControl()->getQue().at(i)->getHit()) continue;
					if(QString(typeid(*list.at(j)).name()) == "5mario" &&
					   getControl()->getMario()->y() ==
					   getControl()->getQue().at(i)->y() + 50)
					{
						getControl()->getQue().at(i)->change();
						if(!getControl()->getQue().at(i)->getHit())
						{
							getControl()->getMario()->addCoinNum();//addCoinNubmer
							getControl()->getQue().at(i)->setHit(true);
							//下边写相应操作
						}

						if(getControl()->getQue().at(i)->x() == 450 &&			//杨添凯的骚操作
						   getControl()->getMario()->y() ==
						   getControl()->getQue().at(i)->y() + 50)
						{
							stone* t1 = new stone;
							stone* t2 = new stone;
							stone* t3 = new stone;
							stone* t4 = new stone;

							this->addItem(t1);
							this->addItem(t2);
							this->addItem(t3);
							this->addItem(t4);
							t1->setPos(1100, 500);
							t2->setPos(1150, 500);
							t3->setPos(500, 500);
							t4->setPos(550, 500);
						}
						else if(getControl()->getQue().at(i)->x() == 3100 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							monster* t2 = new monster;
							this->addItem(t1);
							this->addItem(t2);
							t1->setPos(3045, 555);
							t2->setPos(3155, 555);
							getControl()->pushMonster(t1);
							getControl()->pushMonster(t2);
						}
						else if(getControl()->getQue().at(i)->x() == 5500 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							this->addItem(t1);
							t1->setPos(5500, 550);
							getControl()->pushMonster(t1);
						}
						else if(getControl()->getQue().at(i)->x() == 5650 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							this->addItem(t1);
							t1->setPos(5650, 550);
							getControl()->pushMonster(t1);
						}
						else if(getControl()->getQue().at(i)->x() == 5550 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							this ->addItem(t1);
							t1->setPos(5550, 350);
						}
						else if(getControl()->getQue().at(i)->x() == 5600 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							this->addItem(t1);
							t1->setPos(5600, 350);
							getControl()->pushMonster(t1);
						}
						else if(getControl()->getQue().at(i)->x() == 6200 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							this->addItem(t1);
							t1->setPos(6150, 550);
							getControl()->pushMonster(t1);
						}
						else if(getControl()->getQue().at(i)->x() == 6300 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							stone* t1 = new stone;
							this->addItem(t1);
							t1->setPos(6350, 500);
							stone* t2 = new stone;
							this->addItem(t2);
							t2->setPos(6400, 500);
							stone* t3 = new stone;
							this->addItem(t3);
							t3->setPos(6450, 500);
							stone* t4 = new stone;
							this->addItem(t4);
							t4->setPos(6350, 500);
						}
						else if(getControl()->getQue().at(i)->x() == 6650 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							monster* t1 = new monster;
							monster* t2 = new monster;
							this->addItem(t1);
							this->addItem(t2);
							t1->setPos(6600, 550);
							t2->setPos(6700, 550);
							getControl()->pushMonster(t1);
							getControl()->pushMonster(t2);
						}
						else if(getControl()->getQue().at(i)->x() == 12600 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							fstream in("special.txt");
							string str;
							while (getline(in, str))
							{
								int x = atoi(const_cast<char*>(str.substr(3, 5).c_str()));
								int y = atoi(const_cast<char*>(str.substr(8, 3).c_str()));
								blocks* blo = new blocks;
								this->addItem(blo);
								blo->setPos(x, y);
							}
						}
						else if(getControl()->getQue().at(i)->x() == 12400 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							stone* t1 = new stone;
							this->addItem(t1);
							t1->setPos(12450, 500);
						}
						else if(getControl()->getQue().at(i)->x() == 12900 &&
								getControl()->getMario()->y() >=
								getControl()->getQue().at(i)->y() + 50)
						{
							stone* t1 = new stone;
							stone* t2 = new stone;
							stone* t3 = new stone;
							stone* t4 = new stone;
							stone* t5 = new stone;
							stone* t6 = new stone;
							this->addItem(t1);
							this->addItem(t2);
							this->addItem(t3);
							this->addItem(t4);
							this->addItem(t5);
							this->addItem(t6);
							t1->setPos(12800, 350);
							t2->setPos(12800, 400);
							t3->setPos(12800, 450);
							t4->setPos(13000, 350);
							t5->setPos(13000, 400);
							t6->setPos(13000, 450);
						}
					}
				}
			}
		}
	}
}

void MyScene::refresh()
{
    update();
    advance();
	removeCoins();
	judgeQue();
	//若已经死亡则不再判断
	if(!getControl()->getMario()->getDie())
	{
		spcialDie();
	}
	else
	{
		percentage();
	}
}

void MyScene::initialize()
{
    BGM=new Sound("StartBGM.mp3");
    BGM->player->setVolume(20);
    addItem(getControl()->getBack());
    getControl()->getBack()->setPos(0, 0);
    getControl()->getBack()->setZValue(-100);

    addItem(getControl()->getMario());
	getControl()->getMario()->setPos(200, 600);
	getControl()->getMario()->setZValue(50);

	addItem(getControl()->getFlag());
	getControl()->getFlag()->setPos(21150, 150);

    {
        coins* coi = new coins;
        this->addItem(coi);
        getControl()->pushCoins(coi);
        coi->setPos(200, -200000);
        getControl()->pushCoins(coi);
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
            getControl()->pushBlock(blo);
        }
        else if(str.substr(0,3) == "COI")
        {
            coins* coi = new coins;
            this->addItem(coi);
            coi->setPos(x, y);
			getControl()->pushCoins(coi);
        }
        else if(str.substr(0, 3) == "MON")
        {
			monster* mon = new monster;
			this->addItem(mon);
			mon->setPos(x, y);
			getControl()->pushMonster(mon);
        }

        else if(str.substr(0, 3) == "MUS")
        {
			mushroom* mus = new mushroom;
			this->addItem(mus);
			mus->setPos(x, y);
			getControl()->pushMushroom(mus);
        }
		else if(str.substr(0, 3) == "CLO")
        {
			cloud* clo = new cloud;
			this->addItem(clo);
			clo->setPos(x, y);
			getControl()->pushCloud(clo);
        }
		else if(str.substr(0, 3) == "STO")
		{
			stone* sto = new stone;
			this->addItem(sto);
			sto->setPos(x, y);
            getControl()->pushStone(sto);
		}
		else if(str.substr(0, 3) == "QUE")
		{
			questionMark* que = new questionMark;
			this->addItem(que);
			que->setPos(x, y);
			getControl()->pushQue(que);
		}
		else if(str.substr(0, 3) == "BAS")
		{
			baseblock* bas = new baseblock;
			this->addItem(bas);
			bas->setPos(x, y);
            getControl()->pushBase(bas);
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
                    getControl()->pushTube(tub);
				}
				else if(str[2] == 'M')
				{
					tube* tub = new tube(Medium, true);
					this->addItem(tub);
					tub->setPos(x, y);
                    getControl()->pushTube(tub);
				}
				else if(str[2] == 'L')
				{
					tube* tub = new tube(Long, true);
					this->addItem(tub);
					tub->setPos(x, y);
                    getControl()->pushTube(tub);
				}
			}
			else if(str[1] == 'F')
			{
				if(str[2] == 'S')
				{
					tube* tub = new tube(Short, false);
					this->addItem(tub);
					tub->setPos(x, y);
                    getControl()->pushTube(tub);
				}
				else if(str[2] == 'M')
				{
					tube* tub = new tube(Medium, false);
					this->addItem(tub);
					tub->setPos(x, y);
                    getControl()->pushTube(tub);
				}
				else if(str[2] == 'L')
				{
					tube* tub = new tube(Long, false);
					this->addItem(tub);
					tub->setPos(x, y);
                    getControl()->pushTube(tub);
				}
			}
		}
		else if(str.substr(0, 3) == "FLO")
		{
			flower* flo = new flower;
			this->addItem(flo);
			flo->setPos(x, y);
            flo->setZValue(-49);
			getControl()->pushFlower(flo);
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
				delete jumpSound;
				jumpSound=new Sound("Jump.wav");
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
			if(control->isDowncollider())           //在下方有东西的时候才能跳
			{
				delete jumpSound;
				jumpSound=new Sound("Jump.wav");
				//connect(jumpSound,&Sound::finished, jumpSound, &QObject::deleteLater);
				control->getMario()->setJumping(true);
			}
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
            //control->getMario()->setPixmap("Lstand.png");//松开A面朝左站立
        }
        else if(event->key() == Qt::Key_D)          //松开d键传停止右走的信号
        {
            control->getMario()->setGoingRight(false);
            //control->getMario()->setPixmap("Rstand.png");//松开D面朝右站立
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
        if(event->key() == Qt::Key_D)
        { 
            control->getMario()->setGoingRight(false);
            isMoving = false;
        }
        else if(event->key() == Qt::Key_A)
        {
            control->getMario()->setGoingLeft(false);
            isMoving = false;
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
    if(control->getMario()->x() <= pos_x) { control->getMario()->setGoingLeft(false); }
    else if(control->getMario()->x() < pos_x + 500) { isMoving = false; }
    control->getBack()->update();

	//若马里奥死亡则不再移动场景及马里奥
	if(!getControl()->getMario()->getDie())
	{
		control->moveMario();
		moveView();
	}

    moveMonster();
    moveFlower();
}

void MyScene::moveView()                                    //场景移动相关函数
{
    if(isMoving)
    {
        //qDebug() << "moveView";                             //调试信息
        if(pos_x<20300)

        {
            pos_x += 1;
            setSceneRect(pos_x,0,1450,800);
            int temp = pos_x;
            control->getBack()->setX(pos_x);//到图的右边缘就不再动了
            control->getBack()->setPos(temp,0);
        }

        control->getBack()->update();
        //调用update()的时候会自动调用paint函数，所以给paint里drawpixmap的横坐标改成参数x
        //修改x的值，让背景图片paint起点在负方向，就实现北京移动了
    }
}

void MyScene::moveMonster()
{
    int num = control->getMonster().size();
    for(int i = 0;i < num;i++)
    {
        //qDebug() << "first working" << pos_x << control->getMonster().at(i)->x();

        if(control->getMonster().at(i)->x() < pos_x)
        {
            continue;
        }
        else if(control->getMonster().at(i)->x() > pos_x+1450)
        {
            continue;
        }

        //qDebug() << "work";

        if(control->monisLeft(control->getMonster().at(i)))
        {
            control->getMonster().at(i)->setGoingLeft(false);
            control->getMonster().at(i)->setGoingRight(true);
        }
        if(control->monisRight(control->getMonster().at(i)))
        {
            control->getMonster().at(i)->setGoingLeft(true);
            control->getMonster().at(i)->setGoingRight(false);
        }

        bool left = control->getMonster().at(i)->getGoingLeft();
        bool right = control->getMonster().at(i)->getGoingRight();

        if(left == true && right == false)
        {
            //qDebug() << left << right << control->getMonster().at(i)->x();
            control->getMonster().at(i)->moveBy(-1,0);
        }
        else if(left == false && right == true)
        {
            //qDebug() << left << right << control->getMonster().at(i)->x();
            control->getMonster().at(i)->moveBy(1,0);
        }

        if(!control->monisDown(control->getMonster().at(i)))
        {
            control->getMonster().at(i)->moveBy(0,2);
        }

    }
}

void MyScene::moveFlower()
{
    int num = control->getFlower().size();
    for(int i = 0;i < num;i++)
    {
        if(control->getFlower().at(i)->x() < pos_x && control->getFlower().at(i)->x() > pos_x +1450)
            continue;

        if(control->getFlower().at(i)->getTime() > 0 && control->getFlower().at(i)->getTime() < 200)
        {
            control->getFlower().at(i)->moveBy(0,0.2);
            control->getFlower().at(i)->setTime(control->getFlower().at(i)->getTime() + 1);
        }
        else if(control->getFlower().at(i)->getTime() == 200)
        {
            control->getFlower().at(i)->moveBy(0,1000);
            control->getFlower().at(i)->setTime(control->getFlower().at(i)->getTime() + 1);
        }
        else if(control->getFlower().at(i)->getTime() == 1200)
        {
            control->getFlower().at(i)->moveBy(0,-1000);
            control->getFlower().at(i)->setTime(control->getFlower().at(i)->getTime() + 1);
        }
        else if(control->getFlower().at(i)->getTime() > 1200 && control->getFlower().at(i)->getTime() < 1400)
        {
            control->getFlower().at(i)->moveBy(0,-0.2);
            control->getFlower().at(i)->setTime(control->getFlower().at(i)->getTime() + 1);
        }
        else if(control->getFlower().at(i)->getTime() == 2000)
        {
            control->getFlower().at(i)->setTime(1);
        }
        else
        {
            control->getFlower().at(i)->setTime(control->getFlower().at(i)->getTime() + 1);
        }

//        qDebug() << control->getFlower().at(i)->y() << i;
    }
}

QString MyScene::percentage()
{
	double temp = (getControl()->getMario()->x() + pos_x) / 21750.0;
	QString ret;
	double t = 0.1;
	int k = 0;
	while (temp > 0)
	{
		k++;
		char te = static_cast<int>(temp / t) + '0';
		temp = temp / t - te + '0';
		ret.push_back(te);
		qDebug() << te;
		if(k == 2) ret.push_back('.');
		if(k == 4)
		{
			ret.push_back('%');
			break;
		}
	}
	qDebug() << ret;
	return ret;
}
