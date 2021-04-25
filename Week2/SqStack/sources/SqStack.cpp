#include "SqStack.h"
#include <stdio.h>
#include <malloc.h>

//��ʼ��ջ
Status initStack(SqStack* s, int sizes)
{
	if (!s || sizes < 1)
	{
		printf_s("������sizesС��1�����ǳ���ȡֵ��Χ��Ŷ��");
		return ERROR;
	}
		
	if (s->elem != NULL)
	{
		printf_s("�ѳ�ʼ���������ظ���");
		return ERROR;
	}
	else
	{
		s->elem = (ElemType*)malloc(sizeof(ElemType)*sizes);
		s->top = -1;
		s->size = sizes;
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s->top != -1)
	{
		*e = (s->elem)[s->top];
		return SUCCESS;
	}
	else
		return ERROR;
}

//���ջ
Status clearStack(SqStack* s)
{
	if (!s)
		return ERROR;
	else 
	{
		s->top = -1;
		return SUCCESS;
	}
}

//����ջ
Status destroyStack(SqStack* s)
{
	if (!s)
		return ERROR;
	else
	{
		ElemType* p;
		p = s->elem;
		free(p);
		p = NULL;
		s->elem = NULL;
		return SUCCESS;
	}
}

//���ջ����
Status stackLength(SqStack* s, int* length)
{
	if (!s)
		return ERROR;
	else
	{
		*length = ((s->top)+1);
		return SUCCESS;
	}
}

//��ջ
Status pushStack(SqStack* s, ElemType data)
{
	if (s->top < (s->size) - 1)
	{
		s->top++;
		s->elem[s->top] = data;
		return SUCCESS;
	}
	else
		return ERROR;
}
//��ջ
Status popStack(SqStack* s, ElemType* data)
{
	if (!s)
		return ERROR;
	else
	{
		*data = s->elem[s->top];
		(s->top)--;
		return SUCCESS;
	}
}

//��ӡ�˵�
void printMenu()
{
	printf_s(
		"********************************\n"
		"       *�������Ӧ���*\n"
		"       *��ӭʹ������ջ*\n"
		"|-----1.��ʼ��ջ          -----|\n"
		"|-----2.��ջ              -----|\n"
		"|-----3.��ջ              -----|\n"
		"|-----4.���ջ�ĳ���      -----|\n"
		"|-----5.�ж�ջ�Ƿ�Ϊ��    -----|\n"
		"|-----6.�õ�ջ��Ԫ��      -----|\n"
		"|-----7.���ջ            -----|\n"
		"|-----8.����ջ            -----|\n"
		"|-----9.��ջ�ױ���ջ      -----|\n"
		"|-----10.��ջ������ջ     -----|\n"
		"|-----11. ����            -----|\n"
		"|-----12.��������         -----|\n"
		"********************************\n\n\n");
}

//��ջ�ױ���ջ
void TraverseSqStack(SqStack* s, void (*visit)(ElemType e))
{
	int i ;
	for (i=0;i<=s->top;i++)
	{
		visit((s->elem)[i]);
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf_s("%d ", e);
}

//��ջ������ջ
void TraverseSqStack_top(SqStack* s, void (*visit)(ElemType e))
{
	for (int i=s->top;i>=0;i--)
	{
		visit(s->elem[i]);
	}
	printf("\n");
}