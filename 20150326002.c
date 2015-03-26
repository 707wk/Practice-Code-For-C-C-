#include <stdio.h>

int a[20];
int b[20];
int n;

int checknum(int m)
{
	int len;
	if(m==2)return 1;
	for(len=2;len*len<=m;len++)
		if(m%len==0)return 0;
	return 1;
	
}
void dfsnum(int j)
{
	int i;
	if(j==n&&checknum(a[n]+1))
	{
		for(i=1;i<n;i++)
		printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	for(i=2;i<=n;i++)
	{
		if(b[i]!=0&&checknum(a[j]+i))
		{
			a[j+1]=i;
			b[i]=0;
			dfsnum(j+1);
			b[i]=i;
		}
	}
}
int main()
{
	int len;
	a[1]=1;
	for(len=1;len<=20;len++)b[len]=len;
	for(len=1;scanf("%d",&n)!=EOF;len++)
	{
		printf("Case %d:\n",len);
		if(!(n%2))dfsnum(1);
		printf("\n");
	}
	return 0;
}
