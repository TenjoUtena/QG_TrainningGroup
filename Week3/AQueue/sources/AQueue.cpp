#include <stdio.h>
#include "AQueue.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/**
  *  @name        : void InitAQueue(AQueue *Q)
  *  @description : 初始化队列
  *  @param       : Q 队列指针Q
  *  @notice      : None
  */
void InitAQueue(AQueue* Q)
{
	if (Q->data[0] != NULL)
	{
		printf_s("Already initialized！\n");
		return;
	}
	else
	{
		Q->front = 0;
		Q->rear = 0;
		for (int i = 0; i < MAXQUEUE; i++)
			Q->data[i] = malloc(20);
		printf_s("You have initialized the queue successfully！\n");
	}
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf_s("Please initialize the queue first！\n");
		return;
	}
	else
	{
		Q->data[0] = NULL;
		for (int i = 1; i < MAXQUEUE; i++)
			free(Q->data[i]);
		printf_s("You have destoryed the queue successfully!\n");
	}
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *  @description : 检查队列是否已满
 *  @param       : Q 队列指针Q
 *  @return      : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q)
{
	return ((Q->rear + 1) % MAXQUEUE == Q->front ? TRUE : FALSE);
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q 队列指针Q，存放元素e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (Q->data[0] == NULL)
	{
		printf_s("Please initialize the queue first！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q) == TRUE)
	{
		printf_s("The queue is empty, please make the elements enter the queue first!\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front], 20);
	return TRUE;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q 队列指针Q
 *  @return      : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf_s("Please initialize the queue first！\n");
		return -1;
	}
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue* Q, void* data)
{
	if (IsFullAQueue(Q) == TRUE)
	{
		printf_s("The queue has been full！\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf_s("Please initialize the queue first！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q) == TRUE)
	{
		printf_s("The queue is empty！There is no element.\n");
		return FALSE;
	}
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q)
{
	if (Q->data[0] == NULL)
	{
		printf_s("Please initialize the queue first！\n");
		return;
	}
	if (IsEmptyAQueue(Q) == TRUE)
	{
		printf_s("The queue has been empty!\n");
		return;
	}
	Q->front = Q->rear = 0;
	printf_s("Clear the queue successfully!\n");
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int type))
{
	if (IsEmptyAQueue(Q) == TRUE)
	{
		return FALSE;
	}
	int temp = Q->front;
	while (temp != Q->rear)
	{
		int i = 1;
		if (i % 5 == 0)
			printf("\n");
		foo(Q->data[temp],Q->type[temp]);
		temp = (temp+1) % MAXQUEUE;
		i++;
	}
	return TRUE;
}

/**
 *  @name        : void APrint(void *q)
 *  @description : 操作函数
 *  @param       : q 指针q
 *  @notice      : None
 */
void APrint(void* q, int type)
{
	if (type == 3 && q != NULL)
		printf("%lf ", *(double*)q);
	if (type == 4 && q != NULL)
	{
		puts((char*)q);
		printf(" ");
	}
	if (type == 2 && q != NULL)
		printf("%c ", *(char*)q);
	if (type == 1 && q!=NULL)
		printf("%d ", *(int*)q);
}

/**
 *  @name        : void PrintMenu_1()
 *  @description : Print the menu1
 *  @param       : None
 *  @notice      : None
 */
void PrintMenu_1()
{
	printf_s(
		" **********************************************\n"
		"    *Please input the corresponding number*\n"
		"          *Welcome to use the queue*\n"
		"|-----1.Initialize the queue             -----|\n"
		"|-----2.Enqueue                          -----|\n"
		"|-----3.Dequeue                          -----|\n"
		"|-----4.Detect the queue length          -----|\n"
		"|-----5.Judge if the queue is empty      -----|\n"
		"|-----6.Judge if the queue is full       -----|\n"
		"|-----7.Get the head element of the queue-----|\n"
		"|-----8.Clear the queue                  -----|\n"
		"|-----9.Destroy the queue                -----|\n"
		"|-----10.Traverse the queue              -----|\n"
		"|-----11.Clear the screen                -----|\n"
		"|-----12.End process                     -----|\n"
		"* warning: The maxsize of the queue is 9      *\n"
		"***********************************************\n\n\n");
}

/**
 *  @name        : void PrintMenu_2()
 *  @description : Print the menu2
 *  @param       : None
 *  @notice      : None
 */
void PrintMenu_2()
{
	printf_s(
		" ****************************************************\n"
		"    *    Please input the corresponding number   *\n"
		"         |-----1.int         -----|\n"
		"         |-----2.char        -----|\n"
		"         |-----3.double      -----|\n"
		"         |-----4.string      -----|\n"
		"         |-----5.cancel      -----|\n"
		"    * warning:The string length cannot exceed 20 *\n"
		"******************************************************\n\n\n");
}

/**
 *  @name        : void selection(AQueue* Q, int selet)
 *  @description : a selection menu
 *  @param       : Q 指针Q, seletion selet
 *  @notice      : None
 */
void selection(AQueue* q,int selet)
{
	int i;
	Status flag;
	int* n1, m1;
	char* n2, m2;
	double* n3, m3;
	char str1[1000], str2[20];
	switch (selet)
	{
	case 1:
		printf("please input:");
		while (scanf_s("%d", &m1) == 0 || getchar() != '\n')
		{
			printf("Input illegal character! please input again:");
			while (getchar() != '\n');
		}
		q->type[q->rear] = 1;
		n1 = &m1;
		system("cls");
		PrintMenu_1();
		flag = EnAQueue(q, n1);
		if(flag == TRUE)
			printf("Input successfully!\n");
		break;

	case 2:
		printf("please input:");
		scanf_s("%c", &m2);
		q->type[q->rear] = 2;
		n2 = &m2;
		system("cls");
		PrintMenu_1();
		flag = EnAQueue(q, n2);
		if (flag == TRUE)
			printf("Input successfully!\n");
		break;

	case 3:
		printf("please input:");
		while (scanf_s("%lf", &m3) == 0 || getchar() != '\n')
		{
			printf("Input illegal character! please input again:");
			while (getchar() != '\n');
		}
		q->type[q->rear] = 3;
		n3 = &m3;
		system("cls");
		PrintMenu_1();
		flag = EnAQueue(q, n3);
		if (flag == TRUE)
			printf("Input successfully!\n");
		break;

	case 4:
		printf("please input:");
		gets_s(str1);
		if (strlen(str1) > 20)
		{
			printf("The string length exceeds 20!\n");
			break;
		}
		else
		{
			strcpy_s(str2, str1);
			system("cls");
			PrintMenu_1();
			q->type[q->rear] = 4;
			flag = EnAQueue(q, str2);
				printf("Input successfully!\n");
			break;
		}
	default:
		system("cls");
		PrintMenu_1();
		printf_s("Fail to identify\n");
		return;
	}
}