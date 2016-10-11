// Minesweeper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataStructure.h"

struct serverset sysinfo;

//统计周围有多少地雷
int statisticsMine(int y,int x)
{
	int sum = 0;
	//1号位置
	if (y - 1 >= 0 && x - 1 >= 0 && sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].type == -1)sum++;
	//2号位置
	if (y - 1 >= 0 && sysinfo.pMap[(y - 1)*sysinfo.width + x].type == -1)sum++;
	//3号位置
	if (y - 1 >= 0 && x + 1 < sysinfo.width && sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].type == -1)sum++;
	
	//4号位置
	if (x - 1 >= 0 && sysinfo.pMap[y*sysinfo.width + (x - 1)].type == -1)sum++;
	//6号位置
	if (x + 1 < sysinfo.width&&sysinfo.pMap[y*sysinfo.width + (x + 1)].type == -1)sum++;
	
	//7号位置
	if (y + 1 < sysinfo.height&&x - 1 >= 0 && sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].type == -1)sum++;
	//8号位置
	if (y + 1 < sysinfo.height&&sysinfo.pMap[(y + 1)*sysinfo.width + x].type == -1)sum++;
	//9号位置
	if (y + 1 < sysinfo.height&&x + 1 < sysinfo.width &&sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].type == -1)sum++;

	return sum;
}

//创建地图
void createMap()
{
	int x;
	int y;

	//创建地雷
	for (int i = 0;i<sysinfo.mineNum;)
	{
		x = abs(rand()) % sysinfo.width;
		y = abs(rand()) % sysinfo.height;
		if (sysinfo.pMap[y*sysinfo.width + x].type == -1)
		{
			continue;
		}
		sysinfo.pMap[y*sysinfo.width + x].type = -1;
		i++;
	}

	//统计每格周围地雷数
	for (int i = 0;i < sysinfo.height;i++)
	{
		for (int j = 0;j < sysinfo.width;j++)
		{
			if (sysinfo.pMap[i*sysinfo.width + j].type != -1)
			{
				sysinfo.pMap[i*sysinfo.width + j].type = statisticsMine(i, j);
			}
		}
	}
}

void showmap()
{
	printf("[map]\n    ");
	for (int j = 0;j < sysinfo.width;j++)
	{
		printf("%2d", j + 1);
	}
	printf("\n   ");
	for (int j = 0;j < sysinfo.width + 1;j++)
	{
		printf("==");
	}
	printf("\n");
	for (int i = 0;i < sysinfo.height;i++)
	{
		printf(" %2d|", i + 1);
		for (int j = 0;j < sysinfo.width;j++)
		{
			if (sysinfo.pMap[i*sysinfo.width + j].type<0)
					printf_s(" #");
			else if (sysinfo.pMap[i*sysinfo.width + j].type == 0)
				printf_s("  ");
			else printf_s("%2d", sysinfo.pMap[i*sysinfo.width + j].type);
		}
		printf("|\n");

	}
	printf("   ");
	for (int j = 0;j < sysinfo.width + 1;j++)
	{
		printf("==");
	}
	printf("\n");
}

void showstep(int index)
{
	printf("[%3d:%3d]\n    ", index, sysinfo.unknowNum);
	for (int j = 0;j < sysinfo.width;j++)
	{
		printf("%2d",j+1);
	}
	printf("\n   ");
	for (int j = 0;j < sysinfo.width+1;j++)
	{
		printf("==");
	}
	printf("\n");
	for (int i = 0;i < sysinfo.height;i++)
	{
		printf(" %2d|", i + 1);
		for (int j = 0;j < sysinfo.width;j++)
		{
			if (sysinfo.pMap[i*sysinfo.width + j].state)
				if (sysinfo.pMap[i*sysinfo.width + j].type<0)
					if(sysinfo.pMap[i*sysinfo.width + j].mineFlage)
						printf_s(" #");
					else printf_s(" @");
				else if (sysinfo.pMap[i*sysinfo.width + j].type==0)
						printf_s("  ");
				else printf_s("%2d", sysinfo.pMap[i*sysinfo.width + j].type);
			else printf_s(" ?");
		}
		printf("|\n");
		
	}
	printf("   ");
	for (int j = 0;j < sysinfo.width + 1;j++)
	{
		printf("==");
	}
	printf("\n");
}

