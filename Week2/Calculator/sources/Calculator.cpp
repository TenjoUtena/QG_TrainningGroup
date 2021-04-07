#include <stdio.h>
#include "Calculator.h"
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//��ӡ�˵�
void PrintMenu()
{
	printf_s(
		"***********************************************\n"
		"            *��ӭʹ���������������*\n"
		"***********************************************\n"
		" ||          ���뷶����5+(9*8+4)/2           ||\n"
		"***********************************************\n"
		" ||  ��ʾ��Ҫ��Ӣ�����뷨�����Ҳ����пո�    ||\n"
		" ||  ��ʾ��ֻ�����Ӽ��˳�Ŷ��֧�ָ�������    ||\n"
		" ||  ��ʾ������()��ʱ�����Ҫ�Ȱ�һ��shiftŶ ||\n"
		" ||           �������Ӣ�����뷨��           ||\n"
		"***********************************************\n"
		" ||             ��������Ӧ��ѡ��             ||\n"
		" ||              1.������ʽ                ||\n"
		" ||              2.���׺���ʽ              ||\n"
		" ||              3.������ʽ���            ||\n"
		" ||              4.����                      ||\n"
		" ||              5.��������                  ||\n"
		"***********************************************\n");
}

//��ʼ��ջ
void initStack(SqStack* s, int sizes)
{
	s->elem = (char*)malloc(sizeof(char) * sizes);
	s->top = -1;
	s->size = sizes;
}
void initStack_double(SqStack_double* s, int sizes)
{
	s->elem = (double*)malloc(sizeof(double) * sizes);
	s->top = -1;
	s->size = sizes;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
}

//��ջ
void pushStack(SqStack* s, char data)
{
	s->top++;
	s->elem[s->top] = data;
}
void pushStack_double(SqStack_double* s, double data)
{
	s->top++;
	s->elem[s->top] = data;
}

//��ջ
void popStack(SqStack* s)
{
	(s->top)--;
}
void popStack_double(SqStack_double* s)
{
	(s->top)--;
}

//�õ�ջ��Ԫ��
char getTopStack(SqStack* s)
{
	char e;
	e = (s->elem)[s->top];
	return e;
}
double getTopStack_double(SqStack_double* s)
{
	double e;
	e = (s->elem)[s->top];
	return e;
}

//��ջ�ױ���ջ
void TraverseSqStack(SqStack* s, void (*visit)(char e))
{
	int i;
	for (i = 0; i <= s->top; i++)
	{
		visit((s->elem)[i]);
	}
	printf("\n");
}
void visit(char e)
{
	printf_s("%c", e);
}

void clearStack(SqStack* s)
{
	s->top = -1;
}

SqStack* FreePointer(SqStack* s)
{
	SqStack* p = s;
	free(p);
	p = (SqStack*)malloc(sizeof(SqStack));
	initStack(p, MAXSIZE);
	return p;
}

//�����ʽ���Ƿ���˺����֣�+��-��*��/��������,.�⻹�б�Ķ���
Status Check_1(char* exp)
{
	int flag = 1;
	int temp;
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		temp = exp[i];
		if ((temp >= 40 && temp <= 43) || (temp >= 45 && temp <= 57))
		{
			continue;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
	{
		printf_s("���ʽ������˺����֣�+��-��*��/��������,.�⻹�б�Ķ���Ŷ!\n");
		return ERROR;
	}
	if (flag == 1)
		return SUCCESS;
}

//�����ʽ�����ŵ�ƥ���
Status Check_2(char* exp)
{
	Status flag = ERROR;
	SqStack* inn = (SqStack*)malloc(sizeof(SqStack));
	initStack(inn, MAXSIZE);
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		if (exp[i] == '(')
			pushStack(inn, '(');
		else if (exp[i] == ')')
		{
			flag = isEmptyStack(inn);
			if (flag == 1)
			{
				printf_s("���ʽ��ȱ��ƥ��ġ�����!\n");
				free(inn->elem);
				free(inn);
				return ERROR;
			}
			else
				popStack(inn);
		}
	}
	flag = isEmptyStack(inn);
	if (flag == SUCCESS)
	{
		//free(inn->elem);
		free(inn);
		return SUCCESS;
	}
	else
	{
		printf_s("���ʽ��ȱ��ƥ��ġ�)��!\n");
		free(inn->elem);
		free(inn);
		return ERROR;
	}
}

