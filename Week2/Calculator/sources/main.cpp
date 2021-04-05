#include <stdio.h>
#include "Calculator.h"
#include <malloc.h>
#include <stdlib.h>

int main()
{
	int flag, choice=0,judge=0;
	char exp[MAXSIZE] = {'\0'};
	double ele, * e = &ele;
	SqStack* exp_suf = (SqStack*)malloc(sizeof(SqStack));
	initStack(exp_suf, MAXSIZE);
	void (*pointer)(char);
	pointer = visit;
	PrintMenu();
	while (choice != 5)
	{
		printf_s("���ѡ���ǣ�");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("�����˷Ƿ��ַ����������������ѡ��");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			clearStack(exp_suf);
			printf_s("��������׺���ʽ��");
			gets_s(exp);
			flag = Check_1(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			flag = Check_2(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			flag = Check_3(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			flag = Check_4(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			flag = Check_5(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			flag = Check_6(exp);
			if (flag == ERROR)
			{
				printf_s("����ʧ�ܣ�\n");
				break;
			}
			else
			{
				judge = 0;
				printf_s("����ɹ���\n");
				break;
			}

		case 2:
			if (exp[0] == '\0')
			{
				printf_s("����������׺���ʽ��\n");
				break;
			}
			if (flag == ERROR)
			{
				printf_s("������������׺���ʽ��\n");
				break;
			}
			if(judge == 0)
			{
				exp_suf = change(exp, exp_suf);
				printf_s("��׺���ʽΪ��\n");
				TraverseSqStack(exp_suf, pointer);
				judge = 1;
				break;
			}
			if (judge == 1)
			{
				printf_s("��׺���ʽΪ��\n");
				TraverseSqStack(exp_suf, pointer);
				printf_s("\n");
				break;
			}

		case 3:
			if (exp[0] == '\0')
			{
				printf_s("����������׺���ʽ��\n");
				break;
			}
			if (judge == 0)
			{
				exp_suf = change(exp, exp_suf);
				judge = 1;
			}
			if (Calculate(exp_suf, e) == SUCCESS)
			{
				printf_s("����Ľ��Ϊ:%lf", *e);
				printf_s("\n");
				break;
			}
			else
				break;

		case 4:
			system("cls");
			PrintMenu();
			break;

		case 5:
			printf_s("��������\n");
			break;

		default:
			printf_s("�޷�ʶ��\n");
		}
	}
	system("pause");
	return 0;
}