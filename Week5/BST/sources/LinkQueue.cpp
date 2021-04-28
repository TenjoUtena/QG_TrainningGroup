#include <stdio.h>
#include "LinkQueue.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	LQNode* p = (LQNode*)malloc(sizeof(LQNode));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	p->data = NULL;
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
	LQueue* p = Q;
	ClearLQueue(Q);
	Q->front = NULL;
	Q->rear = NULL;
}


/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
int IsEmptyLQueue(const LQueue* Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
}


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
QStatus EnLQueue(LQueue* Q, NodePtr data)
{
	LQNode* p = (LQNode*)malloc(sizeof(LQNode));
	Q->rear->data = data;
	Q->rear->next = p;
	p->next = NULL;
	Q->rear = p;
	return TRUE;
}


/**
 *  @name        : QStatus DeLQueue(LQueue* Q, NodePtr* data)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
QStatus DeLQueue(LQueue* Q, NodePtr* data)
{
	*data = Q->front->data;
	LQNode* p;
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
	if (IsEmptyLQueue(Q) == TRUE)
	{
		return;
	}
	LQNode* p, * q;
	p = q = Q->front->next;
	while (NULL != q->next)
	{
		q = q->next;
		free(p);
		p = q;
	}
	free(p);
	p = q = NULL;
	Q->rear = Q->front = (LQNode*)malloc(sizeof(LQNode));
}


int LengthLQueue(LQueue* Q)
{
	int length;
	LQNode* p = (LQNode*)malloc(sizeof(LQNode));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}