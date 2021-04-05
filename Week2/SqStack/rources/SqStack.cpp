#include "SqStack.h"
#include <stdio.h>
#include <malloc.h>

//初始化栈
Status initStack(SqStack* s, int sizes)
{
	if (!s || sizes < 1)
	{
		printf_s("可能是sizes小于1或者是超出取值范围了哦，");
		return ERROR;
	}
		
	if (s->elem != NULL)
	{
		printf_s("已初始化，操作重复。");
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

//判断栈是否为空
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1)
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
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

//清空栈
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

//销毁栈
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

//检测栈长度
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

//入栈
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
//出栈
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

//打印菜单
void printMenu()
{
	printf_s(
		"********************************\n"
		"       *请输入对应编号*\n"
		"       *欢迎使用链表栈*\n"
		"|-----1.初始化栈          -----|\n"
		"|-----2.入栈              -----|\n"
		"|-----3.出栈              -----|\n"
		"|-----4.检测栈的长度      -----|\n"
		"|-----5.判断栈是否为空    -----|\n"
		"|-----6.得到栈顶元素      -----|\n"
		"|-----7.清空栈            -----|\n"
		"|-----8.销毁栈            -----|\n"
		"|-----9.从栈底遍历栈      -----|\n"
		"|-----10.从栈顶遍历栈     -----|\n"
		"|-----11. 清屏            -----|\n"
		"|-----12.结束进程         -----|\n"
		"********************************\n\n\n");
}

//从栈底遍历栈
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

//从栈顶遍历栈
void TraverseSqStack_top(SqStack* s, void (*visit)(ElemType e))
{
	for (int i=s->top;i>=0;i--)
	{
		visit(s->elem[i]);
	}
	printf("\n");
}