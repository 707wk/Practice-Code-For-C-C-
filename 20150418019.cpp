/**************************************
 *FILE    :019.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/18/2015
 *TEXT    :recursion main
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>

using namespace std;

int flage=10;

int main()
{
	if(flage--)
	{
		printf("1");
		main();
	}
	return 0;
}
