/**************************************
 *FILE    :017.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/12/2015
 *TEXT    :compound rate
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void rowline(int len)
{
	for(int i=0;i<len;i++)cout<<'-';
	cout<<endl;
}

float comprate(double rate,int endyear)
{
	double temp=1;

	for(int i=0;i<endyear;i++)
		temp*=rate;
	return 24*(1-temp)/(1-rate);
}

int main()
{
	double sum;
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	
	rowline(20);
	for(int i=5;i<11;i++)
	{
		cout<<"|"<<setw(3)<<i<<"% |"<<setw(10)<<comprate(1+i*1.0/100,1900+timeinfo->tm_year-1626)<<" |"<<endl;
		rowline(20);
	}
	
	return 0;
}
