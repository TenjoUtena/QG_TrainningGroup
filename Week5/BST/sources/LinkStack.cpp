#include "LinkStack.h"
#include <stdio.h>
#include <malloc.h>

//Initialize the LinkStack
Status initLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	else
	{
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}


//Judge whether the LinkStack is empty 
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}


//Get an element in the top of the LinkStack
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


//Clear the LinkStack
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


//Destroy the LinkStack
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


//Push the element into the LinkStack
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


//Pop the element out of the Stack
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