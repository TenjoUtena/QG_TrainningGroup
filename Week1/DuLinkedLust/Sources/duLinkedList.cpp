#include<stdio.h>
#include<malloc.h>
#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) 
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (!*L)
		return ERROR;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	(*L)->data = info;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) 
{
	DuLinkedList p;
	while (*L)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	p = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	if (p != NULL && q != NULL)
	{
		if (p->prior != NULL)
		{
			p->prior->next = q;
			q->prior = p->prior;
		}
		q->next = p;
		p->prior = q;
		return SUCCESS;
	}
	else
		return ERROR;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) 
{
	if (p != NULL && q != NULL)
	{
		if (p->next != NULL)
		{
			q->next = p->next;
			p->next->prior = q;
		}
		q->prior = p;
		p->next = q;
		return SUCCESS;
	}
	else
		return ERROR;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) 
{
	if (p == NULL)
	{
		printf_s("该结点为空\n");
		return ERROR;
	}
	if (p->next == NULL)
	{
		printf_s("该结点后面没有元素\n");
		return ERROR;
	}
	DuLinkedList q;
	q = p->next;
	*e = q->data;
	p->next = q->next;
	if((q->next)!=NULL)
		q->next->prior = q->prior;
	free(q);
	printf_s("被删除的元素是：%d\n", *e);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	while (L != NULL)
	{
		visit(L->data);
		L = L->next;
	}
	printf("\n");
}
void visit(ElemType e)
{
	printf_s("%d ", e);
}

/**
 *  @name        : DuLNode* CreateNode(ElemType data)
 *	@description : create a new node and assign its value
 *	@param		 : data
 *	@return		 : LNode*
 *  @notice      : Not from the studio,it built by myself,
 */
DuLNode* CreateNode(ElemType data)
{
	DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
	p->data = data;
	p->next = NULL;
	p->prior = NULL;
	return p;
}

