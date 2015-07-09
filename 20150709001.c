/**************************************
 *FILE    :D:\c\main.c
 *PROJECT :NULL
 *AUTHOR  :707wk
 *CREATED :2015/7/9 19:28:40
 *TEXT    :three four + five six = nine zero
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
#include <string.h>

char strnum[][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int chartoint(char* str)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(strcmp(strnum[i],str)==0)return i;
	}
	return 0;
}

int operator(int operation,int num[])
{
	switch(operation)
	{
		case 1:
			if(!num[1])return 0;
			return num[0]/num[1];
		case 2:
			return num[0]*num[1];
		case 3:
			return num[0]-num[1];
		case 4:
			return num[0]+num[1];
	}
	return 0;
}

void inputchar(int num)
{
	int i;
	char str[10]="";
	itoa(num,str,10);
	for(i=0;str[i];i++)
	{
		printf("%s ",strnum[str[i]-'0']);
	}
	printf("\n");
}

int main()
{
	int sum;
	int num[2];
	int index;
	int operation;
	char tmp[100];

	for(;;)
	{
		operation=num[0]=num[1]=0;
		for(index=0;scanf("%s",tmp);)
		{
			switch(tmp[0])
			{
				case '+':
					operation++;
				case '-':
					operation++;
				case '*':
					operation++;
				case '/':
					operation++;
					index++;
				break;
				case '=':
					if(num[0]==0&&num[1]==0)return ;
					sum=operator(operation,num);
					inputchar(sum);
				break;
				default :
					num[index]=num[index]*10+chartoint(tmp);
				break;
			}
		}
	}
	return 0;
}
