#include "mainwindow.h"
#include <QApplication>

#include "mario.h"
#include "blocks.h"
#include "gameboard.h"
#include "view.h"
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
class view;
class GameBoard;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QGraphicsScene scene;


	view* vie = new view;
	scene.addItem(vie->getControl()->getMario());

/*    scene.additem(item);
	scene.additem(block);
	scene.additem(block2);
	scene.additem(block3);
	block->setpos(300, 170);
	block2->setpos(250, 220);
	block3->setpos(300, 70);
	item->setpos(300, 120);
*/


	scene.setSceneRect(0, 0, 700, 500);
	QGraphicsView v(&scene);
	v.setWindowTitle("motherfucker");

    v.resize(1440,800);
	v.show();

    return a.exec();
}
