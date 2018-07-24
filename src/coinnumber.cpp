#include "coinnumber.h"
#include <QString>
#include <QFont>

coinnumber::coinnumber(int a)
{
	number = a;
}

void coinnumber::showNumber()
{
	QString str;
	int dig = 1;
	int temp = number;
	while (temp / 10)
	{
		dig++;
		temp = temp / 10;
	}
	str.resize(dig);
	for(int i = 0; i < dig; i++)
	{
		int t = number % 10;
		number = number / 10;
		str[dig - i - 1] = t + '0';
	}

	this->setFont(QFont("Consolas",40,QFont::Bold));
	setDefaultTextColor(QColor(255, 255, 255));
	setPlainText(str);
}
