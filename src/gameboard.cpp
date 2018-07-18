#include "gameboard.h"
#include "mario.h"
#include "blocks.h"
#include <QTimer>

GameBoard::GameBoard(QObject *parent) : QObject(parent)
{
	timerId = startTimer(15);//开启一个每隔15ms触发一次的计时器，timerId是该计时器的名称，
}

void GameBoard::setBlock(const QString file, qreal pos_x, qreal pos_y) {

}

void GameBoard::timerEvent(QTimerEvent *event) {
	moveView();
	moveMario();
}

void GameBoard::moveView() {
	back->move();
	for(int i = 0; i < blocklist.size(); i++) {
		blocklist[i]->move();
	}
}

void GameBoard::moveMario() {
	player->move();
}

