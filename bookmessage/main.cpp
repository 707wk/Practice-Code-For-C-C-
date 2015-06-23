/**************************************
 *FILE    :C:\Users\Administrator\Desktop\bookmessage\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 19:35:17
 *TEXT    :图书管理
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct bookinfo
{
	string name;
	int id;
};

class bookmessage
{
private:
	vector <struct bookinfo> data;    //书籍存放
	struct bookinfo tmp;              //临时交换空间
public:
	void addbook();                   //添加书籍
	void inputbookinfo();             //输出书籍信息
	void findbook();                  //查找书籍
	int  finddata();                  //查找书籍
	void delbook();                   //删除书籍
};

//添加书籍
void bookmessage::addbook()
{
	cout<<"请输入书名:";
	cin>>tmp.name;
	cout<<"请输入书籍编号";
	string str;
	cin>>str;
	tmp.id=atoi(str.c_str());
	if(finddata())
	{
		cout<<"书籍已存在!"<<endl;
		return ;
	}
	data.push_back(tmp);
	cout<<"添加成功!"<<endl;
}

//输出书籍信息
void bookmessage::inputbookinfo()
{
	cout<<"书籍名\t编号"<<endl;
	for(int i=0;i<data.size();i++)
	{
		cout<<data[i].name<<" "<<data[i].id<<endl;
	}
}

//查找书籍
void bookmessage::findbook()
{
	cout<<"请输入要查找的书籍名:";
	cin>>tmp.name;
	int index=finddata();
	if(!index)
	{
		cout<<"书籍未找到!"<<endl;
		return ;
	}
	cout<<"书籍名\t编号"<<endl;
	cout<<data[index-1].name<<" "<<data[index-1].id<<endl;
}

//查找书籍
int bookmessage::finddata()
{
	for(int i=0;i<data.size();i++)
	{
		if(data[i].name==tmp.name)
			return i+1;
	}
	return 0;
}

//删除书籍
void bookmessage::delbook()
{
	int index;
	cout<<"请输入要删除的书名:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"书籍未找到!"<<endl;
		return ;
	}
	data.erase(data.begin()+index-1);
	cout<<"删除成功!"<<endl;
}

int main()
{
	bookmessage bookdata;
	for(;;)
	{
		cout<<"书籍管理系统"<<endl;
		cout<<"1 添加书籍"<<endl;
		cout<<"2 输出书籍信息"<<endl;
		cout<<"3 查找书籍"<<endl;
		cout<<"4 删除书籍"<<endl;
		cout<<"5 退出"<<endl;
		cout<<"请输入选项:";
		string ch;
		cin>>ch;
		////////////////////////////////////
		//清屏
		system("cls");
		////////////////////////////////////
		switch(ch[0])
		{
		case '1':
			bookdata.addbook();
			break;
		case '2':
			bookdata.inputbookinfo();
			break;
		case '3':
			bookdata.findbook();
			break;
		case '4':
			bookdata.delbook();
			break;
		case'5':
			return 0;
			break;
		}
	}
	return 0;
}