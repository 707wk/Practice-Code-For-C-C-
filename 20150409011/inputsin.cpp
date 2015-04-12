/**************************************
 *FILE    :inputsin.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
/*
input sin
*/
#include <iostream>
#include <math.h>
#include "inputsin.h"

using namespace std;

void inputsin::setnum()
{
	int j;
	int temp;
	for(j=0;j<WIDE;j++)
	{
		temp=HIGHT/2-(int)((sin(j/(WIDE/62)/10.0)+0.05)*HIGHT/2);
		num[temp][j]=1;
	}
}

void inputsin::putnum()
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
