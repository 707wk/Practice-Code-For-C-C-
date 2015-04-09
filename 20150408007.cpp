/**************************************
 *FILE    :007.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
读取文件数据排序输出文件
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std ;

int main()
{
	int i ;
	ifstream datain("input.txt");
	ofstream dataout("output.txt");
	vector<int> num;
	
	for(i=0;!datain.eof();i++)
	{
		int temp;
		datain>>temp;
		num.push_back(temp);
	}
	
	sort(num.begin(),num.end());
	
	vector<int>::iterator iter=num.begin();
	for(;iter<num.end();iter++)
	{
		cout<<*iter<<" ";
		dataout<<*iter<<" ";
	}
	
	datain.close();
	dataout.close();
	
	return 0 ;
}
