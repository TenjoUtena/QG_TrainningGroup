#include <stdio.h>
#include "AQueue.h"
#include <malloc.h>
#include <stdlib.h>

int main()
{
	Status flag;
	int choice = 0, size = 0, selet = 0;
	void* e = malloc(20);
	AQueue* q = (AQueue*)malloc(sizeof(AQueue));
	q->data[0] = NULL;
	void (*foo)(void*,int);
	foo = APrint;
	PrintMenu_1();
	while (choice != 12)
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
			InitAQueue(q);
			break;

		case 2:
			if (q->data[0] == NULL)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			system("cls");
			PrintMenu_2();
			printf_s(
				"Which data type do you what to choose?\n"
				"Please input the corresponding number:"); 
			while (scanf_s("%d", &selet) == 0 || getchar() != '\n')
			{
				printf("Input illegal character! please input again:");
				while (getchar() != '\n');
			}
			selection(q, selet);
			break;


		case 3:
			flag = DeAQueue(q);
			if (flag == TRUE)
			{
				printf_s("Element dequeued successfully!\n");
				break;
			}
			break;

		case 4:
			int len;
			len = LengthAQueue(q);
			if (len == -1)
				break;
			else
			{
				printf("Queue length is %d\n",len);
				break;
			}

		case 5:
			flag = IsEmptyAQueue(q);
			if (q->data[0] == NULL)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			if (flag == TRUE)
			{
				printf_s("The queue is empty\n");
				break;
			}
			if (flag == FALSE)
			{
				printf_s("The queue is not empty\n");
				break;
			}

		case 6:
			flag = IsFullAQueue(q);
			if (q->data[0] == NULL)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			if (flag == TRUE)
			{
				printf_s("The queue is full\n");
				break;
			}
			if (flag == FALSE)
			{
				printf_s("The queue is not full\n");
				break;
			}

		case 7:
			flag = GetHeadAQueue(q, e);
			if (flag == TRUE)
			{
				APrint(e,q->type[q->front]);
				printf_s("\n");
				break;
			}
			break;

		case 8:
			ClearAQueue(q);
			break;

		case 9:
			DestoryAQueue(q);
			break;

		case 10:
			if (q->data[0] == NULL)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			flag = TraverseAQueue(q, foo);
			if (flag == TRUE)
			{
				printf_s("\n");
				break;
			}
			if (flag == FALSE)
			{
				printf_s("The queue is empty!\n");
				break;
			}

		case 11:
			system("cls");
			PrintMenu_1();
			break;

		case 12:
			printf_s("End process\n");
			break;

		default:
			printf_s("Fail to identify\n");
		}
	}
	system("pause");
	return 0;
}

