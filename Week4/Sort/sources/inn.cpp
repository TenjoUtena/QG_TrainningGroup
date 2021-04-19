#include "Sort.h"
#include <stdio.h>
#include <malloc.h>

void initLStack(LinkStack* s)
{
	if (!s)
		return ;
	else
	{
		s->top = NULL;
		s->count = 0;
		return ;
	}
}

void clearLStack(LinkStack* s)
{
	if (!s)
		return;
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
		return;
	}
}

void destroyLStack(LinkStack* s)
{
	if (!s)
		return;
	else
	{
		clearLStack(s);
		s->top = NULL;
		return;
	}
}

void pushLStack(LinkStack* s, ElemType data)
{
	StackNode* p;
	p = NULL;
	if (!s)
		return;
	if (s->top == NULL)
	{
		s->top = (StackNode*)malloc(sizeof(StackNode));
		s->count++;
		s->top->next = NULL;
		s->top->data = data;
		return ;
	}
	else
	{
		p = (StackNode*)malloc(sizeof(StackNode));
		p->data = data;
		p->next = s->top;
		s->top = p;
		s->count++;
		return;
	}
}

void popLStack(LinkStack* s)
{
	if (!s)
		return;
	else
	{
		LinkStackPtr p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
		return;
	}
}

int isEmptyLStack(LinkStack* s)
{
	if (s->count == 0)
		return 1;
	else
		return 0;
}
int getTopLStack(LinkStack* s)
{
	if (!s)
		return -1;
	else
		return s->top->data;
}