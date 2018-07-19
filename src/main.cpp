#include "mainwindow.h"
#include <QApplication>

#include "mario.h"
#include "blocks.h"
#include "gameboard.h"
#include "view.h"
#include "myscene.h"
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "globalapplication.h"
class view;
class GameBoard;

int main(int argc, char *argv[])
{
    GlobalApplication a(argc, argv);

    /*    QGraphicsScene scene;
    QGraphicsView v(&scene);

    view* vie = new view;
    scene.addItem(vie->getControl()->getMario());
    vie->getControl()->getMario()->setPos(100, 700);
    scene.addItem(vie);
    for(int i = 0; i < vie->getControl()->getBlocks().size(); i++) {
        scene.addItem(vie->getControl()->getBlocks().at(i));
    }
    vie->setPos(0, 0);


    scene.additem(item);
    scene.additem(block);
    scene.additem(block2);
    scene.additem(block3);
    block->setpos(300, 170);
    block2->setpos(250, 220);
    block3->setpos(300, 70);
    item->setpos(300, 120);*/

    MyScene scene;
    QGraphicsView v(&scene);

    v.setWindowTitle("motherfucker");

    v.resize(1450,800);
    v.show();

    return a.exec();
}
