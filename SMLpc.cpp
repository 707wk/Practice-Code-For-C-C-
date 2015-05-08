/**************************************
 *FILE    :SMLpc.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :5/8/2015
 *TEXT    :SML
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/

/*
//������������������
+1009
+1010
+2009
+3110
+4107
+1109
+4300
+1110
+4300
+0000
+0000
-99999

//���������������
+1007
+1008
+2007
+3008
+2109
+1109
+4300
+0000
+0000
+0000
-99999
*/

#include <iostream>

using namespace std;

#define READ        10 // �����ݶ��뵽�ڴ�ĳ��λ��read  
#define WRITE       11 // �����ݴ��ڴ�д����Ļwrite  
#define LOAD		20 // ���ڴ���ص��ۼ���load
#define STORE		21 // ���ۼ������ݴ洢��ָ���ڴ�store
#define ADD			30 // �ۼ����е�ֵ����ָ���ڴ��ֵaddition
#define SUBTRACT	31 // �ۼ����е�ֵ��ȥָ���ڴ��ֵsubtract
#define DIVIDE		32 // �ۼ�����ֵ����ָ���ڴ��ֵdivision
#define MULTIPLY	33 // �ۼ����е�ֵ����ָ��λ�õ�ֵmultiplication
#define BRANCH		40 // ת�Ƶ��ض��ڴ�λ��
#define BRANCHNEG	41 // ����ۼ���Ϊ����ת�Ƶ��ڴ�ָ��λ��
#define BRANCHZERO 	42 // ����ۼ���Ϊ�㣬ת�Ƶ��ڴ�ָ��λ��
#define HALT		43 // ֹͣ�����������

int main()
{
	int len;
	int acc=0;
	int memory[100]={0};

	cout << "*** Welcome to Simpletron! ***" << endl;  
    cout << "*** Please enter your program one instruction ***" << endl;  
    cout << "*** (or data word) at a time. I will type the ***" << endl;  
    cout << "*** location number and a question mark (?).  ***" << endl;  
    cout << "*** You then type the word for that location. ***" << endl;  
    cout << "*** Type the sentinel -99999 to stop entering ***" << endl;  
    cout << "*** your program. ***" << endl << endl; 
	
	for(len=0;;len++)
	{
		printf("%2d ? ",len);
		cin>>memory[len];
		if(memory[len]==-99999)
		{
			memory[len--]=0;
			break;
		}
	}

	cout << "*** Program loading completed ***" << endl;  
    cout << "*** Program execution begins  ***" << endl;  
	
	/*
	for(int i=0;i<len;i++)
	{
		cout<<memory[i]/100<<" "<<memory[i]%100<<endl;
	}
	cout<<len<<endl;
	*/
	
	for(int i=0;i<len;i++)
	{
		switch(memory[i]/100)
		{
			case READ:
			cout<<" ? ";
			cin>>memory[memory[i]%100];
			break;
			case WRITE:
			cout<<" # "<<memory[memory[i]%100]<<endl;
			break;
			
			case LOAD:
			acc=memory[memory[i]%100];
			break;
			case STORE:
			memory[memory[i]%100]=acc;
			break;
			
			case ADD:
			acc+=memory[memory[i]%100];
			break;
			case SUBTRACT:
			acc-=memory[memory[i]%100];
			break;
			case DIVIDE:
			acc/=memory[memory[i]%100];
			break;
			case MULTIPLY:
			acc*=memory[memory[i]%100];
			break;
			
			case BRANCH:
			i=memory[i]%100;
			i--;
			break;
			case BRANCHNEG:
			if(acc<0)
			{
				i=memory[i]%100;
				i--;
			}
			break;
			case BRANCHZERO:
			if(acc==0)
			{
				i=memory[i]%100;
				i--;
			}
			break;
			case HALT:
			goto _END;
			break;
		}
		
		cout<<endl;
		for(int j=0;j<30;j++)cout<<"=";
		cout<<endl;
		
		cout<<"REGISTERS:"<<endl;
		cout<<"accumulator:\t\t"<<acc<<endl;
		printf("counter:\t\t%04d\n",i);
		cout<<"instructionRegister:\t"<<memory[i+1]<<endl;
		cout<<"operationCode:\t\t"<<memory[i]/100<<endl;
		printf("operand:\t\t%02d\n",memory[i]%100);
		
		for(int j=0;j<73;j++)cout<<"=";
		cout<<endl;
	
		cout<<"MEMORY:"<<endl;
		cout<<"  ";
		for(int j=0;j<10;j++)
			printf("%6d ",j);
			cout<<endl;
		for(int cow=0;cow<10;cow++)
		{
			printf("%2d  ",cow);
			for(int row=0;row<10;row++)
			{
				if(memory[cow*10+row]<0)
					printf("%06d ",memory[cow*10+row]);
				else
					printf(" +%04d ",memory[cow*10+row]);
			}
			cout<<endl;
		}
		
		for(int j=0;j<73;j++)cout<<"=";
		cout<<endl<<endl;
		
	}
	_END:
	
	cout << "*** Program end  ***" << endl; 
	
	return 0;
}
