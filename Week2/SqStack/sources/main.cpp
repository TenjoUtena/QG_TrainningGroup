#include "SqStack.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
	int choice = 0, size;
	int* length = &size,*top = &choice;
	Status flag = ERROR;
	ElemType data = 0;
	ElemType* e = &data;
	struct SqStack SqS;	
	SqStack* Sq = &SqS;
	Sq->elem = NULL;
	void (*pointer)(ElemType);
	pointer = visit;
	printMenu();
	while (choice != 12)
	{
		printf_s("���ѡ���ǣ�");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("\n�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (choice)
		{
			case 1:
				printf("���������빹��ջ�Ĵ�С��");
				while (scanf_s("%d", &size) == 0 || getchar() != '\n')
				{
					printf("\n�����˷Ƿ��ַ������������룺");
					while (getchar() != '\n');
				}
				flag = initStack(Sq, size);
				if (flag == SUCCESS)
				{
					printf_s("��ʼ���ɹ���\n");
					break;
				}
				else
				{
					printf_s("��ʼ��ʧ�ܣ�\n");
					break;
				}

			case 2:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				printf_s("���������ݣ�");
				while (scanf_s("%d", &data) == 0 || getchar() != '\n')
				{
					printf("\n�����˷Ƿ��ַ������������룺");
					while (getchar() != '\n');
				}
				flag = pushStack(Sq, data);
				if (flag == SUCCESS)
				{
					printf_s("�ɹ���ջ��\n");
					break;
				}
				else
				{
					printf_s("ջ��������ջʧ�ܣ�\n");
					break;
				}

			case 3:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("ջ��û��Ԫ�أ�\n");
					break;
				}
				flag = popStack(Sq, e);
				if (flag == SUCCESS)
				{
					printf_s("Ԫ��%d�ѳ�ջ\n", *e);
					break;
				}
				else
				{
					printf_s("��ջʧ�ܣ�\n");
					break;
				}

			case 4:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				flag = stackLength(Sq, length);
				if (flag == SUCCESS)
				{
					printf_s("ջ�ĳ���Ϊ��%d\n", *length);
					break;
				}
				else
				{
					printf_s("���ʧ�ܣ�\n");
					break;
				}

			case 5:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				flag = isEmptyStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("ջΪ�գ�\n");
					break;
				}
				else
				{
					printf_s("ջ��Ϊ�գ�\n");
					break;
				}

			case 6:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("ջ��û��Ԫ�أ�\n");
					break;
				}
				flag = getTopStack(Sq, top);
				if (flag == SUCCESS)
				{
					printf_s("ջ��Ԫ��Ϊ��%d\n", *top);
					break;
				}
				else
				{
					printf_s("��ȡջ��Ԫ��ʧ�ܣ�\n");
					break;
				}

			case 7:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("��Ϊ��ջ��\n");
					break;
				}
				flag = clearStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("�ɹ����ջ��\n");
					break;
				}
				else
				{
					printf_s("���ջʧ�ܣ�\n");
					break;
				}

			case 8:
				if (Sq->elem == NULL)
				{
					printf_s("ջ�����ڣ�\n");
					break;
				}
				flag = destroyStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("�ɹ�����ջ��\n");
					break;
				}
				else
				{
					printf_s("����ջʧ�ܣ�\n");
					break;
				}

			case 9:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("ջ��û��Ԫ�أ�������ջ��\n");
					break;
				}
				TraverseSqStack(Sq, pointer);
				break;

			case 10:
				if (Sq->elem == NULL)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("ջ��û��Ԫ�أ�������ջ��\n");
					break;
				}
				TraverseSqStack_top(Sq, pointer);
				break;

			case 11:
				system("cls");
				printMenu();
				break;
			
			case 12:
				printf_s("��������\n");
				break;

			default:
				printf_s("�޷�ʶ��\n");
		}
	}
	system("pause");
	return 0;
}