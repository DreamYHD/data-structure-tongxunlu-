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
		printf("��ǰͨѶ¼�ǿյ�\n");
	}
	printf("����                    ѧ��                    ��ϵ��ʽ\n");
	while (p)
		{
			printf("%s               %s               %s\n", p->name, p->number, p->phone);
			p = p->next;
		}
	printf("����    0    ����\n");
	int index;
	scanf("%d", &index);
	
	
}
node *find(node *head, int i)
{
	int j = 0;
	node *p = head;
	if (i < 0)
	{
		printf("�����������\n");
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
		printf("������%s\nѧ�ţ�%s\n��ϵ��ʽ��%s\n", p->
			name, p->number, p->phone);
		printf("����    0    ����\n");
		int index;
		scanf("%d", &index);

	}
	else
	{
		printf("������\n");
		printf("����    0    ����\n");
		int index;
		scanf("%d", &index);
	}
	



}
node *insert(node *head,int i)
{
	printf("������������\n ");
	char getname[20];
	scanf("%s", getname);
	printf("������ѧ�ţ�\n ");
	char getnumber[20];
	scanf("%s", getnumber);
	printf("������绰���룻\n ");
	char getphone[20];
	scanf("%s", getphone);
	node *p, *q;;
	q = find(head, i);
	if (!q) {
		printf("���ܲ���");
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
		
		printf("ɾ���ɹ�");
		printf("����    0    ���ط���\n");
		
		scanf("%d", &index);
		return head;

	}
	else
	{
		printf("�޷�ɾ��,�û�������\n");
	}
	printf("����    0    ����\n");
	scanf("%d", &index);
	
}


void showall()
{
	printf("��������������ӭ����842��ͨѶ¼������������\n");
	printf("*                                         *\n");
	printf("*******************************************\n");
	printf("*     1  :    �鿴ȫ��ͬѧ��ϵ��ʽ        *\n");
	printf("*     2  :    ����ͬѧ��Ϣ                *\n");
	printf("*     3  :    ɾ��ͬѧ��Ϣ                *\n");
	printf("*     4  :    ��ѯĳ��ͬѧ����Ϣ          *\n");
	printf("*     0  :    �˳�                        *\n");
	printf("*******************************************\n");
	printf("                                           \n");
	printf("   ��ѡ�����Ҫ��0-4�� :     ");
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
				printf("��������밴    1    �˳��밴   0 \n");
				scanf("%d", &hi);
			}
						
			break;
		case '3':
			system("cls");
			printf("������Ҫɾ�����û����֣�\n");
			char getname[20];
			scanf("%s", getname);
			myclass = dele(myclass,getname);
			break;
		case '4':
			system("cls");
			printf("����������ѯ�û�����\n");
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