#include<malloc.h>
#include<stdio.h>
#include "LinkStack.h"


//初始化栈
Status initLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	if (s->count >= 0)
	{
		printf_s("已初始化，操作重复。");
		return ERROR;
	}
	else
	{
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}
//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0)
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
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

//清空栈
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

//销毁栈
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

//检测栈长度
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

//入栈
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

//出栈
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

//打印菜单
void printMenu()
{
	printf_s(
		"********************************\n"
		"       *欢迎使用链表栈*\n"
		"       *请输入对应编号*\n"
		"|-----1.初始化栈          -----|\n"
		"|-----2.入栈              -----|\n"
		"|-----3.出栈              -----|\n"
		"|-----4.检测栈的长度      -----|\n"
		"|-----5.判断栈是否为空    -----|\n"
		"|-----6.得到栈顶元素      -----|\n"
		"|-----7.清空栈            -----|\n"
		"|-----8.销毁栈            -----|\n"
		"|-----9.从栈顶遍历栈      -----|\n"
		"|-----10. 清屏            -----|\n"
		"|-----11.结束进程         -----|\n"
		"********************************\n\n\n");
}

//从栈顶遍历栈
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
