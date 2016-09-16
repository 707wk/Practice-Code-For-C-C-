/**************************************
 *FILE          :C:\Users\wk950\Desktop\atistical\atistical_707wk.c
 *AUTHOR        :707wk
 *ORGANIZATION  :GT-Soft Studio
 *LAST-MODIFIED :2016/9/16 15:54:16
 *TARGET        :C/C++
 *EMAIL         :gtsoft_wk@foxmail.com
 *LOGO          :
               #########                       
              ############                     
              #############                    
             ##  ###########                   
            ###  ###### #####                  
            ### #######   ####                 
           ###  ########## ####                
          ####  ########### ####               
        #####   ###########  #####             
       ######   ### ########   #####           
       #####   ###   ########   ######         
      ######   ###  ###########   ######       
     ######   #### ##############  ######      
    #######  ##################### #######     
    #######  ##############################    
   #######  ###### ################# #######   
   #######  ###### ###### #########   ######   
   #######    ##  ######   ######     ######   
   #######        ######    #####     #####    
    ######        #####     #####     ####     
     #####        ####      #####     ###      
      #####       ###        ###      #        
        ##       ####        ####              
***************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

//最大文件数
#define MAX_RESULT 100000
//最大文件名长度
#define MAXSTRLEN 1000

struct systeminfo
{
	//文件列表
	char result[MAX_RESULT][MAX_PATH];
	//文件数
	int count;
	//被删除的文件数量
	int deleted_num;
	//正常的记录
	int normal_num;
	//不正常的记录数量
	int illegal_num;
	//合并文件
	FILE* combin;
	//不正常的记录
	FILE* fp_illegal;
	//被删除的文件
	FILE* fp_deleted;
}info;

void checkdata(char* data,FILE* output)
{
	int A ;
	int B ;
	int C ;
	int D ;
	float E ;
	float F ;

	if(sscanf(data,"%d %d %d        %d  %f  %f",&A,&B,&C,&D,&E,&F)!=6)
	{
		fputs(data,info.fp_illegal);
		info.illegal_num++;
		return ;
	}
	if(D!=1&&D!=3)
	{
		fputs(data,info.fp_illegal);
		info.illegal_num++;
		return ;
	}
	fputs(data,output);
	fputs(data,info.combin);
	info.normal_num++;
}

int combinfile(char* filesname)
{
	char tmp[MAX_PATH];
	FILE* fpin=fopen(filesname,"r");

	char buf[1024];
	fgets(buf,1024,fpin);
	fgets(buf,1024,fpin);
	memset(buf, '\0', 1024);
	fgets(buf,1024,fpin);

	if(strlen(buf)<10)
	{
		//空文件
		fprintf(info.fp_deleted,"%s\n",filesname);
		fclose(fpin);
		return 1;
	}

	fprintf(info.fp_illegal,"%s\n",filesname);

	snprintf(tmp,MAX_PATH,"after\\%s",filesname);
	FILE* fpout=fopen(tmp,"w");
	checkdata(buf,fpout);

	for(;!feof(fpin);)
	{
		fgets(buf,1024,fpin);
		checkdata(buf,fpout);
	}

	fclose(fpin);
	fclose(fpout);
	
	return 0;
}

int EnumFiles(const char* directory)
{
	WIN32_FIND_DATA FindFileData ;
	HANDLE hFind ;

	char pattern[MAX_PATH];
	int i=0 ;

	// 开始查找
	snprintf(pattern,MAX_PATH,"%s%s",directory,"\\*.txt");

	hFind=FindFirstFile(pattern,&FindFileData);
	//根据文件名查找文件。该函数到一个文件夹(包括子文件夹)去搜索指定文件

	if(hFind==INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	do
	{
		snprintf(info.result[i++],MAX_PATH,"%s",FindFileData.cFileName);
	}while(FindNextFile(hFind,&FindFileData)!=0);
	// 查找结束
	FindClose(hFind);

	return i;
}

int main(int argc,char* argv[])
{
	int i=0;
	
	if(argc!=2)
	{
		printf("未输入文件路径\n");
		//未将文件夹拖向执行程序就会出现这种弹窗
		return 0;
	}
	
	chdir(argv[1]);
	info.count=EnumFiles(argv[1]);

	if(info.count==0)
	{
		printf("未找到文件\n");
		return 0;
	}
	system("mkdir after");

	info.deleted_num=0;
	info.normal_num =0;
	info.illegal_num=0;
	info.combin	=fopen("after\\combine.txt","w");
	info.fp_deleted=fopen("after\\deleted_files.txt","w");
	info.fp_illegal=fopen("after\\illegal_content.txt","w");

	printf("共%4d个文件\n",info.count);

	for(i=0;i<info.count;i++)
	{
		info.deleted_num+=combinfile(info.result[i]);
		printf("已处理%4d个文件\r",i+1);
	}

	fclose(info.combin);
	fclose(info.fp_deleted);
	fclose(info.fp_illegal);

	printf("\n合并%10d个正常记录",info.normal_num);
	printf("\n删除%10d个空白文件",info.deleted_num);
	printf("\n删除%10d个异常记录",info.illegal_num);
	printf("\n处理完成\n按确认键退出本程序");
	//Sleep(3000);
	getchar();
	return 0;
}
