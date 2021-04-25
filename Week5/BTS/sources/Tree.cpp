#include <stdio.h>
#include <malloc.h>
#include "Tree.h"
#include "LinkStack.h"
#include "LinkQueue.h"

void PrintMenu()
{
	printf_s(
		" **********************************************\n"
		"    *Please input the corresponding number*\n"
		"           *Welcome to use the BST*\n"
		"|-----1.Initialize the BST                       -----|\n"
		"|-----2.Insert an element into the BST           -----|\n"
		"|-----3.Whether the element is in the BST        -----|\n"
		"|-----4.Detect the element in the BST            -----|\n"
		"|-----5.BST preorder traversal without recursion -----|\n"
		"|-----6.BST preorder traversal with recursion    -----|\n"
		"|-----7.BST inorder traversal without recursion  -----|\n"
		"|-----8.BST inorder traversal with recursion     -----|\n"
		"|-----9.BST postorder traversal without recursion-----|\n"
		"|-----10.BST postorder traversal with recursion  -----|\n"
		"|-----11.BST level order traversal               -----|\n"
		"|-----12.Clear the BST                           -----|\n"
		"|-----13.Clear the screen                        -----|\n"
		"|-----14.End process                             -----|\n"
		"***********************************************\n\n\n");
}

SBT_Status BST_init(BinarySortTreePtr p)
{
	if(!p)
		return failed;
	p->root = NULL;
	return succeed;
}

SBT_Status BST_insert(BinarySortTreePtr p, BST_ElemType e)
{
	if (p == NULL)
		return failed;

	//if the element exits, return
	SBT_Status flag = BST_search(p, e);
	if (flag == 1)
		return failed;

	//initialize the node
	NodePtr N = (NodePtr)malloc(sizeof(Node));
	N->value = e;
	N->left = NULL;
	N->right = NULL;

	//situation_1:root is NULL
	if (p->root == NULL)
	{
		p->root = N;
		return succeed;
	}

	NodePtr T = p->root;
	NodePtr t = NULL;

	//situation_2:root is not NULL
	while (T != NULL)
	{
		t = T;
		if (e > T->value)
			T = T->right;
		else if (e < T->value)
			T = T->left;
	}
	if (e > t->value)
		t->right = N;
	else
		t->left = N;
	return succeed;
}

SBT_Status BST_delete(NodePtr* p, BST_ElemType e)
{
	NodePtr temp, t = NULL;
	if (p == NULL)
		return failed;
	if ((*p)->value > e)
		BST_delete(&((*p)->left), e);
	else if((*p)->value < e)
		BST_delete(&((*p)->right), e);
	else
	{
		if ((*p)->left == NULL)
		{
			temp = *p;
			*p = (*p)->right;
			free(temp);
			return succeed;
		}
		else if ((*p)->right == NULL)
		{
			temp = *p;
			*p = (*p)->left;
			free(temp);
			return succeed;
		}
		else
		{
			temp = (*p)->left;
			while (temp != NULL)
			{
				t = temp;
				temp = temp->right;
			}
			(*p)->value = t->value;
			BST_delete(&t, t->value);
		}
	}
}

SBT_Status BST_search(BinarySortTreePtr p, BST_ElemType e)
{
	if (p == NULL || p->root == NULL)
		return failed;
	NodePtr T = p->root;
	while (T != NULL)
	{
		if (T->value == e)
			return true;
		if (T->value < e)
			T = T->right;
		else
			T = T->left;
	}
	return false;
}

void visit(NodePtr v)
{
	printf_s("%d ", v->value);
}

SBT_Status BST_preorderI(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	LinkStack* top = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(top);
	NodePtr t = p->root;
	pushLStack(top, t);
	while (isEmptyLStack(top) == 0)
	{
		popLStack(top, &t);
		visit(t);
		if (t->right != NULL)
			pushLStack(top, t->right);
		if (t->left != NULL)
			pushLStack(top, t->left);
	}
	destroyLStack(top);
	return succeed;
}

