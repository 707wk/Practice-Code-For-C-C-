//使用三条线辅助判断
#include <stdio.h>

int num[8]={0};
int rowdia[8]={0};
int maindia[15]={0};
int vicedia[15]={0};
int n=0;

void funiction(int len)
{
	if(len==8)
	{
		n++;
		return ;
	}
	for(num[len]=0;num[len]<8;num[len]++)
		if(!rowdia[num[len]])
		if(!maindia[len+num[len]])
		if(!vicedia[7-len+num[len]])
		{
			rowdia[num[len]]=maindia[len+num[len]]=vicedia[7-len+num[len]]=1;
			funiction(len+1);
			rowdia[num[len]]=maindia[len+num[len]]=vicedia[7-len+num[len]]=0;
		}
}

int main()
{
	funiction(0);
	printf("%d\n",n);
	return 0 ;
}