//������������ǲ������ֻ���')',�ұ��ǲ������ֻ���'('
Status Check_3(char* exp)
{
	int temp1, temp2, flag = 1, i;
	for (i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			temp1 = exp[i - 1];
			temp2 = exp[i + 1];
			//�������������ֻ�����')',�ұ������ֻ�����'('
			if (((temp1 >= 48 && temp1 <= 57) || temp1 == 41) &&
				((temp2 >= 48 && temp2 <= 57) || temp2 == 40))
				continue;
			else
			{
				flag = 0;
				break;
			}
		}
	}
	i = 0;
	for (i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		if (exp[i] == '-')
		{
			temp1 = exp[i - 1];
			temp2 = exp[i + 1];
			if (((temp1 >= 48 && temp1 <= 57) || temp1 == 41 || temp1 == 40) &&
				((temp2 >= 48 && temp2 <= 57) || temp2 == 40))
				flag = 1;
			else
				flag = -1;
		}
	}
	if (flag == 0)
	{
		printf_s("+��-��*��/����߲��������ֻ�')',���ұ߲������ֻ�'('��\n");
		return ERROR;
	}
	if (flag == -1)
	{
		printf_s("��-�����ұ���'('\n");
		return ERROR;
	}
	else
		return SUCCESS;
}

//����������Ƿ�Ϊ��
Status Check_4(char* exp)
{
	SqStack* inn = (SqStack*)malloc(sizeof(SqStack));
	initStack(inn, MAXSIZE);
	Status flag;
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		if (exp[i] == '(')
			pushStack(inn, '(');
		flag = isEmptyStack(inn);
		if (flag == ERROR && exp[i] != ')')
			pushStack(inn, exp[i]);
		if (exp[i] == ')')
		{
			if (getTopStack(inn) == '(')
			{
				printf_s("������Ϊ�գ�\n");
				free(inn->elem);
				free(inn);
				return ERROR;
			}
		}
	}
	free(inn->elem);
	free(inn);
	return SUCCESS;
}

//���С���������Ƿ�Ϊ����
Status Check_5(char* exp)
{
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		int temp1, temp2;
		if (exp[i] == '.')
		{
			temp1 = exp[i - 1];
			temp2 = exp[i + 1];
			if ((temp1 >= 48 && temp1 <= 57) && (temp2 >= 48 && temp2 <= 57))
				continue;
			else
			{
				printf_s(".����Ҫ������Ŷ��\n");
				return ERROR;
			}
		}
	}
	return SUCCESS;
}

//����Ƿ�ȫ������
Status Check_6(char* exp)
{
	int flag = 0;
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		if ((exp[i] >= 48 && exp[i] <= 57) || exp[i] == '.')
			continue;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf_s("������Ǹ����֣��������������ʽŶ��\n");
		return ERROR;
	}
	else
		return SUCCESS;
}

