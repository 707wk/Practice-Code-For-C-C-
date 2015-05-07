/**************************************
 *FILE    :SMLpc.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :5/7/2015
 *TEXT    :SML
 *EMAIL   :gtsoft_wk@foxmail.com
***************************************/

/*
//输入两个数输出最大数
1009
1010
2009
3110
4107
1109
4300
1110
4300
0000
0000

//输入两个数输出和
1007
1008
2007
3008
2109
1109
4300
0000
0000
0000
*/

#include <iostream>

using namespace std;

int main()
{
	int len;
	int acc;
	int element=0;
	int memory[2][100]={0};
	int order[2][100];
	
	char temp[4];

	cout << "*** Welcome to Simpletron! ***" << endl;  
    cout << "*** Please enter your program one instruction ***" << endl;  
    cout << "*** (or data word) at a time. I will type the ***" << endl;  
    cout << "*** location number and a question mark (?).  ***" << endl;  
    cout << "*** You then type the word for that location. ***" << endl;  
    cout << "*** Type the sentinel -99999 to stop entering ***" << endl;  
    cout << "*** your program. ***" << endl << endl; 
	
	for(len=0;;len++)
	{
		cin>>temp[0]>>temp[1]>>temp[2]>>temp[3];
		order[0][len]=(temp[0]-'0')*10+temp[1]-'0';
		order[1][len]=(temp[2]-'0')*10+temp[3]-'0';
		switch(order[0][len])
		{
			case 10:
			case 11:
			if(!memory[1][order[1][len]])
			{
				memory[1][order[1][len]]=1;
				element++;
			}
			break;
		}
		if(order[0][len]==0&&order[1][len]==0)element--;
		if(element<1)
		{
			len++;
			break;
		}
	}
	
	cout << "*** Program loading completed ***" << endl;  
    cout << "*** Program execution begins  ***" << endl;  
	
	/*
	for(int i=0;i<len;i++)
	{
		cout<<order[0][i]<<" "<<order[1][i]<<endl;
	}
	cout<<len<<endl;
	*/
	for(int i=0;i<len;i++)
	{
		switch(order[0][i])
		{
			case 10:
			cin>>memory[0][order[1][i]];
			break;
			case 11:
			cout<<memory[0][order[1][i]]<<endl;
			break;
			
			case 20:
			acc=memory[0][order[1][i]];
			break;
			case 21:
			memory[0][order[1][i]]=acc;
			break;
			
			case 30:
			acc+=memory[0][order[1][i]];
			break;
			case 31:
			acc-=memory[0][order[1][i]];
			break;
			case 32:
			acc/=memory[0][order[1][i]];
			break;
			case 33:
			acc*=memory[0][order[1][i]];
			break;
			
			case 40:
			i=order[1][i];
			i--;
			break;
			case 41:
			if(acc<0)
			{
				i=order[1][i];
				i--;
			}
			break;
			case 42:
			if(acc==0)
			{
				i=order[1][i];
				i--;
			}
			break;
			case 43:
			goto _END;
			break;
		}
	}
	_END:
	
	cout << "*** Program execution completed  ***" << endl;
	
	return 0;
}
