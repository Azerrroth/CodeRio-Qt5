#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include "view.h"

class MyScene : public QGraphicsScene
{
public:
    MyScene();
private:
    void initialize();
    view* vie;
};

#endif // MYSCENE_H
