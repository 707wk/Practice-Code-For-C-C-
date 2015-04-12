/**************************************
 *FILE    :015.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/11/2015
 *TEXT    :print 1-256 char for teo sox eight
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>
#include <iomanip>

using namespace std;

void rowline()
{
	for(int i=0;i<36;i++)cout<<'-';
	cout<<endl;
}

void formatnum(int num)
{
	cout<<"| "<<setw(3)<<dec<<num<<" |";
	for(int i=16;i;i--)cout<<((num>>(i-1))%2?'1':'0');
	cout<<" | "<<setw(3)<<setiosflags(ios::uppercase)<<hex<<num;
	cout<<" | "<<setw(3)<<oct<<num<<"|"<<endl;
	rowline();
}

int main()
{
	for(int i=1;i<257;i++)
		formatnum(i);
	return 0;
}
