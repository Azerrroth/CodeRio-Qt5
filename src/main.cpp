#include "mainwindow.h"
#include <QApplication>

#include "mario.h"
#include "blocks.h"
#include "gameboard.h"
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
    MyScene scene;
    QGraphicsView v(&scene);
    v.setFixedSize(1452,802);
    v.setWindowFlags(Qt::FramelessWindowHint);
    v.show();

    return a.exec();
}
