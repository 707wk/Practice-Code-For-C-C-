/**************************************
 *FILE    :005.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
回文数
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int checknum(int num)
{
	int left=0;
	int right;
	char temp[100];
	itoa(num,temp,10);
	string str=temp;
	for(right=str.length()-1;left<right;left++,right--)
		if(str[left]!=str[right])return 0;
	return 1;
}

int main()
{
	int num;
	srand((unsigned)time(0));
	for(;!checknum(num=rand()););
	cout<<"找到的第一个回文数:"<<num<<endl;
	cout<<"运行:"<<clock()<<"毫秒"<<endl;
	return 0;
}
