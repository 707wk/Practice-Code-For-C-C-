/**************************************
 *FILE    :date.h
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <iostream>

using namespace std;

class date
{
	public:
		date(int y,int m,int d);
		void setyear(int y);
		int getyear();
		void setmonth(int m);
		int getmonth();
		void setday(int d);
		int getday();
		void displaydate();
	private:
		int year;
		int month;
		int day;
};
