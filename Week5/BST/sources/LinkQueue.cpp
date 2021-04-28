#include <stdio.h>
#include "LinkQueue.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : ��ʼ������
 *  @param       : Q ����ָ��Q
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
 *  @description : ���ٶ���
 *  @param       : Q ����ָ��Q
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
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
int IsEmptyLQueue(const LQueue* Q)
{
	return (Q->front == Q->rear ? TRUE : FALSE);
}


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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