#include "mainwindow.h"
#include <QApplication>

#include "mario.h"
#include "blocks.h"
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
	mario * item = new mario("D:/mario.png");
	blocks* block = new blocks("D:/block.png");
	blocks* block2 = new blocks("D:/block.png");
	blocks* block3 = new blocks("D:/block.png");


    scene.addItem(item);
	scene.addItem(block);
	scene.addItem(block2);
	scene.addItem(block3);
	block->setPos(300, 170);
	block2->setPos(250, 220);
	block3->setPos(300, 70);
	item->setPos(300, 120);



    scene.setSceneRect(0,0,700,500);
    QGraphicsView view(&scene);
    view.setWindowTitle("motherfxxker");

    view.resize(700,500);
    view.show();

    return a.exec();
}
