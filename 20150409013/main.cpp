/**************************************
 *FILE    :main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "date.h"

using namespace std;

int main()
{
	int i;
	srand((unsigned)time(0));
	for(i=0;i<10000;i++)
	{
		date temp(2015,rand(),12);
		if(temp.getmonth()<1)cout<<"no"<<endl;
		if(temp.getmonth()>12)cout<<"no"<<endl;
	}
	cout<<"ok"<<endl;
	return 0;
}
