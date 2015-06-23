/**************************************
 *FILE    :C:\Users\Administrator\Desktop\studentmessage\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/6/23 19:35:17
 *TEXT    :���Թ���
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
	vector <struct studentinfo> data;    //���
	struct studentinfo tmp;              //��ʱ�����ռ�
public:
	void addstudentinfo();			     //���ѧ����Ϣ
	void inputstudentinfo();             //���ѧ����Ϣ
	void findstudentinfo();              //����ѧ����Ϣ
	int  finddata();                     //����ѧ����Ϣ
	void modification();                 //�޸�ѧ����Ϣ
	void delstudentinfo();               //ɾ��ѧ����Ϣ
};

//���ѧ����Ϣ
void studentmessage::addstudentinfo()
{
	cout<<"������ѧ����:";
	cin>>tmp.name;
	cout<<"������ѧ��ѧ��:";
	string str;
	cin>>str;
	tmp.id=atoi(str.c_str());
	if(finddata())
	{
		cout<<"ѧ���Ѵ���!"<<endl;
		return ;
	}
	data.push_back(tmp);
	cout<<"��ӳɹ�!"<<endl;
}

//���ѧ����Ϣ
void studentmessage::inputstudentinfo()
{
	cout<<"����\tѧ��"<<endl;
	for(int i=0;i<data.size();i++)
	{
		cout<<data[i].name<<" "<<data[i].id<<endl;
	}
}

//����ѧ����Ϣ
void studentmessage::findstudentinfo()
{
	cout<<"������Ҫ���ҵ�ѧ����:";
	cin>>tmp.name;
	int index=finddata();
	if(!index)
	{
		cout<<"ѧ��δ�ҵ�!"<<endl;
		return ;
	}
	cout<<"����\tѧ��"<<endl;
	cout<<data[index-1].name<<" "<<data[index-1].id<<endl;
}

//����ѧ����Ϣ
int studentmessage::finddata()
{
	for(int i=0;i<data.size();i++)
	{
		if(data[i].name==tmp.name)
			return i+1;
	}
	return 0;
}

//�޸�ѧ����Ϣ
void studentmessage::modification()
{
	int index;
	cout<<"������Ҫ�޸ĵ�ѧ����:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"ѧ����Ϣδ�ҵ�!"<<endl;
	}
	cout<<"��������ѧ����:";
	cin>>tmp.name;
	cout<<"��������ѧ��ѧ��:";
	cin>>tmp.name;
	data[index-1]=tmp;
	cout<<"�޸ĳɹ�!"<<endl;
}

//ɾ��ѧ����Ϣ
void studentmessage::delstudentinfo()
{
	int index;
	cout<<"������Ҫɾ����ѧ����:";
	cin>>tmp.name;
	index=finddata();
	if(!index)
	{
		cout<<"ѧ����Ϣδ�ҵ�!"<<endl;
		return ;
	}
	data.erase(data.begin()+index-1);
	cout<<"ɾ���ɹ�!"<<endl;
}

int main()
{
	studentmessage studentdata;
	for(;;)
	{
		cout<<"���Թ���ϵͳ"<<endl;
		cout<<"1 ���ѧ����Ϣ"<<endl;
		cout<<"2 ���ѧ����Ϣ"<<endl;
		cout<<"3 ����ѧ����Ϣ"<<endl;
		cout<<"4 �޸�ѧ����Ϣ"<<endl;
		cout<<"5 ɾ��ѧ����Ϣ"<<endl;
		cout<<"6 �˳�"<<endl;
		cout<<"������ѡ��:";
		string ch;
		cin>>ch;
		////////////////////////////////////
		//����
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