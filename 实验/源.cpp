#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
//yanghaodong creat
typedef struct linklist {
	struct linklist *next;
	char name[MAXSIZE];
	char number[MAXSIZE];
	char phone[20];

}node;
node *init()
{
	node *head;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void  display(node *head)
{
	node *p;
	p = head->next;
	if (!p)
	{
		printf("当前通讯录是空的\n");
	}
	printf("姓名                    学号                    联系方式\n");
	while (p)
		{
			printf("%s               %s               %s\n", p->name, p->number, p->phone);
			p = p->next;
		}
	printf("输入    0    返回\n");
	int index;
	scanf("%d", &index);
	
	
}
node *find(node *head, int i)
{
	int j = 0;
	node *p = head;
	if (i < 0)
	{
		printf("不存在这个点\n");
		return p;
	}
	else if (i == 0)
	{
		return p;
	}
	else {
		while (p&&i != j)
		{
			p = p->next;
			j++;
		}

	}
	return p;



}
void  findone(node *head, char *getname)
{
	int j = 0;
	node *p = head->next;
	while (p&&strcmp(getname, p->name) != 0)
	{
		p = p->next;
	}
	if (p) {
		printf("姓名：%s\n学号：%s\n联系方式：%s\n", p->
			name, p->number, p->phone);
		printf("输入    0    返回\n");
		int index;
		scanf("%d", &index);

	}
	else
	{
		printf("不存在\n");
		printf("输入    0    返回\n");
		int index;
		scanf("%d", &index);
	}
	



}
node *insert(node *head,int i)
{
	printf("请输入姓名；\n ");
	char getname[20];
	scanf("%s", getname);
	printf("请输入学号；\n ");
	char getnumber[20];
	scanf("%s", getnumber);
	printf("请输入电话号码；\n ");
	char getphone[20];
	scanf("%s", getphone);
	node *p, *q;;
	q = find(head, i);
	if (!q) {
		printf("不能插入");
		return head;
	}
	p = (node*)malloc(sizeof(node));
	strcpy(p->name, getname);
	strcpy(p->number, getnumber);
	strcpy(p->phone, getphone);
	p->next = q->next;
	q->next = p;
	return head;

}
node *dele(node *head, char *getname)
{
	
	node *p = head->next;
	node *pre = head;
	int index;
	while (p&&strcmp(getname, p->name) != 0) {
		pre = p;
		p = p->next;
	}
	if (p)
	{
		pre->next = p->next;
		free(p);
		
		printf("删除成功");
		printf("输入    0    返回返回\n");
		
		scanf("%d", &index);
		return head;

	}
	else
	{
		printf("无法删除,用户不存在\n");
	}
	printf("输入    0    返回\n");
	scanf("%d", &index);
	
}


void showall()
{
	printf("——————欢迎进入842班通讯录——————\n");
	printf("*                                         *\n");
	printf("*******************************************\n");
	printf("*     1  :    查看全班同学联系方式        *\n");
	printf("*     2  :    增加同学信息                *\n");
	printf("*     3  :    删除同学信息                *\n");
	printf("*     4  :    查询某个同学的信息          *\n");
	printf("*     0  :    退出                        *\n");
	printf("*******************************************\n");
	printf("                                           \n");
	printf("   请选择你的要求（0-4） :     ");
}

void  mainfirst(node *myclass)
{
	system("cls");
	int index;
	showall();
	int hi=1;
	index = getchar();
		switch (index)
		{
		case '1':
			system("cls");
			display(myclass);
			break;
		case '2':
			system("cls");
			while (hi!=0&&hi==1)
			{
				myclass = insert(myclass, 0);
				printf("继续添加请按    1    退出请按   0 \n");
				scanf("%d", &hi);
			}
						
			break;
		case '3':
			system("cls");
			printf("请输入要删除的用户名字：\n");
			char getname[20];
			scanf("%s", getname);
			myclass = dele(myclass,getname);
			break;
		case '4':
			system("cls");
			printf("请输入所查询用户姓名\n");
			char getnametwo[20];
			scanf("%s", getnametwo);
			findone(myclass, getnametwo);

			break;
		case '0':
			exit(0);
			break;

		default:mainfirst(myclass);
			break;



		}
 
}
int main()
{
	node *myclass=init();

	do
	{
		mainfirst(myclass);
	} while (1);


	return 0;
	


}