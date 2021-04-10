#include <stdio.h>
#include "LQueue.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	Status flag;
	int choice = 0, size = 0, selet = 0;
	void* e = malloc(20);
	LQueue* q = (LQueue*)malloc(sizeof(LQueue));
	q->judge = -1;
	void (*foo)(void*, int);
	foo = LPrint;
	PrintMenu_1();
	while (choice != 11)
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
			InitLQueue(q);
			break;

		case 2:
			if (q->judge == -1)
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
			flag = DeLQueue(q);
			if (flag == TRUE)
			{
				printf_s("Element dequeued successfully!\n");
				break;
			}
			break;

		case 4:
			if (q->judge == -1)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			else
			{
				int len;
				len = LengthLQueue(q);
				printf("Queue length is %d\n", len);
				break;
			}

		case 5:
			if (q->judge == -1)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			flag = IsEmptyLQueue(q);
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
			flag = GetHeadLQueue(q, e);
			if (flag == TRUE)
			{
				LPrint(e, q->front->type);
				printf_s("\n");
				break;
			}
			break;

		case 7:
			ClearLQueue(q);
			break;

		case 8:
			 DestoryLQueue(q);
			break;

		case 9:
			if (q->judge == -1)
			{
				printf_s("Please initialize the queue first£¡\n");
				break;
			}
			flag = TraverseLQueue(q, foo);
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

		case 10:
			system("cls");
			PrintMenu_1();
			break;

		case 11:
			printf_s("End process\n");
			break;

		default:
			printf_s("Fail to identify\n");
		}
	}
	system("pause");
	return 0;
}