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
		"       *�������Ӧ���*\n"
		"|-----1.��ʼ������          -----|\n"
		"|-----2.������            -----|\n"
		"|-----3.�����������      -----|\n"
		"|-----4.���������б�        -----|\n"
		"|-----5.������ż˳��        -----|\n"
		"|-----6.�ҵ��м���        -----|\n"
		"|-----7.ɾ����㲢ȡֵ      -----|\n"
		"|-----8.��ѯ����Ƿ����    -----|\n"
		"|-----9.�ж������Ƿ�ɻ�    -----|\n"
		"|-----10.����������ɻ�     -----|\n"
		"|-----11.����״����⿪     -----|\n"
		"|-----12.���������������� -----|\n"
		"**********************************\n\n\n");

	while (choice != 12)
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
			InitList(&head);
			p = head;
			printf_s("�ɹ���ʼ������\n");
			break;

		case 2:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
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
					scanf_s("%d", &data);
					q = CreateNode(data);
					InsertList(p, q);
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
			if (head->next == NULL)
			{
				printf_s("���Ȳ�����\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			TraverseList(head->next, pointer);
			break;

		case 4:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("�������\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			ReverseList(&head);
			p = head;
			while (p->next != NULL)
				p = p->next;
			printf_s("�����ѷ�ת\n");
			break;

		case 5:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("�������\n");
				break;
			}
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			ReverseEvenList(&(head->next));
			printf_s("������ż�����ɹ�\n");
			break;

		case 6:
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
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			value1 = FindMidNode(&(head->next));
			printf_s("�����м��������Ϊ��%d\n", value1->data);
			break;

		case 7:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			printf_s("������Ҫɾ���ڼ�����㣺\n");
			while (scanf_s("%d", &n) == 0)
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
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
			flag = DeleteList(p1, ele);
			if (flag == 1)
				printf_s("�����ɹ�\n");
			break;
		case 8:
			flag = IsLoopList(head);
			if (flag == 1)
			{
				printf_s("���Ƚ⿪��״����\n");
				break;
			}
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("�������\n");
				break;
			}
			printf_s("������Ҫ��ѯ��Ԫ�أ�");
			while (scanf_s("%d", &e) == 0)
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			flag = SearchList(head, e);
			if (flag == 1)
				printf("%d����\n", e);
			else
				printf("%d������\n", e);
			break;

		case 9:
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
			flag = IsLoopList(head);
			if (flag == 1)
				printf("�������ǳɻ�\n");
			else
				printf("�������ɻ�\n");
			break;

		case 10:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("�������\n");
				break;
			}
			flag = TurnLoopLink(head, p);
			if (flag == 1)
				printf_s("�����ɹ���\n");
			else
				printf_s("����ʧ�ܣ�\n");
			break;

		case 11:
			if (head == NULL)
			{
				printf_s("���ȳ�ʼ������\n");
				break;
			}
			if (head->next == NULL)
			{
				printf_s("�������\n");
				break;
			}
			flag = Loop_off(head, p);
			if(flag == 1)
				printf_s("�ѽ⿪\n");
			break;

		case 12:
			DestroyList(&head);
			printf_s("��������\n");
			break;
		default:
			printf_s("�޷�ʶ���������������ѡ��:");
		}
	}
	return 0;
}
