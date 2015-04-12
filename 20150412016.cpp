/**************************************
 *FILE    :016.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/11/2015
 *TEXT    :calculated values
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int temp=1;
	double sum=0;
	for(int i=1;i<10001;i++)
	{
		sum+=temp*4.0/(2*i-1);
		temp=-temp;
		cout<<setw(5)<<i<<" | "<<setw(10)<<sum<<endl;
	}
	return 0;
}
