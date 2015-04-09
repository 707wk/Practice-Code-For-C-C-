/**************************************
 *FILE    :date.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <iostream>
#include "date.h"

using namespace std;

date::date(int y,int m,int d)
{
	setyear(y);
	setmonth(m);
	setday(d);
}

void date::setyear(int y)
{
	year=y;
}

int date::getyear()
{
	return year;
}

void date::setmonth(int m)
{
	if(m<1)m=1;
	if(m>12)m=1;
	month=m;
}

int date::getmonth()
{
	return month;
}

void date::setday(int d)
{
	day=d;
}

int date::getday()
{
	return day;
}

void date::displaydate()
{
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}
