/**************************************
 *FILE    :D:\707wk\Practice-Code-For-CPP\20150427002.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/4/27 12:25:56
 *TEXT    :计算三角形面积
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>

using namespace std ;

class Box 
{
public :
	//
	void set_value();
	void show_volume();
	void volume();
	
private :
	int length ;
	int width ;
	int height ;
	int vol;
};

void Box :: set_value()
{
	cin>>length ;
	cin>>width ;
	cin>>height ;
	volume();
}

void Box :: volume()
{
	vol=height*length*width;
}

void Box :: show_volume()
{
	cout<<"The volume is "<<vol<<endl ;
}

int main()
{
	Box box1 ;
	box1.set_value();
	box1.show_volume();
	return 0 ;
}
