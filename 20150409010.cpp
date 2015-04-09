/**************************************
 *FILE    :010.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/9/2015
***************************************/
/*
检测回文句
*/
#include <iostream>
#include <fstream>

using namespace std;

#define MAXNUM 100

int checkstr(string temp)
{
	int i;
	int j;
	fstream inout("temp",ios::out);
	string str[MAXNUM];
	inout<<temp;
	inout.close();
	inout.open("temp",ios::in);
	for(i=0;!inout.eof();i++)
		inout>>str[i];
	inout.close();
	for(j=0;j<i-1;j++,i--)
	{
		if(str[j]!=str[i-1])return 0;
	}
	return 1;
}

int main()
{
	string str;
	for(;;)
	{
		getline(cin,str);
		if(checkstr(str))cout<<"这是回文句"<<endl;
		else cout<<"这不是回文句"<<endl;
	}
	return 0;
}