//翻开空白格子
void setGone(int index)
{
	int y = index / sysinfo.width;
	int x = index - index / sysinfo.width*sysinfo.width;
	//printf("y=%d x=%d ", y, x);
	//1号位置
	if (y - 1 >= 0 && x - 1 >= 0 && sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].state == 0)
	{ 
		sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].state = 1;
		sysinfo.unknowNum--;
	}
	//2号位置
	if (y - 1 >= 0 && sysinfo.pMap[(y - 1)*sysinfo.width + x].state == 0)
	{
		sysinfo.pMap[(y - 1)*sysinfo.width + x].state = 1;
		sysinfo.unknowNum--;
	}
	//3号位置
	if (y - 1 >= 0 && x + 1 < sysinfo.width && sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].state == 0)
	{
		sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].state = 1;
		sysinfo.unknowNum--;
	}
	
	//4号位置
	if (x - 1 >= 0 && sysinfo.pMap[y*sysinfo.width + (x - 1)].state == 0)
	{
		sysinfo.pMap[y*sysinfo.width + (x - 1)].state = 1;
		sysinfo.unknowNum--;
	}
	//6号位置
	if (x + 1 < sysinfo.width && sysinfo.pMap[y*sysinfo.width + (x + 1)].state == 0)
	{
		sysinfo.pMap[y*sysinfo.width + (x + 1)].state = 1;
		sysinfo.unknowNum--;
	}
	
	//7号位置
	if (y + 1 < sysinfo.height&&x - 1 >= 0 && sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].state == 0) 
	{
		sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].state = 1;
		sysinfo.unknowNum--;
	}
	//8号位置
	if (y + 1 < sysinfo.height && sysinfo.pMap[(y + 1)*sysinfo.width + x].state == 0)
	{
		sysinfo.pMap[(y + 1)*sysinfo.width + x].state = 1;
		sysinfo.unknowNum--;
	}
	//9号位置
	if (y + 1 < sysinfo.height&&x + 1 < sysinfo.width && sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].state == 0)
	{
		sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].state = 1;
		sysinfo.unknowNum--;
	}
}

