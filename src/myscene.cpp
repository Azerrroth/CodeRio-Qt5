#include "myscene.h"
#include "view.h"
#include <fstream>
#include <string>
#include <algorithm>

using std::fstream;
using std::string;

MyScene::MyScene()
{
    vie = new view;
    addItem(vie);
    vie->setPos(0, 0);
    initialize();
    setSceneRect(0, 0, 1450, 800);
}

void MyScene::initialize()
{
    addItem(vie->getControl()->getMario());
    vie->getControl()->getMario()->setPos(100, 700);
    addItem(vie->getControl()->getBack());
    vie->getControl()->getBack()->setPos(0, 0);
    fstream in("info.txt");
    string str;
    while (getline(in, str))
    {
        int x = atoi(const_cast<char*>(str.substr(3, 7).c_str()));
        int y = atoi(const_cast<char*>(str.substr(10, 7).c_str()));

        if(str.substr(0, 3) == "BLO")
        {
            blocks* blo = new blocks;
            this->addItem(blo);
            blo->setPos(x, y);
            vie->getControl()->getBlocks().push_back(blo);
        }
        else if(str.substr() == "COI")
        {
            coins* coi = new coins;
            this->addItem(coi);
            coi->setPos(x, y);
            vie->getControl()->getCoins().push_back(coi);
        }
        else if(str.substr(0, 3) == "MON")
        {

        }
        else if(str.substr(0, 3) == "FLA")
        {

        }
        else if(str.substr(0, 3) == "MUS")
        {

        }
        else if(str.substr(0, 3) == "TUR")
        {

        }
    }
}
