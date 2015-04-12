/**************************************
 *FILE    :018.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/12/2015
 *TEXT    :factorial
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>

using namespace std;

double funiction(int num,int len)
{
	int x=num;
	int denom=1;
	double sum=1;
	
	for(int i=1;i<len;i++)
	{
		denom*=i;
		sum+=(x*1.0/denom);
		x*=num;
	}
	return sum;
}

int main()
{
	int num;
	int len;
	for(;cin>>num>>len;)
		cout<<funiction(num,len)<<endl;
	return 0;
}
