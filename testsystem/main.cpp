/**************************************
 *FILE    :C:\Users\Administrator\Desktop\studentmessage\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 19:35:17
 *TEXT    :考试管理
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct studentinfo
{
	string name;
	int id;
};

class studentmessage
{
private:
	vector <struct studentinfo> data;    //存放
	struct studentinfo tmp;              //临时交换空间
public:
	void addstudentinfo();			     //添加学生信息
	void inputstudentinfo();             //输出学生信息
	void findstudentinfo();              //查找学生信息
	int  finddata();                     //查找学生信息
	void modification();                 //修改学生信息
	void delstudentinfo();               //删除学生信息
};

//添加学生信息
void studentmessage::addstudentinfo()
{
	cout<<"请输入学生名:";
	cin>>tmp.name;
	cout<<"请输入学生学号:";
	string str;
	cin>>str;
	tmp.id=atoi(str.c_str());
	if(finddata())
	{
		cout<<"学生已存在!"<<endl;
		return ;
	}
	data.push_back(tmp);
	cout<<"添加成功!"<<endl;
}

//输出学生信息
void studentmessage::inputstudentinfo()
{
	cout<<"姓名\t学号"<<endl;
	for(int i=0;i<data.size();i++)
	{
		cout<<data[i].name<<" "<<data[i].id<<endl;
	}
}

//查找学生信息
void studentmessage::findstudentinfo()
{
	cout<<"请输入要查找的学生名:";
	cin>>tmp.name;
	int index=finddata();
	if(!index)
	{
		cout<<"学生未找到!"<<endl;
		return ;
	}
	cout<<"姓名\t学号"<<endl;
	cout<<data[index-1].name<<" "<<data[index-1].id<<endl;
}

//查找学生信息
int studentmessage::finddata()
{
	for(int i=0;i<data.size();i++)
	{
		if(data[i].name==tmp.name)
			return i+1;
	}
	return 0;
}

//修改学生信息
void studentmessage::modification()
{
	int index;
	cout<<"请输入要修改的学生名:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"学生信息未找到!"<<endl;
	}
	cout<<"请输入新学生名:";
	cin>>tmp.name;
	cout<<"请输入新学生学号:";
	cin>>tmp.name;
	data[index-1]=tmp;
	cout<<"修改成功!"<<endl;
}

//删除学生信息
void studentmessage::delstudentinfo()
{
	int index;
	cout<<"请输入要删除的学生名:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"学生信息未找到!"<<endl;
		return ;
	}
	data.erase(data.begin()+index-1);
	cout<<"删除成功!"<<endl;
}

int main()
{
	studentmessage studentdata;
	for(;;)
	{
		cout<<"考试管理系统"<<endl;
		cout<<"1 添加学生信息"<<endl;
		cout<<"2 输出学生信息"<<endl;
		cout<<"3 查找学生信息"<<endl;
		cout<<"4 修改学生信息"<<endl;
		cout<<"5 删除学生信息"<<endl;
		cout<<"6 退出"<<endl;
		cout<<"请输入选项:";
		string ch;
		cin>>ch;
		////////////////////////////////////
		//清屏
		//system("cls");
		////////////////////////////////////
		switch(ch[0])
		{
		case '1':
			studentdata.addstudentinfo();
			break;
		case '2':
			studentdata.inputstudentinfo();
			break;
		case '3':
			studentdata.findstudentinfo();
			break;
		case '4':
			studentdata.modification();
			break;
		case '5':
			studentdata.delstudentinfo();
			break;
		case '6':
			break;
		}
	}
	return 0;
}