/**************************************
 *FILE    :008.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
/*
input sin
*/
#include <iostream>
#include <math.h>

using namespace std;

#define HIGHT 20
#define WIDE 62

int num[HIGHT][WIDE]={0};

void setnum()
{
	int j;
	int temp;
	for(j=0;j<WIDE;j++)
	{
		temp=HIGHT/2-(int)((sin(j/(WIDE/62)/10.0)+0.05)*HIGHT/2);
		num[temp][j]=1;
	}
}

void putnum()
{
	int i;
	int j;
	for(i=0;i<HIGHT;i++)
	{
		for(j=0;j<WIDE;j++)
		{
			if(num[i][j])cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	setnum();
	putnum();
	return 0;
}
