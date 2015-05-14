/**************************************
 *FILE    :D:\707wk\Practice-Code-For-CPP\20150514002.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015-5-14 ���� 07:49:40
 *TEXT    :NULL
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>

using namespace std;

/******************************************************************************/
//����ָ��� 
void putline()
{
	cout<<endl;
	for(int i=0;i<79;i++)cout<<"=";
	cout<<endl;
}
/******************************************************************************/
//�������� 
int isprime(int num)
{
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)return 0;
	}
	return 1;
}
/******************************************************************************/
//����ˮ�ɻ��� 
int isnarcissnum(int num)
{
	int a=num/100;
	int b=num/10%10;
	int c=num%10;
	if(a*a*a+b*b*b+c*c*c==num)return 1;
	return 0;
}
/******************************************************************************/
//�������� 
int isperfectnum(int num)
{
	int sum=0;
	for(int i=1;i<num;i++)
	{
		if(num%i==0)sum+=i;
	}
	if(sum==num)return 1;
	return 0;
}
/******************************************************************************/
int main()
{
	putline();
	//һ�������е�����д�� 
	cout<<"����:"<<endl;
	for(int i=1;i<1000;i++)
	{
		if(isprime(i))printf("%3d ",i);
	}
	/**************************************************************************/
	putline();
	//�ԴӸ߿�֮���ûд���ⶫ���� 
	cout<<"ˮ�ɻ���:"<<endl;
	for(int i=1;i<1000;i++)
	{
		if(isnarcissnum(i))printf("%3d ",i);
	}
	/**************************************************************************/
	putline();
	//����һ���������ʵ�����ɶ���� 
	cout<<"����:"<<endl;
	for(int i=1;i<1000;i++)
	{
		if(isperfectnum(i))printf("%3d ",i);
	}
	/**************************************************************************/
	putline();
	//1!+2!+3!+4!+����+10!
	cout<<"1!+2!+3!+4!+����+10!:"<<endl;
	int sum=0;
	int temp=1;
	for(int i=1;i<10+1;i++)
	{
		temp*=i;
		sum+=temp;
	}
	cout<<sum;
	/**************************************************************************/
	putline();
	return 0;
}
