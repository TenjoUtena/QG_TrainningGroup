#include <stdio.h>
#include "LQueue.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

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
		"|-----6.Get the head element of the queue-----|\n"
		"|-----7.Clear the queue                  -----|\n"
		"|-----8.Destroy the queue                -----|\n"
		"|-----9.Traverse the queue               -----|\n"
		"|-----10.Clear the screen                -----|\n"
		"|-----11.End process                     -----|\n"
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
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (Q->judge != -1)
	{
		printf_s("Already initialized！\n");
		return;
	}
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	p->data = NULL;
	Q->judge = 0;
	printf_s("You have initialized the queue successfully！\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
	if (Q->judge == -1)
	{
		printf_s("Please initialize the queue first！\n");
		return;
	}
	else
	{
		LQueue* p = Q;
		ClearLQueue(Q);
		Q->judge = -1;
		Q->front = NULL;
		Q->rear = NULL;
		printf_s("You have destoryed the queue successfully!\n");
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q e 队列指针Q,返回数据指针e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
	size_t size;
	char str[20];
	if (Q->judge == -1)
	{
		printf_s("Please initialize the queue first！\n");
		return FALSE;
	}
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf_s("The queue is empty, please make the elements enter the queue first!\n");
		return FALSE;
	}
	if (Q->front->type == 1)
		Q->data_size = sizeof(int);
	if (Q->front->type == 2)
		Q->data_size = sizeof(char);
	if (Q->front->type == 3)
		Q->data_size = sizeof(double);
	if (Q->front->type == 4)
		Q->data_size = sizeof(str);
	memcpy(e, Q->front->data, Q->data_size);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q)
{
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data)
{
	if (Q->judge == -1)
	{
		printf_s("Please initialize the queue first！\n");
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	Q->rear->data = (void*)malloc(Q->data_size);
	memcpy(Q->rear->data, data, Q->data_size);
	Q->rear->next = p;
	p->next = NULL;
	Q->rear = p;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q)
{
	if (Q->judge == -1)
	{
		printf_s("Please initialize the queue first！\n");
		return FALSE;
	}
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf_s("The queue is empty！There is no element.\n");
		return FALSE;
	}
	Node* p;
	p = Q->front;
	Q->front = p->next;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
	if (Q->judge == -1)
	{
		printf_s("Please initialize the queue first！\n");
		return;
	}
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf_s("The queue has been empty!\n");
		return;
	}
	Node* p, * q;
	p = q = Q->front->next;
	while (NULL != q->next) 
	{
		q = q->next;
		free(p);
		p = q;
	}
	free(p);
	p = q = NULL;
	Q->rear = Q->front = (Node*)malloc(sizeof(Node));
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int type))
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	int i = 1;
	while (p != NULL)
	{
		if (i % 5 == 0) printf("\n");
		foo(p->data, p->type);
		p = p->next;
		i++;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *  @description : 操作函数
 *  @param       : q 指针q
 *  @notice      : None
 */
void LPrint(void* q, int type)
{
	if (type == 1 && q != NULL)
		printf("%d ", *(int*)q);
	if (type == 2 && q != NULL)
		printf("%c ", *(char*)q);
	if (type == 3 && q != NULL)
		printf("%lf ", *(double*)q);
	if (type == 4 && q != NULL)
	{
		puts((char*)q);
		printf(" ");
	}
}

/**
 *  @name        : void selection(LQueue* Q, int selet)
 *  @description : a selection menu
 *  @param       : Q 指针Q, seletion selet
 *  @notice      : None
 */
void selection(LQueue* Q, int selet)
{
	int i;
	Status flag;
	int* n1, m1;
	char* n2, m2;
	double* n3, m3;
	char str1[1000], str2[20];
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->rear;
	switch (selet)
	{
	case 1:
		printf("please input:");
		while (scanf_s("%d", &m1) == 0 || getchar() != '\n')
		{
			printf("Input illegal character! please input again:");
			while (getchar() != '\n');
		}
		p->type = 1;
		n1 = &m1;
		system("cls");
		PrintMenu_1();
		Q->data_size = sizeof(int);
		flag = EnLQueue(Q, n1);
		if (flag == TRUE)
			printf("Input successfully!\n");
		break;

	case 2:
		printf("please input:");
		scanf_s("%c", &m2);
		p->type = 2;
		n2 = &m2;
		system("cls");
		PrintMenu_1();
		Q->data_size = sizeof(char);
		flag = EnLQueue(Q, n2);
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
		p->type = 3;
		n3 = &m3;
		system("cls");
		PrintMenu_1();
		Q->data_size = sizeof(double);
		flag = EnLQueue(Q, n3);
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
			p->type = 4;
			Q->data_size = sizeof(str2);
			flag = EnLQueue(Q, str2);
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
