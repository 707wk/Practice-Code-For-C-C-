/**************************************
 *FILE    :007.c
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :4/8/2015
***************************************/
/*
读取文件数据排序输出文件
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int i ;
	int j;
	int num[MAXNUM];
	FILE* datain=fopen("input.txt","r");
	FILE* dataout=fopen("output.txt","w");
	
	for(i=0;!feof(datain);i++)
	{
		fscanf(datain,"%d",num+i);
	}

	qsort(num,i,sizeof(num[0]),cmp);
	
	for(j=0;j<i;j++)
	{
		printf("%d ",num[j]);
		fprintf(dataout,"%d ",num[j]);
	}
	
	fclose(datain);
	fclose(dataout);
	
	return 0 ;
}
