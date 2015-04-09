/**************************************
 *FILE    :003.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
4.26 回文数
*/
#include <iostream>
#include <string>
#include <stdlib.h>

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
	for(;cin>>num;)
	{
		if(checknum(num))cout<<"这是回文数"<<endl;
		else cout<<"这不是回文数"<<endl;
	}
	return 0;
}
