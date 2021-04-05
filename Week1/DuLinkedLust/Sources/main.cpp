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
		"       *�������Ӧ���*\n"
		"|-----1.��ʼ������          -----|\n"
		"|-----2.�ں󷽲�����      -----|\n"
		"|-----3.��ǰ��������      -----|\n"
		"|-----4.�����������      -----|\n"
		"|-----5.ɾ����㲢ȡֵ      -----|\n"
		"|-----6.����������������  -----|\n"
		"**********************************\n\n\n");
	while (choice != 6 && flag1 != 0)
	{
		printf_s("���ѡ���ǣ�");
		while (scanf_s("%d", &choice) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			InitList_DuL(&head);
			p = head;
			q = head;
			printf_s("�ɹ���ʼ������\n");
			break;

		case 2:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			printf_s("��������������Ԫ�ظ�����\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			printf_s("��������������Ԫ�أ�\n");
			for (i = 0; i < n; i++)
			{
				while (scanf_s("%d", &data) == 0)
				{
					printf("�����˷Ƿ��ַ������������룺");
					while (getchar() != '\n');
				}
				p1 = CreateNode(data);
				InsertAfterList_DuL(p, p1);
				p = p->next;
			}
				printf_s("�ɹ�ʹ�ò�����\n");
			break;

		case 3:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			printf_s("��������������Ԫ�ظ�����\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			printf_s("��������������Ԫ�أ�\n");
			for (i = 0; i < n; i++)
			{
				while (scanf_s("%d", &data) == 0)
				{
					printf("�����˷Ƿ��ַ������������룺");
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
				printf_s("�ɹ�ʹ�ò�����\n");
			break;

		case 4:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("���Ȳ�����\n");
				break;
			}
			TraverseList_DuL(head->next, pointer);
			break;


		case 5:
			printf_s("������Ҫɾ���ڼ�����㣺\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			if (n < 1)
			{
				printf_s("��㲻���ڣ�\n");
				break;
			}
			p1 = head;
			for (i = 1; i < n; i++)
			{
				if (p1->next == NULL)
				{
					printf_s("��㲻���ڣ�\n");
					break;
				}
				p1 = p1->next;
			}
			if (p1->next != NULL)
				if (p1->next->next == NULL)
					p = p1;
			flag = DeleteList_DuL(p1, ele);
			if (flag == 1)
				printf_s("�����ɹ�\n");
			break;

		case 6:
			DestroyList_DuL(&head);
			printf_s("��������\n");
			break;
		default:
			printf_s("�޷�ʶ���������������ѡ��:\n");
		}
	}
	if(flag1==0)
		printf_s("�Ƿ�����\n");
	return 0;
}