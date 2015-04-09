/**************************************
 *FILE    :006.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
回文词
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int checkstr(string str)
{
	int left=0;
	int right=str.length()-1;
	for(;left<right;left++,right--)
		if(str[left]!=str[right])return 0;
	return 1;
}

int main()
{
	string str;
	for(;cin>>str;)
	{
		if(checkstr(str))cout<<str<<"是回文词"<<endl;
		else cout<<str<<"不是回文词"<<endl;
	}
	return 0;
}
