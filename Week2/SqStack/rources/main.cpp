#include "SqStack.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
	int choice = 0, size;
	int* length = &size,*top = &choice;
	Status flag = ERROR;
	ElemType data = 0;
	ElemType* e = &data;
	struct SqStack SqS;	
	SqStack* Sq = &SqS;
	Sq->elem = NULL;
	void (*pointer)(ElemType);
	pointer = visit;
	printMenu();
	while (choice != 12)
	{
		printf_s("你的选择是：");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("\n输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch (choice)
		{
			case 1:
				printf("请输入您想构建栈的大小：");
				while (scanf_s("%d", &size) == 0 || getchar() != '\n')
				{
					printf("\n输入了非法字符，请重新输入：");
					while (getchar() != '\n');
				}
				flag = initStack(Sq, size);
				if (flag == SUCCESS)
				{
					printf_s("初始化成功！\n");
					break;
				}
				else
				{
					printf_s("初始化失败！\n");
					break;
				}

			case 2:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				printf_s("请输入数据：");
				while (scanf_s("%d", &data) == 0 || getchar() != '\n')
				{
					printf("\n输入了非法字符，请重新输入：");
					while (getchar() != '\n');
				}
				flag = pushStack(Sq, data);
				if (flag == SUCCESS)
				{
					printf_s("成功入栈！\n");
					break;
				}
				else
				{
					printf_s("栈已满，化栈失败！\n");
					break;
				}

			case 3:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("栈中没有元素！\n");
					break;
				}
				flag = popStack(Sq, e);
				if (flag == SUCCESS)
				{
					printf_s("元素%d已出栈\n", *e);
					break;
				}
				else
				{
					printf_s("出栈失败！\n");
					break;
				}

			case 4:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				flag = stackLength(Sq, length);
				if (flag == SUCCESS)
				{
					printf_s("栈的长度为：%d\n", *length);
					break;
				}
				else
				{
					printf_s("检测失败！\n");
					break;
				}

			case 5:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				flag = isEmptyStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("栈为空！\n");
					break;
				}
				else
				{
					printf_s("栈不为空！\n");
					break;
				}

			case 6:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("栈中没有元素！\n");
					break;
				}
				flag = getTopStack(Sq, top);
				if (flag == SUCCESS)
				{
					printf_s("栈顶元素为：%d\n", *top);
					break;
				}
				else
				{
					printf_s("获取栈顶元素失败！\n");
					break;
				}

			case 7:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("已为空栈！\n");
					break;
				}
				flag = clearStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("成功清空栈！\n");
					break;
				}
				else
				{
					printf_s("清空栈失败！\n");
					break;
				}

			case 8:
				if (Sq->elem == NULL)
				{
					printf_s("栈不存在！\n");
					break;
				}
				flag = destroyStack(Sq);
				if (flag == SUCCESS)
				{
					printf_s("成功销毁栈！\n");
					break;
				}
				else
				{
					printf_s("销毁栈失败！\n");
					break;
				}

			case 9:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("栈中没有元素，请先入栈！\n");
					break;
				}
				TraverseSqStack(Sq, pointer);
				break;

			case 10:
				if (Sq->elem == NULL)
				{
					printf_s("请先初始化栈！\n");
					break;
				}
				if (Sq->top == -1)
				{
					printf_s("栈中没有元素，请先入栈！\n");
					break;
				}
				TraverseSqStack_top(Sq, pointer);
				break;

			case 11:
				system("cls");
				printMenu();
				break;
			
			case 12:
				printf_s("结束程序\n");
				break;

			default:
				printf_s("无法识别\n");
		}
	}
	system("pause");
	return 0;
}