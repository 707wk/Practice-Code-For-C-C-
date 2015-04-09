/**************************************
 *FILE    :001.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
//stststs
// ststs
//  sts
//   s
#include <iostream>

using namespace std;

void printtriangle(int hight)
{
	int i;
	int j;
	for(i=0;i<hight;i++)
	{
		for(j=0;j<i;j++)
			cout<<" ";
		for(j=0;j<(hight-i)*2-1;j++)
			j%2?cout<<"T":cout<<"S";
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
