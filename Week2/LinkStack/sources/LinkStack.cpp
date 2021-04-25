#include<malloc.h>
#include<stdio.h>
#include "LinkStack.h"


//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	if (s->count >= 0)
	{
		printf_s("�ѳ�ʼ���������ظ���");
		return ERROR;
	}
	else
	{
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}
//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (!s)
		return ERROR;
	else
	{
		*e = s->top->data;
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	else
	{
		LinkStackPtr p1, p2;
		p1 = p2 = s->top;
		while (p2 != NULL)
		{
			p2 = p2->next;
			free(p1);
			p1 = p2;
		}
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}

//����ջ
Status destroyLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	else
	{
		clearLStack(s);
		s->top = NULL;
		s->count = -1;
		return SUCCESS;
	}
}

//���ջ����
Status LStackLength(LinkStack* s, int* length)
{
	if (s->count != -1)
	{
		*length = s->count;
		return SUCCESS;
	}
	else
		return ERROR;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data)
{
	StackNode* p;
	p = NULL;
	if (!s)
		return ERROR;
	if (s->top == NULL)
	{
		s->top = (StackNode*)malloc(sizeof(StackNode));
		s->count++;
		s->top->next = NULL;
		s->top->data = data;
		return SUCCESS;
	}
	else
	{
		p = (StackNode*)malloc(sizeof(StackNode));
		p->data = data;
		p->next = s->top;
		s->top = p;
		s->count++;
		return SUCCESS;
	}
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data)
{
	if (!s)
		return ERROR;
	else
	{
		LinkStackPtr p = s->top;
		*data = s->top->data;
		s->top = s->top->next;
		s->count--;
		free(p);
		return SUCCESS;
	}
}

//��ӡ�˵�
void printMenu()
{
	printf_s(
		"********************************\n"
		"       *��ӭʹ������ջ*\n"
		"       *�������Ӧ���*\n"
		"|-----1.��ʼ��ջ          -----|\n"
		"|-----2.��ջ              -----|\n"
		"|-----3.��ջ              -----|\n"
		"|-----4.���ջ�ĳ���      -----|\n"
		"|-----5.�ж�ջ�Ƿ�Ϊ��    -----|\n"
		"|-----6.�õ�ջ��Ԫ��      -----|\n"
		"|-----7.���ջ            -----|\n"
		"|-----8.����ջ            -----|\n"
		"|-----9.��ջ������ջ      -----|\n"
		"|-----10. ����            -----|\n"
		"|-----11.��������         -----|\n"
		"********************************\n\n\n");
}

//��ջ������ջ
void TraverseStack(LinkStack* s, void (*visit)(ElemType e))
{
	StackNode* p = s->top;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf_s("%d ", e);
}
