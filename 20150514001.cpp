/**************************************
 *FILE    :D:\707wk\Practice-Code-For-CPP\20150514001.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015-5-14 ÏÂÎç 03:23:36
 *TEXT    :NULL
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
***************************************/

#include <stdio.h>

typedef struct node
{
	int num[5];
}DATA;

int main()
{
	int i;
	int j;
	int len;
	char ch;
	FILE* fpin;
	DATA num[100];
	fpin=fopen("input.txt","r");
	
	if(fpin==NULL)return 0;
	
	for(len=0;!feof(fpin);len++)
	{
		fscanf(fpin,"%d",&num[len].num[0]);
		for(i=1;!feof(fpin);i++)
		{
			if((ch=fgetc(fpin))=='\n')break;
			if(feof(fpin))break;
			fscanf(fpin,"%d",&num[len].num[i]);
		}
		if(i!=5)len--;
	}
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",num[i].num[j]);
		printf("\n");
	}
	
	return 0;
}