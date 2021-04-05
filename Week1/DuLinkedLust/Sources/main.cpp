#include<stdio.h>
#include"duLinkedList.h"
int main()
{
	int i, e, n, choice = 0, elem;
	ElemType data;
	Status flag;
	int flag1 = 1;
	flag = SUCCESS;
	DuLinkedList head = NULL, p = NULL, q = NULL, p1=NULL, q1=NULL;
	DuLNode* value1;
	int* ele = &elem;
	void (*pointer)(ElemType);
	pointer = visit;
	printf_s(
		"**********************************\n"
		"       *请输入对应编号*\n"
		"|-----1.初始化链表          -----|\n"
		"|-----2.在后方插入结点      -----|\n"
		"|-----3.在前方插入结点      -----|\n"
		"|-----4.遍历链表并输出      -----|\n"
		"|-----5.删除结点并取值      -----|\n"
		"|-----6.销毁链表，结束进程  -----|\n"
		"**********************************\n\n\n");
	while (choice != 6 && flag1 != 0)
	{
		printf_s("你的选择是：");
		while (scanf_s("%d", &choice) == 0)
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			InitList_DuL(&head);
			p = head;
			q = head;
			printf_s("成功初始化链表\n");
			break;

		case 2:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			printf_s("请输入你想插入的元素个数：\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			printf_s("请输入你想插入的元素：\n");
			for (i = 0; i < n; i++)
			{
				while (scanf_s("%d", &data) == 0)
				{
					printf("输入了非法字符，请重新输入：");
					while (getchar() != '\n');
				}
				p1 = CreateNode(data);
				InsertAfterList_DuL(p, p1);
				p = p->next;
			}
				printf_s("成功使用插入结点\n");
			break;

		case 3:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			printf_s("请输入你想插入的元素个数：\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			printf_s("请输入你想插入的元素：\n");
			for (i = 0; i < n; i++)
			{
				while (scanf_s("%d", &data) == 0)
				{
					printf("输入了非法字符，请重新输入：");
					while (getchar() != '\n');
				}
				q1 = CreateNode(data);
				InsertBeforeList_DuL(q, q1);
				q = q->prior;
			}
			if (head->next == NULL)
			{
				p = head->prior;
				head->prior->next = NULL;
			}
			else
			{
				head->prior->next = head->next;
				head->next->prior = head->prior;
			}
			head->next = q;
			head->prior = NULL;
			q->prior = head;
			q = head;
			if (flag1 != 0)
				printf_s("成功使用插入结点\n");
			break;

		case 4:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请先插入结点\n");
				break;
			}
			TraverseList_DuL(head->next, pointer);
			break;


		case 5:
			printf_s("请输入要删除第几个结点：\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			if (n < 1)
			{
				printf_s("结点不存在：\n");
				break;
			}
			p1 = head;
			for (i = 1; i < n; i++)
			{
				if (p1->next == NULL)
				{
					printf_s("结点不存在：\n");
					break;
				}
				p1 = p1->next;
			}
			if (p1->next != NULL)
				if (p1->next->next == NULL)
					p = p1;
			flag = DeleteList_DuL(p1, ele);
			if (flag == 1)
				printf_s("操作成功\n");
			break;

		case 6:
			DestroyList_DuL(&head);
			printf_s("结束进程\n");
			break;
		default:
			printf_s("无法识别，请重新输入你的选择:\n");
		}
	}
	if(flag1==0)
		printf_s("非法输入\n");
	return 0;
}