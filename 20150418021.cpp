/**************************************
 *FILE    :021.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/18/2015
 *TEXT    :Greatest common divisor from files and sort
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
 
#define MAXNUM 10000

struct data{
	int m;
	int n;
	int maxgcd;
};

//产生len个范围在0-MAX之间的随机数存储至input.txt
void startdata(int len)
{
	srand(time(NULL));
	ofstream out("input.txt");
	for(;len--;)
	{
		out<<rand()%MAXNUM<<"\t"<<rand()%MAXNUM<<endl;
	}
	out.close();
}

//利用转转相除法求最大公约数
int gcd(int m,int n)
{
	if(m%n==0)return n;
	return gcd(n,m%n);
}

//判断函数
bool compdata(struct data a, struct data b){
	return a.maxgcd < b.maxgcd ? 1 : 0;
}     

//读取数值并排序存至output.txt
void sortnum()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	struct data temp;
	vector<data> num;

	cout<<"read data from input.txt!"<<endl;
	for(int i=0;!in.eof();i++)
	{
		in>>temp.m>>temp.n;
		temp.maxgcd=gcd(temp.m,temp.n);
		num.push_back(temp);
	}
	cout<<"read data end!"<<endl;
	in.close();

	vector<data>::iterator it;
	/*for(it=num.begin();it<num.end();it++)
	{
		cout<<it->m<<" \t"<<it->n<<" \t"<<it->maxgcd<<endl;
	}*/

	sort(num.begin(),num.end(),compdata);

	if(out.is_open())
	{
		cout<<"files open success!"<<endl;
		for(it=num.begin();it<num.end();it++)
		{
			out<<(*it).m<<" \t"<<(*it).n<<" \t"<<(*it).maxgcd<<endl;
		}
		cout<<"data input files success!"<<endl;
	}
	else cout<<"files open fails!"<<endl;
	
	out.close();
}

int main()
{
	startdata(1000);
	sortnum();
	return 0;
}
