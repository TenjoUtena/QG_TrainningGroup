#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int choice = 0;
	Status flag = ERROR;
	ElemType data = 0;
	ElemType* e = &data;
	int* length = &choice, *ele = &choice;
	LinkStack *top = (LinkStack*)malloc(sizeof(LinkStack));
	top->count = -1;
	void (*pointer)(ElemType);
	pointer = visit;
	printMenu();
	while (choice != 11)
	{
		printf_s("���ѡ���ǣ�");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (choice)
		{
			case 1:
				flag = initLStack(top);
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

			case 2 :
				if (top->count == -1)
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
				flag = pushLStack(top, data);
				if (flag = SUCCESS)
				{
					printf_s("�ɹ���ջ��\n");
					break;
				}
				else
				{
					printf_s("��ջʧ�ܣ�\n");
					break;
				}

			case 3:
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (top->count == 0)
				{
					printf_s("ջ��û��Ԫ�أ�\n");
					break;
				}
				flag = popLStack(top, e);
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
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				flag = LStackLength(top, length);
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
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				flag = isEmptyLStack(top);
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
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (top->count == 0)
				{
					printf_s("ջ��û��Ԫ�أ�\n");
					break;
				}
				flag = getTopLStack(top, ele);
				if (flag == SUCCESS)
				{
					printf_s("ջ��Ԫ��Ϊ��%d\n", *ele);
					break;
				}
				else
				{
					printf_s("��ȡջ��Ԫ��ʧ�ܣ�\n");
					break;
				}

			case 7:
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if (top->count == 0)
				{
					printf_s("��Ϊ��ջ��\n");
					break;
				}
				flag = clearLStack(top);
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
				if (top->count == -1)
				{
					printf_s("ջ�����ڣ�\n");
					break;
				}
				flag = destroyLStack(top);
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
				if (top->count == -1)
				{
					printf_s("���ȳ�ʼ��ջ��\n");
					break;
				}
				if(top->count == 0)
				{
					printf_s("ջ��û��Ԫ�أ�������ջ��\n");
					break;
				}
				TraverseStack(top, pointer);
				break;

			case 10 :
				system("cls");
				printMenu();
				break;

			case 11 :
				printf_s("��������\n");
				break;

			default:
				printf_s("�޷�ʶ��\n");
		}

	}
	system("pause");
	return 0;
}