/**************************************
 *FILE    :D:\707wk\Practice-Code-For-CPP\20150618001.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/18 12:20:59
 *TEXT    :—È÷§ ‰»Î
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>

using namespace std ;

int main()
{
    int a ;
    for(;;)
    {
        cin>>a ;
        if(cin.fail())
		{
			cout<<"error"<<endl;
			cin.clear();
		}
        if(a==1)
        {
            cout<<a<<" !!!!!"<<endl ;
        }
        else 
        {
            cout<<a<<" @@@@"<<endl ;
        }
        cin.sync();
    }
    return 0 ;
}
