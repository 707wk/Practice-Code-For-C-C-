#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <unistd.h>

#define FILEPATH_MAX 4096+1

struct node
{
	char catalogname[FILEPATH_MAX];
	struct node* next;
};

struct catalogue
{
	struct node* head;
	struct node* end;

	int catalogSum;
};

struct catalogue catalog;

void initialization()
{
	char catalogname[FILEPATH_MAX];
	//getcwd(catalogname,FILEPATH_MAX);
	
	strcpy(catalogname,"/home/707wk/");

	catalog.head=NULL;
	catalog.end=NULL;
	catalog.catalogSum=0;

	catalog.head=(struct node*)malloc(sizeof(struct node));
	strcpy(catalog.head->catalogname,catalogname);
	catalog.end=catalog.head;
	catalog.head->next=catalog.end;
	catalog.end->next=catalog.head;
	catalog.catalogSum++;
}

void swapnode()
{
	struct node* tmp;

	tmp=catalog.head->next->next;
	catalog.head->next->next=catalog.head;
	catalog.head=catalog.head->next;
	catalog.head->next->next=tmp;
}

void addnode(char option[])
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	strcpy(tmp->catalogname,option);

	tmp->next=catalog.head;
	catalog.head=tmp;
	catalog.end->next=catalog.head;
	
	catalog.catalogSum++;
}

void movenode(int index)
{
	int i;
	for(i=0;i<index;i++)
	{
		catalog.end=catalog.head;
		catalog.head=catalog.head->next;
		//catalog.end=catalog.end->next;
	}
}

void pushd(char option[])
{
	int index;

	if(option[0]=='\0')
	{
		swapnode();
	}
	else if(option[0]=='/')
	{
		addnode(option);
	}
	else if(option[0]=='+')
	{
		sscanf(option+1,"%d",&index);
		movenode(index);
	}
	else if(option[0]=='-')
	{
		sscanf(option+1,"%d",&index);
		movenode(catalog.catalogSum-1-index);
	}//*/
	else printf("not found\n");
}

void delhead()
{
	struct node* tmpfree=catalog.head;
	catalog.head=catalog.head->next;
	free(tmpfree);
	catalog.catalogSum--;
}

void subnode(int index)
{
	struct node* tmp=catalog.head;
	struct node* tmpfree;

	int i;

	for(i=1;i<index;i++)
	{
		tmp=tmp->next;
	}

	tmpfree=tmp->next;
	tmp->next=tmp->next->next;
	free(tmpfree);

	catalog.catalogSum--;
}

void popd(char option[])
{
	int index;
	
	if(option[0]=='\0')
	{
		delhead();
	}
	else if(option[0]=='+')
	{
		sscanf(option+1,"%d",&index);
		subnode(index);
	}
	//else if(option[0]=='-')
	else printf("not found\n");
}

void dirs()
{
	int i;
	struct node* tmp=catalog.head;

	printf("\t#%s #%s #%d\n\t",
			catalog.head->catalogname,
			catalog.end->catalogname,
			catalog.catalogSum); 
	for(i=1;i<catalog.catalogSum;i++)
	{
		printf("%s ",tmp->catalogname);
		tmp=tmp->next;
	}
	printf("%s\n",tmp->catalogname);
}

void freenode()
{
	struct node* tmp;
	int i;
	
	for(i=0;i<catalog.catalogSum;i++)
	{
		tmp=catalog.head;
		free(tmp);
		catalog.head=catalog.head->next;
	}
}

int main()
{
	char inputstr[FILEPATH_MAX];
	char command[FILEPATH_MAX];
	char option[FILEPATH_MAX];

	initialization();
	
	addnode("/bin");
	addnode("/boot");
	addnode("/etc");
	addnode("/mnt");
	addnode("/tmp");
	addnode("/home");
	addnode("/lib");
	
	dirs();

	for(;;)
	{
		option[0]='\0';
		gets(inputstr);
		sscanf(inputstr,"%s %s",command,option);
		if(strcmp(command,"pushd")==0)
		{
			pushd(option);
			dirs();
		}
		else if(strcmp(command,"popd")==0)
		{
			printf("unfinished");
			//popd(option);
			//dirs();
		}
		else if(strcmp(command,"dirs")==0)
		{
			dirs();
		}
		else if(strcmp(command,"exit")==0)
		{
			break;
		}
		else system(inputstr);
	}

	freenode();

	return 0;
}
