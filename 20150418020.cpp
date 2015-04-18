/**************************************
 *FILE    :020.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/18/2015
 *TEXT    :Greatest common divisor 
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>

using namespace std;

int gcd(int m,int n)
{
	if(m%n==0)return n;
	return gcd(n,m%n);
}

int main()
{
	int m;
	int n;
	for(;cin>>m>>n;cout<<gcd(m,n)<<endl);
	return 0;
}
