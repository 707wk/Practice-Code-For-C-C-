#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int coutlines(char *filename)
{
	ifstream tempfiles(filename,ios::in);
	int len=0;
	string temp;
	
	if(tempfiles.fail())return 0;
	else
	{
		for(;getline(tempfiles,temp,'\n');len++);
		tempfiles.close();
		return len;
	}
}

int main()
{
	int i;
	int len=coutlines("input.txt");
	ifstream datain("input.txt",ios::in);
	ofstream dataout("out.txt",ios::out);
	int *num=new int[len];
	cout<<len<<endl;

	for(i=0;i<len;i++)
	{
		datain>>num[i];
	}
	
	sort(num,num+len);
	
	for(i=0;i<len;i++)
	{
		cout<<num[i]<<" ";
		dataout<<num[i]<<" ";
	}
	
	datain.close();
	dataout.close();
	delete num;
	
	return 0;
}
