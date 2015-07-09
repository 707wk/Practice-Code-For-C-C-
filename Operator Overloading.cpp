/**************************************
 *FILE    :D:\c\Operator Overloading.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 23:13:24
 *TEXT    :Operator Overloading
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class OperatorOverloading
{
public:
	//构造函数 
	OperatorOverloading(double a, double b)
	{
		real=a;
		imaginary=b;
	}
	//拷贝构造函数 
	OperatorOverloading(const OperatorOverloading &source)
	{
		real=source.real;
		imaginary=source.imaginary;
	}

	OperatorOverloading operator +(const OperatorOverloading &right)
	{
		return OperatorOverloading(real+right.real, imaginary+right.imaginary);
	}
	
	OperatorOverloading operator -(const OperatorOverloading &right)
	{
		return OperatorOverloading(real-right.real, imaginary-right.imaginary);
	}
	
	OperatorOverloading operator *(const OperatorOverloading &right)
	{
		return OperatorOverloading(real*right.real-imaginary*right.imaginary, imaginary*right.real+real*right.imaginary);
	}
	
	OperatorOverloading operator /(const OperatorOverloading &right)
	{
		return OperatorOverloading((real*right.real+imaginary*right.imaginary)/(right.real*right.real+right.imaginary*right.imaginary), (imaginary*right.real-real*right.imaginary)/(right.real*right.real+right.imaginary*right.imaginary));
	}
	
	friend ostream &operator<<(ostream &output, const OperatorOverloading data);
	
	friend istream &operator>>(istream &input, OperatorOverloading &data);

private:
	double real;
	double imaginary;
};

//输出流重载
ostream &operator<<(ostream &out, const OperatorOverloading data)
{
	if(data.real==0&&data.imaginary==0)
	{
		out<<0;
		return out;
	}

	out<<data.real;
	if(data.imaginary!=0)
	{
		if(data.real!=0&&data.imaginary>0) out<<'+';
		if(data.imaginary!=1&&data.imaginary!=-1) out<<data.imaginary;
		else if(data.imaginary==-1) out<<'-';
		out<<'i';
	}

	return out;
}

//输入流重载
istream &operator>>(istream &input, OperatorOverloading &data)
{
	cout<<"输入 real + imaginary i\nreal: ";
	input>>data.real;
	cout<<"imaginary: ";
	input>>data.imaginary;
	if(!input) data.real=data.imaginary=0.0;
	return input;
}

int main()
{
	OperatorOverloading a(0.0,0.0);
	OperatorOverloading b(a);
	for(;;)
	{
		cout<<"输入第一个:"<<endl;
		cin>>a;
		cout<<"输入第二个:"<<endl;
		cin>>b;
		cout<<"加: "<<a+b<<endl;
		cout<<"减: "<<a-b<<endl;
		cout<<"乘: "<<a*b<<endl;
		cout<<"除: "<<a/b<<endl;
		cout<<endl;
	}
	return 0;
}

