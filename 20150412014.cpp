/**************************************
 *FILE    :014.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/11/2015
 *TEXT    :two to ten
 *EMAIL    :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>
#include <string>

using namespace std;

long long twototen(string str)
{
	int i;
	long long sum=0;
	
	for(i=0;i<str.length();i++)
	{
		sum*=2;
		if(str[i]-'0')sum+=1;
	}
	
	return sum;
}

int main()
{
	string str;
	for(;cin>>str;cout<<twototen(str)<<endl);
	return 0;
}