SBT_Status BST_preorderR(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	BST_preorderR_(p->root, visit);
}
SBT_Status BST_preorderR_(NodePtr p, void (*visit)(NodePtr))
{
	if (p == NULL)
		return failed;
	visit(p);
	BST_preorderR_(p->left, visit);
	BST_preorderR_(p->right, visit);
	return succeed;
}

SBT_Status BST_inorderI(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	LinkStack* top = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(top);
	NodePtr t = p->root;
	while (isEmptyLStack(top) == 0 || t != NULL)
	{
		while (t != NULL)
		{
			pushLStack(top, t);
			t = t->left;
		}
		if (isEmptyLStack(top) == 0)
		{
			popLStack(top, &t);
			visit(t);
			t = t->right;
		}
	}
	destroyLStack(top);
	return succeed;
}

SBT_Status BST_inorderR(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	BST_inorderR_(p->root, visit);
}
SBT_Status BST_inorderR_(NodePtr p, void (*visit)(NodePtr))
{
	if (p == NULL)
		return failed;
	BST_inorderR_(p->left, visit);
	visit(p);
	BST_inorderR_(p->right, visit);
	return succeed;
}

SBT_Status BST_postorderI(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	//double stack
	/*LinkStack* top1 = (LinkStack*)malloc(sizeof(LinkStack));
	LinkStack* top2 = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(top1);
	initLStack(top2);
	NodePtr t = p->root;
	NodePtr T;
	pushLStack(top1, t);
	while (isEmptyLStack(top1) == 0)
	{
		popLStack(top1, &t);
		T = t;
		pushLStack(top2, T);
		if (t->left != NULL)
			pushLStack(top1, t->left);
		if (t->right != NULL)
			pushLStack(top1, t->right);
		
		
	}
	while (isEmptyLStack(top2) == 0)
	{
		popLStack(top2, &T);
		visit(T);
	}
	destroyLStack(top1);
	destroyLStack(top2);*/

	//one stack and one queue
	LinkStack* top = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(top);
	LQueue* q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(q);
	NodePtr t = p->root;
	NodePtr T;
	EnLQueue(q, t);
	while (IsEmptyLQueue(q) == 0)
	{
		DeLQueue(q, &t);
		T = t;
		pushLStack(top, T);
		if (t->right != NULL)
			EnLQueue(q, t->right);
		if (t->left != NULL)
			EnLQueue(q, t->left);
		
	}
	while (isEmptyLStack(top) == 0)
	{
		popLStack(top, &t);
		visit(t);
	}
	return succeed;
}

SBT_Status BST_postorderR(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	BST_postorderR_(p->root, visit);
}
SBT_Status BST_postorderR_(NodePtr p, void (*visit)(NodePtr))
{
	if (p == NULL)
		return failed;
	BST_postorderR_(p->left, visit);
	BST_postorderR_(p->right, visit);
	visit(p);
	return succeed;
}

SBT_Status BST_levelOrder(BinarySortTreePtr p, void (*visit)(NodePtr))
{
	if (p == NULL || p->root == NULL)
		return failed;
	LQueue* q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(q);
	NodePtr t = p->root;
	EnLQueue(q, t);
	while(IsEmptyLQueue(q) == 0)
	{
		DeLQueue(q, &t);
		if (t->left != NULL)
			EnLQueue(q, t->left);
		if (t->right != NULL)
			EnLQueue(q, t->right);
		visit(t);
	}
	DestoryLQueue(q);
	return succeed;
}

SBT_Status BST_clear(BinarySortTreePtr p)
{
	if (p == NULL)
		return failed;
	NodePtr t = p->root;
	if (t == NULL)
	{
		printf_s("The BST is already empty!\n");
		return succeed;
	}
	else
	{
		free(t);
		p->root = NULL; 
		printf_s("Clear the BST successfully!\n");
		return succeed;
	}
}