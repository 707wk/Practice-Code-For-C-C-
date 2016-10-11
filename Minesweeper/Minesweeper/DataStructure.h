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
	int x;                            //横坐标
	int y;                            //纵坐标
	int type;                         //类型 -1雷 >0空格
	int state;                        //状态 0未走 1已走
	int mineFlage;                    //标记为地雷 0否 1是
	double weight;                    //概率
};

//系统设置
struct serverset
{
	int height;
	int width;
	int mineNum;
	int unknowNum;
	struct mineNode* pMap;
};

#endif