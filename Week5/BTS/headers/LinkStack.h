#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Tree.h"

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef NodePtr ElemType;

typedef  struct StackNode
{
	ElemType data;
	bool flag;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


Status initLStack(LinkStack* s);//Initialize the LinkStack
Status isEmptyLStack(LinkStack* s);//judge whether the LinkStack is empty 
Status getTopLStack(LinkStack* s, ElemType* e);//Get an element in the top of the LinkStack
Status clearLStack(LinkStack* s);//Clear the LinkStack
Status destroyLStack(LinkStack* s);//Destroy the LinkStack
Status pushLStack(LinkStack* s, ElemType data);//Push the element into the LinkStack
Status popLStack(LinkStack* s, ElemType* data);//Pop the element out of the Stack


#endif
#pragma once
