#ifndef COINNUMBER_H
#define COINNUMBER_H
#include <QGraphicsItem>


class coinnumber : public QGraphicsTextItem
{
public:
	coinnumber(int a);
	void showNumber();
	void setNum(int a) {number = a;}

private:
	int number;
};

#endif // COINNUMBER_H
