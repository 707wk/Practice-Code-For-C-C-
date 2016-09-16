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

//����ļ���
#define MAX_RESULT 100000
//����ļ�������
#define MAXSTRLEN 1000

struct systeminfo
{
	//�ļ��б�
	char result[MAX_RESULT][MAX_PATH];
	//�ļ���
	int count;
	//��ɾ�����ļ�����
	int deleted_num;
	//�����ļ�¼
	int normal_num;
	//�������ļ�¼����
	int illegal_num;
	//�ϲ��ļ�
	FILE* combin;
	//�������ļ�¼
	FILE* fp_illegal;
	//��ɾ�����ļ�
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
		//���ļ�
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

	// ��ʼ����
	snprintf(pattern,MAX_PATH,"%s%s",directory,"\\*.txt");

	hFind=FindFirstFile(pattern,&FindFileData);
	//�����ļ��������ļ����ú�����һ���ļ���(�������ļ���)ȥ����ָ���ļ�

	if(hFind==INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	do
	{
		snprintf(info.result[i++],MAX_PATH,"%s",FindFileData.cFileName);
	}while(FindNextFile(hFind,&FindFileData)!=0);
	// ���ҽ���
	FindClose(hFind);

	return i;
}

int main(int argc,char* argv[])
{
	int i=0;
	
	if(argc!=2)
	{
		printf("δ�����ļ�·��\n");
		//δ���ļ�������ִ�г���ͻ�������ֵ���
		return 0;
	}
	
	chdir(argv[1]);
	info.count=EnumFiles(argv[1]);

	if(info.count==0)
	{
		printf("δ�ҵ��ļ�\n");
		return 0;
	}
	system("mkdir after");

	info.deleted_num=0;
	info.normal_num =0;
	info.illegal_num=0;
	info.combin	=fopen("after\\combine.txt","w");
	info.fp_deleted=fopen("after\\deleted_files.txt","w");
	info.fp_illegal=fopen("after\\illegal_content.txt","w");

	printf("��%4d���ļ�\n",info.count);

	for(i=0;i<info.count;i++)
	{
		info.deleted_num+=combinfile(info.result[i]);
		printf("�Ѵ���%4d���ļ�\r",i+1);
	}

	fclose(info.combin);
	fclose(info.fp_deleted);
	fclose(info.fp_illegal);

	printf("\n�ϲ�%10d��������¼",info.normal_num);
	printf("\nɾ��%10d���հ��ļ�",info.deleted_num);
	printf("\nɾ��%10d���쳣��¼",info.illegal_num);
	printf("\n�������\n��ȷ�ϼ��˳�������");
	//Sleep(3000);
	getchar();
	return 0;
}