//��׺���ʽת��׺���ʽ
SqStack* change(char* exp, SqStack* exp_suf)
{
	int j = 0;
	SqStack* inn = (SqStack*)malloc(sizeof(SqStack));
	initStack(inn, MAXSIZE);
	for (int i = 0; exp[i] != '\0' || i > MAXSIZE; i++)
	{
		while ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.'
			|| exp[i] == '(')
		{
			if (exp[i] == '(' && exp[1 + i] != '-')
				break;
			if (exp[i] == '(' && exp[1 + i] == '-')
			{
				i++;
				do
				{
					pushStack(exp_suf, exp[i]);
					i++;
				} while (exp[i] != ')');
			}
			if (exp[i] == ')')
			{
				pushStack(exp_suf, ' ');
				i++;
				break;
			}
			pushStack(exp_suf, exp[i]);
			i++;
			if ((exp[i] < '0' || exp[i] > '9') && exp[i] != '.')
			{
				pushStack(exp_suf, ' ');
				break;
			}
		}
		if (')' == exp[i])
		{
			while (getTopStack(inn) != '(')
			{
				pushStack(exp_suf, getTopStack(inn));
				popStack(inn);
				pushStack(exp_suf, ' ');

			}
			popStack(inn);
		}
		else if ('+' == exp[i] || '-' == exp[i])
		{
			if (isEmptyStack(inn) == SUCCESS)
				pushStack(inn, exp[i]);
			else
			{
				do
				{
					if (getTopStack(inn) == '(')
						continue;
					else
					{
						pushStack(exp_suf, getTopStack(inn));
						popStack(inn);
						pushStack(exp_suf, ' ');
					}
				} while (isEmptyStack(inn) == ERROR && getTopStack(inn) != '(');
				pushStack(inn, exp[i]);
			}
		}
		else if ('(' == exp[i])
		{
			pushStack(inn, exp[i]);
		}
		else if ('*' == exp[i] || '/' == exp[i])
		{
			while (getTopStack(inn) == '*' || getTopStack(inn) == '/')
			{
				pushStack(exp_suf, getTopStack(inn));
				pushStack(exp_suf, ' ');
				popStack(inn);
			}
			if ((isEmptyStack(inn) == SUCCESS))
			{
				pushStack(inn, exp[i]);
			}
			if (getTopStack(inn) != '*' && getTopStack(inn) != '/'
				&& (isEmptyStack(inn) == ERROR))
				pushStack(inn, exp[i]);
		}
	}
	while (isEmptyStack(inn) == ERROR)
	{
		pushStack(exp_suf, getTopStack(inn));
		popStack(inn);
		pushStack(exp_suf, ' ');
	}
	return exp_suf;
}

//������
Status Calculate(SqStack* exp_suf, double* e)
{
	int j = 0;
	SqStack_double* inn = (SqStack_double*)malloc(sizeof(SqStack_double));
	initStack_double(inn, MAXSIZE);
	double a, b, result;
	char str[MAXBUFFER], str1[MAXSIZE] = { '\0' };
	for (int i = 0; i <= exp_suf->top; i++)
	{
		while ((exp_suf->elem[i] >= '0' && exp_suf->elem[i] <= '9') ||
			exp_suf->elem[i] == '.' || exp_suf->elem[i] == '-')
		{
			if (exp_suf->elem[i] == '-')
				if (exp_suf->elem[i + 1] == ' ')
					break;
			str[j++] = exp_suf->elem[i];
			str[j] = '\0';
			if (j >= MAXBUFFER - 1)
			{
				printf_s("����ĵ������ݹ���\n");
				return ERROR;
			}
			i++;
			if (exp_suf->elem[i] == ' ')
			{
				a = atof(str);
				pushStack_double(inn, a);
				j = 0;
				break;
			}
		}
		switch (exp_suf->elem[i])
		{
		case '+':
			a = getTopStack_double(inn);
			popStack_double(inn);
			b = getTopStack_double(inn);
			popStack_double(inn);
			pushStack_double(inn, a + b);
			break;

		case '-':
			a = getTopStack_double(inn);
			popStack_double(inn);
			b = getTopStack_double(inn);
			popStack_double(inn);
			pushStack_double(inn, b - a);
			break;

		case '*':
			a = getTopStack_double(inn);
			popStack_double(inn);
			b = getTopStack_double(inn);
			popStack_double(inn);
			pushStack_double(inn, a * b);
			break;

		case '/':
			a = getTopStack_double(inn);
			popStack_double(inn);
			b = getTopStack_double(inn);
			popStack_double(inn);
			if (a != 0)
			{
				pushStack_double(inn, b / a);
			}
			else
			{
				printf_s("������������Ϊ0��\n");
				return ERROR;
			}
			break;
		}
	}
	*e = getTopStack_double(inn);
	return SUCCESS;
}

void clear(char* str)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		str[i] = '\0';
	}
}