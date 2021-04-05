#include<stdio.h>
#include"LinkedList.h"
int main()
{
	int i, e, n, choice = 0, elem;
	ElemType data;
	Status flag;
	LinkedList head = NULL, p = NULL, q = NULL, p1 = NULL;
	LNode* value1;
	int* ele = &elem;
	void (*pointer)(ElemType);
	pointer = visit;
	printf_s(
		"**********************************\n"
		"       *请输入对应编号*\n"
		"|-----1.初始化链表          -----|\n"
		"|-----2.插入结点            -----|\n"
		"|-----3.遍历链表并输出      -----|\n"
		"|-----4.反向链接列表        -----|\n"
		"|-----5.调换奇偶顺序        -----|\n"
		"|-----6.找到中间结点        -----|\n"
		"|-----7.删除结点并取值      -----|\n"
		"|-----8.查询结点是否存在    -----|\n"
		"|-----9.判断链表是否成环    -----|\n"
		"|-----10.将现有链表成环     -----|\n"
		"|-----11.将环状链表解开     -----|\n"
		"|-----12.销毁链表，结束进程 -----|\n"
		"**********************************\n\n\n");

	while (choice != 12)
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
			InitList(&head);
			p = head;
			printf_s("成功初始化链表\n");
			break;

		case 2:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
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
					scanf_s("%d", &data);
					q = CreateNode(data);
					InsertList(p, q);
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
			if (head->next == NULL)
			{
				printf_s("请先插入结点\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			TraverseList(head->next, pointer);
			break;

		case 4:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请插入结点\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			ReverseList(&head);
			p = head;
			while (p->next != NULL)
				p = p->next;
			printf_s("链表已反转\n");
			break;

		case 5:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请插入结点\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			ReverseEvenList(&(head->next));
			printf_s("链表奇偶调换成功\n");
			break;

		case 6:
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
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			value1 = FindMidNode(&(head->next));
			printf_s("链表中间结点的数据为：%d\n", value1->data);
			break;

		case 7:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			printf_s("请输入要删除第几个结点：\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
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
			flag = DeleteList(p1, ele);
			if (flag == 1)
				printf_s("操作成功\n");
			break;
		case 8:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("请先解开环状链表\n");
				break;
			}
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请插入结点\n");
				break;
			}
			printf_s("请输入要查询的元素：");
			while (scanf_s("%d", &e) == 0)
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			flag = SearchList(head, e);
			if (flag == 1)
				printf("%d存在\n", e);
			else
				printf("%d不存在\n", e);
			break;

		case 9:
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
			flag = IsLoopList(head);
			if (flag == 1)
				printf("该链表是成环\n");
			else
				printf("该链表不成环\n");
			break;

		case 10:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请插入结点\n");
				break;
			}
			flag = TurnLoopLink(head, p);
			if (flag == 1)
				printf_s("操作成功！\n");
			else
				printf_s("操作失败！\n");
			break;

		case 11:
			if (head == NULL)
			{
				printf_s("请先初始化链表\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("请插入结点\n");
				break;
			}
			flag = Loop_off(head, p);
			if(flag == 1)
				printf_s("已解开\n");
			break;

		case 12:
			DestroyList(&head);
			printf_s("结束进程\n");
			break;
		default:
			printf_s("无法识别，请重新输入你的选择:");
		}
	}
	return 0;
}
