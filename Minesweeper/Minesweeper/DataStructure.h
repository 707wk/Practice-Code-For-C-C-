/**************************************
 *FILE          :T:\Minesweeper\Minesweeper\DataStructure.h
 *AUTHOR        :707wk
 *ORGANIZATION  :GT-Soft Studio
 *LAST-MODIFIED :2016/10/6 19:37:36
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

#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

#include "StdAfx.h"
#include <iostream>

using namespace std;

struct mineNode
{
	int x;                            //������
	int y;                            //������
	int type;                         //���� -1�� >0�ո�
	int state;                        //״̬ 0δ�� 1����
	int mineFlage;                    //���Ϊ���� 0�� 1��
	double weight;                    //����
};

//ϵͳ����
struct serverset
{
	int height;
	int width;
	int mineNum;
	int unknowNum;
	struct mineNode* pMap;
};

#endif