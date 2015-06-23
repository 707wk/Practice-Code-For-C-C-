/**************************************
 *FILE    :C:\Users\Administrator\Desktop\bookmessage\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 19:35:17
 *TEXT    :ͼ�����
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
	vector <struct bookinfo> data;    //�鼮���
	struct bookinfo tmp;              //��ʱ�����ռ�
public:
	void addbook();                   //����鼮
	void inputbookinfo();             //����鼮��Ϣ
	void findbook();                  //�����鼮
	int  finddata();                  //�����鼮
	void delbook();                   //ɾ���鼮
};

//����鼮
void bookmessage::addbook()
{
	cout<<"����������:";
	cin>>tmp.name;
	cout<<"�������鼮���";
	string str;
	cin>>str;
	tmp.id=atoi(str.c_str());
	if(finddata())
	{
		cout<<"�鼮�Ѵ���!"<<endl;
		return ;
	}
	data.push_back(tmp);
	cout<<"��ӳɹ�!"<<endl;
}

//����鼮��Ϣ
void bookmessage::inputbookinfo()
{
	cout<<"�鼮��\t���"<<endl;
	for(int i=0;i<data.size();i++)
	{
		cout<<data[i].name<<" "<<data[i].id<<endl;
	}
}

//�����鼮
void bookmessage::findbook()
{
	cout<<"������Ҫ���ҵ��鼮��:";
	cin>>tmp.name;
	int index=finddata();
	if(!index)
	{
		cout<<"�鼮δ�ҵ�!"<<endl;
		return ;
	}
	cout<<"�鼮��\t���"<<endl;
	cout<<data[index-1].name<<" "<<data[index-1].id<<endl;
}

//�����鼮
int bookmessage::finddata()
{
	for(int i=0;i<data.size();i++)
	{
		if(data[i].name==tmp.name)
			return i+1;
	}
	return 0;
}

//ɾ���鼮
void bookmessage::delbook()
{
	int index;
	cout<<"������Ҫɾ��������:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"�鼮δ�ҵ�!"<<endl;
		return ;
	}
	data.erase(data.begin()+index-1);
	cout<<"ɾ���ɹ�!"<<endl;
}

int main()
{
	bookmessage bookdata;
	for(;;)
	{
		cout<<"�鼮����ϵͳ"<<endl;
		cout<<"1 ����鼮"<<endl;
		cout<<"2 ����鼮��Ϣ"<<endl;
		cout<<"3 �����鼮"<<endl;
		cout<<"4 ɾ���鼮"<<endl;
		cout<<"5 �˳�"<<endl;
		cout<<"������ѡ��:";
		string ch;
		cin>>ch;
		////////////////////////////////////
		//����
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