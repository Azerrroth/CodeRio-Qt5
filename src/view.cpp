#include "view.h"

view::view(QWidget *parent) : QWidget(parent)
{

}

void view::keyPressEvent(QKeyEvent *event)
{
	QList<QGraphicsItem*>list = control->getMario()->collidingItems();

	if(control->getMario()->x() < 300
	   &&)
	{ //300即为场景移动的分界处，小于300仅移动马里奥
		if(event->key() == Qt::Key_D)
		{
			bool flag = true;
			for(int i = 0; i < list.size(); i++) {
				if(list[i]->x() >= control->getMario()->x() &&
				   list[i]->y() <= control->getMario()->y())
				{//判断与该物体接触的物体是否阻挡了该物体右移，若阻挡了则不做处理
					flag = false;
					break;
				}
			}
			if(flag) {
				control->getMario()->setMove(4, 0);
			}
		}
		else if(event->key() == Qt::Key_A)
		{
			if(control->getMario()->x() >= 0)
			{				//马里奥必须不能出场景
				bool flag = true;

				for(int i = 0; i < list.size(); i++) {
					if(list[i]->x() <= control->getMario()->x() &&
					   list[i]->y() <= control->getMario()->y())
					{
						flag = false;
						break;
					}
				}
				if(flag) {
					control->getMario()->setMove(-4, 0);
				}
			}
		}
		else if(event->key() == Qt::Key_Q)
		{

		}
		else if(event->key() == Qt::Key_E)
		{

		}
	}

	else
	{
		if(event->key() == Qt::Key_D)
		{
			e
		}
		else if(event->key() == Qt::Key_A)
		{

		}
		else if(event->key() == Qt::Key_Q)
		{

		}
		else if(event->key() == Qt::Key_E)
		{

		}
	}
}