//设置为雷
void setMine(int index)
{
	int y = index / sysinfo.width;
	int x = index - index / sysinfo.width*sysinfo.width;
	int value = 1;
	//1号位置
	if (y - 1 >= 0 && x - 1 >= 0)
	{
		if (sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].state == 0)
		{
			sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].state = 1;
			sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//2号位置
	if (y - 1 >= 0)
	{
		if (sysinfo.pMap[(y - 1)*sysinfo.width + x].state == 0)
		{
			sysinfo.pMap[(y - 1)*sysinfo.width + x].state = 1;
			sysinfo.pMap[(y - 1)*sysinfo.width + x].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//3号位置
	if (y - 1 >= 0 && x + 1 < sysinfo.width)
	{
		if (sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].state == 0)
		{
			sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].state = 1;
			sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//4号位置
	if (x - 1 >= 0)
	{
		if (sysinfo.pMap[y*sysinfo.width + (x - 1)].state == 0)
		{
			sysinfo.pMap[y*sysinfo.width + (x - 1)].state = 1;
			sysinfo.pMap[y*sysinfo.width + (x - 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//6号位置
	if (x + 1 < sysinfo.width)
	{
		if (sysinfo.pMap[y*sysinfo.width + (x + 1)].state == 0)
		{
			sysinfo.pMap[y*sysinfo.width + (x + 1)].state = 1;
			sysinfo.pMap[y*sysinfo.width + (x + 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//7号位置
	if (y + 1 < sysinfo.height&&x - 1 >= 0)
	{
		if (sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].state == 0)
		{
			sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].state = 1;
			sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//8号位置
	if (y + 1 < sysinfo.height)
	{
		if (sysinfo.pMap[(y + 1)*sysinfo.width + x].state == 0)
		{
			sysinfo.pMap[(y + 1)*sysinfo.width + x].state = 1;
			sysinfo.pMap[(y + 1)*sysinfo.width + x].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
	//9号位置
	if (y + 1 < sysinfo.height&&x + 1 < sysinfo.width)
	{
		if (sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].state == 0)
		{
			sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].state = 1;
			sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].mineFlage = value;
			if (value) { sysinfo.mineNum--;sysinfo.unknowNum--; }
		}
	}
}

//计算概率
double countProba(int index)
{
	double value = 0.0;
	int unknownNum = 0;
	int mineNum = 0;
	int y = index / sysinfo.width;
	int x = index - index / sysinfo.width*sysinfo.width;

	//1号位置
	if (y - 1 >= 0 && x - 1 >= 0)
	{
		if(sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y - 1)*sysinfo.width + (x - 1)].mineFlage)
			mineNum++;
	}
	//2号位置
	if (y - 1 >= 0)
	{
		if(sysinfo.pMap[(y - 1)*sysinfo.width + x].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y - 1)*sysinfo.width + x].mineFlage)
			mineNum++;
	}
	//3号位置
	if (y - 1 >= 0 && x + 1 < sysinfo.width)
	{
		if(sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y - 1)*sysinfo.width + (x + 1)].mineFlage)
			mineNum++;
	}
	//4号位置
	if (x - 1 >= 0)
	{
		if(sysinfo.pMap[y*sysinfo.width + (x - 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[y*sysinfo.width + (x - 1)].mineFlage)
			mineNum++;
	}
	//6号位置
	if (x + 1 < sysinfo.width)
	{
		if(sysinfo.pMap[y*sysinfo.width + (x + 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[y*sysinfo.width + (x + 1)].mineFlage)
			mineNum++;
	}
	//7号位置
	if (y + 1 < sysinfo.height&&x - 1 >= 0)
	{
		if(sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y + 1)*sysinfo.width + (x - 1)].mineFlage)
			mineNum++;
	}
	//8号位置
	if (y + 1 < sysinfo.height)
	{
		if(sysinfo.pMap[(y + 1)*sysinfo.width + x].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y + 1)*sysinfo.width + x].mineFlage)
			mineNum++;
	}
	//9号位置
	if (y + 1 < sysinfo.height&&x + 1 < sysinfo.width)
	{
		if(sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].state == 0)
			unknownNum++;
		if(sysinfo.pMap[(y + 1)*sysinfo.width + (x + 1)].mineFlage)
			mineNum++;
	}
	//printf("[type=%d mine=%d unknow=%d]", sysinfo.pMap[y*sysinfo.width + x].type, mineNum, unknownNum);
	return (sysinfo.pMap[y*sysinfo.width + x].type - mineNum)*1.0 / unknownNum;
}

void disposeMine()
{
	int x = abs(rand()) % sysinfo.width;
	int y = abs(rand()) % sysinfo.height;
	int mineNum = sysinfo.mineNum;
	int flage = -1;
	sysinfo.unknowNum = sysinfo.height*sysinfo.width;

	do {//使第一个点击的是空格
		x = abs(rand()) % sysinfo.width;
		y = abs(rand()) % sysinfo.height;
	} while (sysinfo.pMap[y*sysinfo.width + x].type != 0);

	printf("<y=%2d x=%2d unknowNum=%3d mineNum=%3d>\n", y + 1, x + 1, sysinfo.unknowNum, sysinfo.mineNum);
	sysinfo.unknowNum--;
	sysinfo.pMap[y*sysinfo.width + x].state = 1;
	for (int index=0;;index++)
	{
		//printf("%d ", sysinfo.unknowNum);
		for (int i = 0;i < sysinfo.height*sysinfo.width;i++)
		{
			//空格则翻开周围8个格子
			if (sysinfo.pMap[i].state == 1 &&sysinfo.pMap[i].type == 0)
			{
				setGone(i);
			}
			//数字则计算每个格子的概率
			else if (sysinfo.pMap[i].state == 1 && sysinfo.pMap[i].type > 0)
			{
				//printf("{%d %d}\t", i / sysinfo.width +1, i - i / sysinfo.width*sysinfo.width +1);
				if (countProba(i) == 1.0)
				{
					//printf("{%d %d}\t", i / sysinfo.width + 1, i - i / sysinfo.width*sysinfo.width + 1);
					//sysinfo.unknowNum--;
					setMine(i);
				}
				else if (countProba(i) == 0.0)
				{
					setGone(i);
				}
			}
		}
		if (flage == sysinfo.unknowNum)break;
		flage = sysinfo.unknowNum;
		showstep(index);
	}
	sysinfo.mineNum = mineNum;

	if (sysinfo.unknowNum > 0)
	{
		printf("接下来只能靠自己了\n");
	}
	else if (sysinfo.unknowNum == 0||sysinfo.unknowNum== mineNum)
	{
		printf("扫完所有雷了\n");
	}
	else
	{
		printf("程序出错了\n");
	}
}

int main()
{
	printf("输入地图高度/宽度/地雷数量:");
	scanf_s("%d %d %d", &sysinfo.height, &sysinfo.width, &sysinfo.mineNum);
	for(;sysinfo.height*sysinfo.width <= sysinfo.mineNum;)
	{
		printf_s("地图尺寸过小,请重新输入\n输入地图高度/宽度/地雷数量:");
		scanf_s("%d %d %d", &sysinfo.height, &sysinfo.width, &sysinfo.mineNum);
	}
	getchar();
	srand((unsigned int)time(NULL));
	sysinfo.pMap = (struct mineNode*)malloc(sizeof(struct mineNode)*sysinfo.height*sysinfo.width);

	//for (int i = 0;i < 5;i++)
	{
		memset(sysinfo.pMap, '\0', sizeof(struct mineNode)*sysinfo.height*sysinfo.width);
		createMap();
		showmap();
		printf("start:\n");
		disposeMine();
		printf("end>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	}
	for (;;);
	return 0;
}

