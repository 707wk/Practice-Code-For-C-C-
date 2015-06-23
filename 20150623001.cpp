/**************************************
 *FILE    :D:\c\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 12:03:35
 *TEXT    :超长二进制转十进制
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//以多少为进位 
#define MODNUM 10000
////////////////////////////////////////////////////////////////////////////////

int main()
{
	string bitstr;
	vector <int> temp;
	vector <int> sum;
	int temp_add=0;
	cin>>bitstr;
	for(int i=0;i<bitstr.length();i++)
	{
		////////////////////////////////////////////////////////////////////////
		//计算当前二进制位大小 
		int add=0;
		if(i==0)add=1;
		for(int j=0;j<temp.size();j++)
		{
	 		temp[j]=temp[j]*2+add;
			add=temp[j]/MODNUM;
			temp[j]=temp[j]%MODNUM;
		}
		if(add)
		{
			temp.push_back(add);
		}
		////////////////////////////////////////////////////////////////////////
		
		////////////////////////////////////////////////////////////////////////
		//累加 
		if(bitstr[i]=='1')
		{
			for(int j=0;j<temp.size();j++)
			{
				if(j>=sum.size())sum.push_back(0);
	 			sum[j]=sum[j]+temp[j]+temp_add;
				temp_add=sum[j]/MODNUM;
				sum[j]=sum[j]%MODNUM;
			}
			if(temp_add)
			{
				sum.push_back(temp_add);
				temp_add=0;
			}
		}
		////////////////////////////////////////////////////////////////////////
	}
	
	//逆序输出
	printf("%d",sum[sum.size()-1]);
	for(int k=sum.size()-1;k;k--)
	{
		//输出格式按照MODNUM更改 
		printf(".%04d",sum[k-1]);
	}
	cout<<endl;
	
	return 0;
}
