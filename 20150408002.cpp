/**************************************
 *FILE    :002.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
请输入行数:12
           #$
          ##$$
         ###$$$
        ####$$$$
       #####$$$$$
      ######$$$$$$
     #######$$$$$$$
    ########$$$$$$$$
   #########$$$$$$$$$
  ##########$$$$$$$$$$
 ###########$$$$$$$$$$$
############$$$$$$$$$$$$
*/
#include <iostream>

using namespace std;

void printtriangle(int hight)
{
	int i;
	int j;
	for(i=1;i<=hight;i++)
	{
		for(j=0;j<hight-i;j++)
			cout<<" ";
		for(j=0;j<i*2;j++)
			j<i?cout<<"#":cout<<"$";
		cout<<endl;
	}
}

int main()
{
	int num;
	cout<<"请输入行数:";
	for(;cin>>num;cout<<"请输入行数:")
		printtriangle(num);
	return 0;
}
