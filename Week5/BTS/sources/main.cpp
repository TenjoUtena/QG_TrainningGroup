#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Tree.h"

int main()
{
	SBT_Status flag = 0;
	void (*pointer)(NodePtr);
	pointer = visit;
	int choice = 0, init = 0, e;
	BinarySortTreePtr head = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	PrintMenu();
	while (choice != 14)
	{
		printf_s("Your choice is£º");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("Input illegal character! please input again:");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			if (init == 0)
			{
				flag = BST_init(head);
				if (flag == 1)
				{
					printf_s("Initialize successfully!\n");
					init = 1;
				}
				else
					printf_s("Fail to initialize!\n");
			}
			else
				printf_s("The BST has been initialized£¡\n");
			break;

		case 2:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			printf_s("Please input the element£º");
			while (scanf_s("%d", &e) == 0 || getchar() != '\n')
			{
				printf("Input illegal character! please input again:");
				while (getchar() != '\n');
			}
			flag = BST_insert(head, e);
			if (flag == 1)
				printf_s("Insert successfully!\n");
			else
				printf_s("Fail to insert!The element has been exited.\n");
			break;

		case 3:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			printf_s("Please input the element that you want to check£º");
			while (scanf_s("%d", &e) == 0 || getchar() != '\n')
			{
				printf("Input illegal character! please input again:");
				while (getchar() != '\n');
			}
			flag = BST_search(head, e);
			if(flag == 1)
				printf_s("The element exits!\n");
			else
				printf_s("The element don't exit£¡\n");
			break;

		case 4:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			printf_s("Please input the element that you want to delete£º");
			while (scanf_s("%d", &e) == 0 || getchar() != '\n')
			{
				printf("Input illegal character! please input again:");
				while (getchar() != '\n');
			}
			flag = BST_search(head, e);
			if (flag == 0)
			{
				printf_s("The element don't exit£¡\n");
				break;
			}
			else
			{
				flag = BST_delete(&(head->root), e);
				if (flag == 1)
				{
					printf_s("Delete successfully£¡\n");
					break;
				}
				else
				{
					printf_s("Fail to delete!\n");
					break;
				}
			}

		case 5:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_preorderI(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 6:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_preorderR(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 7:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_inorderI(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 8:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_inorderR(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 9:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_postorderI(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 10:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_postorderR(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 11:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			if (head->root == NULL)
			{
				printf_s("Please insert the element first£¡\n");
				break;
			}
			flag = BST_levelOrder(head, pointer);
			if (flag == 0)
			{
				printf_s("Fail to traverse !\n");
				break;
			}
			printf_s("\n");
			break;

		case 12:
			if (init == 0)
			{
				printf_s("Please initialize the BST first£¡\n");
				break;
			}
			BST_clear(head);
			break;

		case 13:
			system("cls");
			PrintMenu();
			break;

		case 14:
			printf_s("End process!\n");
			break;

		default:
			printf_s("Fail to identify!\n");
		}
	}
	system("pause");
	return 0;
}