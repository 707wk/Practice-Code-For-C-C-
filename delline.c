/**************************************
 *FILE          :C:\Users\707wk\Desktop\�½��ļ���\test5.c
 *AUTHOR        :707wk
 *ORGANIZATION  :GT-Soft Studio
 *LAST-MODIFIED :2016/4/14 ���� 04:40:50
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//����ļ��� 
#define MAX_RESULT    100000
//����ļ������� 
#define MAXSTRLEN 1000

char result[MAX_RESULT][MAX_PATH];

void deletefiles(char* filesname,char* path)
{    
    FILE* fpin;
    FILE* fpout;
    
    char ch;
    char tmpinfiles[MAX_PATH];
    char tmpfiles[MAX_PATH];
    
    strcpy(tmpinfiles,path);
    strcat(tmpinfiles,"\\");
    strcat(tmpinfiles,filesname);
    
    strcpy(tmpfiles,path);
    strcat(tmpfiles,"\\after\\");
    strcat(tmpfiles,filesname);
    
    fpin=fopen(tmpinfiles,"r");
    if(fpin==NULL)
    {
    	printf("%s��ʧ��\n",tmpinfiles);
    	return ;
    }
    
    fpout=fopen(tmpfiles,"w");
    if(fpout==NULL)
    {
    	printf("%s����ʧ��\n",tmpfiles);
    	return ;
    }
    
    for(;fgetc(fpin)!='\n';);
    for(;fgetc(fpin)!='\n';);
    
    for(;(ch=fgetc(fpin))!=EOF;fputc(ch,fpout));
        
    fclose(fpin);
    fclose(fpout);
    //04130843.TXTSleep(100);
}

void EnumFiles(const char* directory,int* count)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    
    char** returnresult;
    char pattern[MAX_PATH];
    int i=0;
	
    // ��ʼ����
    strcpy(pattern,directory);
    strcat(pattern,"\\*.txt");
    hFind=FindFirstFile(pattern,&FindFileData);
    
    if(hFind==INVALID_HANDLE_VALUE)
    {
        *count=0;
        return ;
    }
    else 
    {
        do 
        {
            strcpy(result[i++],FindFileData.cFileName);
        }
        while(FindNextFile(hFind,&FindFileData)!=0);
    }
    
    // ���ҽ���
    FindClose(hFind);

    *count=i ;
}

int main(int argc,char* argv[])
{
    int count;
    int i=0;
    char tmpfiles[MAX_PATH];
    
    if(argc!=2)
    {
    	printf("δ�����ļ�·��\n");
    	return 0;
    }
    
    EnumFiles(argv[1],&count);

    if(count==0)
    {
    	printf("δ�ҵ��ļ�\n");
    	return 0; 
    }
    
    printf("��%4d���ļ�\n",count);
    
    strcpy(tmpfiles,argv[1]);
    strcat(tmpfiles,"\\after");
    CreateDirectory(tmpfiles,NULL);
    
    for(i=0;i<count;i++)
    {
    	deletefiles(result[i],argv[1]);
		printf("�Ѵ���%4d���ļ�\r",i+1);
    }
    printf("\n�������\n��ȷ�ϼ��˳�������");
    
    getchar();
    return 0 ;
}
