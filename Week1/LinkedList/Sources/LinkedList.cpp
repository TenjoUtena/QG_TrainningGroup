#include<stdio.h>
#include<malloc.h>
#include"LinkedList.h"
struct Node {
	ElemType data;
	struct Node* next;
};

/**
 *  @name        : Status InitList(LinkedList* L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if (!*L)
		return ERROR;
	(*L)->next = NULL;
	(*L)->data = info;
	return SUCCESS;
}


/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) 
{
	if (p->next == NULL)
	{
		p->next = q;
		return SUCCESS;
	}
	if (p != NULL && q != NULL)
	{
		q->next = p->next;
		p->next = q;
		return SUCCESS;
	}
	
	else
		return ERROR;
}


/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
		while (L) 
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
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
	while (L != NULL)
	{
		if (L->data == e) {
			return SUCCESS;
		}		
		L = L->next;
	}
	return ERROR;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) 
{
	if (p == NULL)
	{
		printf_s("该结点为空");
		return ERROR;
	}
	if (p->next == NULL)
	{
		printf_s("该结点后面没有元素");
		return ERROR;
	}
	LinkedList q;
	q = p->next;
	*e = q->data;
	p->next = q->next;
	printf_s("被删除的元素是：%d\n",*e);
	return SUCCESS;
}
/**
 *  @name        : void DestroyList(LinkedList head)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* head)
 {
	 LinkedList p;
	 while ((*head)!=NULL)
	 {
		 p = *head;
		 *head = (*head)->next;
		 free(p);
	 }
	 p = NULL;
 }

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	LinkedList p1, p2;
	if (!L)
		return ERROR;
	p1 = p2 = L;
	while (p1 != NULL && p2 != NULL &&(p2->next)!=NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
			return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)
{
	LinkedList p1, p2, p3;
	if (!(*L))
		return ERROR;
	p1 = NULL;
	p2 = p3 = (*L)->next;
	(*L)->next = NULL;
	while (p3 != NULL)
	{
		p3 = p3->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	(*L)->next = p1;
	return SUCCESS;
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) 
{
	LinkedList p , q;
	ElemType t;
	p = *L;
	q = (*L)->next;
	while (p != NULL && q != NULL)
	{
		t = p->data;
		p ->data = q->data;
		q->data = t;
		p = q->next;
		if (p == NULL)
			break;
		q = p->next;
	}
	return *L;
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)
{
	if (!(*L))
	{
		printf_s("链表为空");
		return *L;
	}
	LinkedList p1, p2;
	p1 = p2 = (*L);
	while (p1 != NULL && p2 != NULL)
	{
		if ((p2->next) == NULL|| (p2->next->next) == NULL)
			return p1;
		p1 = p1->next;
		if((p2->next) != NULL)
		p2 = p2->next->next;
	}
	free(*L);
	return p1;
}

/**
 *  @name        : LNode* CreateNode(ElemType data)
 *	@description : create a new node and assign its value
 *	@param		 : data
 *	@return		 : LNode*
 *  @notice      : Not from the studio,it built by myself
 */
LNode* CreateNode(ElemType data)
{
	LNode *p=(LNode*)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;
	return p;
}

/**
 *  @name        : Status BuildLoopLink(LNode* head, LNode* tail)
 *	@description : turn linkedlist to looplist
 *	@param		 : head,tail
 *	@return		 : Status
 *  @notice      : Not from the studio,it built by myself
 */
Status TurnLoopLink(LNode* head, LNode* tail)
{
	if (head->next == NULL)
	{
		printf_s("请先插入元素\n");
		return ERROR;
	}
	if (tail->next != NULL)
		return ERROR;
	else
	{
		tail->next = head;
		return SUCCESS;
	}
}

/**
 *  @name        : Status Loop_off(LNode* head, LNode* tail)
 *	@description : loop-off the looplink
 *	@param		 : head,tail
 *	@return		 : Status
 *  @notice      : Not from the studio,it built by myself
 */
Status Loop_off(LNode* head, LNode* tail)
{
	Status flag;
	flag = IsLoopList(head);
	if (flag == 0)
	{
		printf_s("该链表不成环\n");
		return ERROR;
	}
	else
	{
		tail->next = NULL;
		return SUCCESS;
	}
}