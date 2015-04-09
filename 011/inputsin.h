/**************************************
 *FILE    :inputsin.h
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

class inputsin{
	
	public:
		inputsin()
		{
			int i;
			int j;
			for(i=0;i<HIGHT;i++)
				for(j=0;j<WIDE;j++)
					num[i][j]=0;
		};
		void setnum();
		void putnum();
		
	private:
		int num[HIGHT][WIDE];
		
};
