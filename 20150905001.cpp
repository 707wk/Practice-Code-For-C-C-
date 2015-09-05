/**************************************
 *FILE    :C:\Users\Administrator\desktop\214\main.cpp
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/9/5 10:01:36
 *TEXT    :NULL
 *EMAIL   :gtsoft_wk@foxmail.com
 *CODE    :https://github.com/707wk
 *LOGO    :
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
      #####      ;###        ###      #        
        ##       ####        ####              

***************************************/

#include <stdio.h>

#define N 30000
#define M 5000

int score[N];

int main()
{
	int len=0;
	int operatenum=0;
	int A;
	int B;
	
	scanf("%d%d",&len,&operatenum);
	
	for(int i=0;i<len;i++)
	{
		scanf("%d",score+i);
	}
	
	for(int i=0;i<operatenum;i++)
	{
		char operate;
		getchar();
		scanf("%c%d%d",&operate,&A,&B);
		if(operate=='Q')
		{
			int maxindex=A-1;
			for(int j=A;j<B;j++)
			{
				if(*(score+maxindex)<*(score+j))maxindex=j;
			}
			printf("%d\n",*(score+maxindex));
		}	
		else
		{
			score[A-1]=B;
		}
	}
	
	return 0;
}
