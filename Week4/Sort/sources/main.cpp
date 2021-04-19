#include "sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	clock_t start, duration;
	int data[200000], temp[200000];
	int choice = 0, flag1 = 0, flag2 = 0, flag3 = 0, i, j, k, n;
	PrintMenu();
	while (choice != 12)
	{
		printf_s("���ѡ���ǣ�");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("�Ƿ�����! ���ٴ�����:");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			writetxt_1(data);
			flag1 = 1;
			printf_s("���������������Ϊ10,000���������ݡ�\n");
			break;

		case 2:
			writetxt_2(data);
			flag2 = 1;
			printf_s("���������������Ϊ50,000���������ݡ�\n");
			break;


		case 3:
			writetxt_3(data);
			flag3 = 1;
			printf_s("���������������Ϊ200,000���������ݡ�\n");
			break;

		case 4:
			if (flag1 == 0)
			{
				printf_s("�������������Ӧ�����ݣ�\n");
				break;
			}
			else
			{
				printf_s("�����������������Ϊ10000������������ʱ��\n");
				Time_1(data, temp);
				break;
			}

		case 5:
			if (flag2 == 0)
			{
				printf_s("�������������Ӧ�����ݣ�\n");
				break;
			}
			else
			{
				printf_s("�����������������Ϊ50000������������ʱ��\n");
				Time_2(data, temp);
				break;
			}

		case 6:
			if (flag3 == 0)
			{
				printf_s("�������������Ӧ�����ݣ�\n");
				break;
			}
			else
			{
				printf_s("�����������������Ϊ200000������������ʱ�䣬���Ե�һ��~\n");
				Time_3(data, temp);
				break;
			}

		case 7:
			printf_s("�����������ɵ���������:");
			while (scanf_s("%d", &n) == 0 || getchar() != '\n')
			{
				printf("�Ƿ�����! ���ٴ�����:");
				while (getchar() != '\n');
			}
			if (n < 1 || n > 200000)
			{
				printf("������������С��\n", n);
				break;
			}
			else
			{
				writetxt(data,n);
				printf_s("���������������Ϊ%d���������ݡ�\n",n);
				printf_s("�����������������Ϊ%d������������ʱ�䣬���Ե�һ��~\n",n);
				Time(data, temp, n);
				break;
			}
		
		case 8:
			printf_s("�������������k:");
			while (scanf_s("%d", &k) == 0 || getchar() != '\n')
			{
				printf("�Ƿ�����! ���ٴ�����:");
				while (getchar() != '\n');
			}
			printf_s("����Ҫ���ĵȺ�һ��ʱ��\n");
			start = clock();
			for(i = 0;i<k;i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					insertSort(data, 100);
				}
			}
			duration = clock() - start;
			printf("*�����������ʱΪ�� %d ms\n", duration);

			start = clock();
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					MergeSort(data, 0, 100 - 1, temp);
				}
			}
			duration = clock() - start;
			printf("*�鲢�������ʱΪ�� %d ms\n", duration);

			start = clock();
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					QuickSort_Recursion(data, 0, 100 - 1);
				}
			}
			duration = clock() - start;
			printf("*����ȡ�з������������ʱΪ�� %d ms\n", duration);

			start = clock();
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					CountSort(data, 100, FindMax(data, 100));
				}
			}
			duration = clock() - start;
			printf("*�����������ʱΪ�� %d ms\n", duration);

			start = clock();
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					RadixCountSort(data, 100);
				}
			}
			duration = clock() - start;
			printf("*���������������ʱΪ�� %d ms\n", duration);

			start = clock();
			for (i = 0; i < k; i++)
			{
				for (j = 0; j < 100; j++)
				{
					data[i] = rand();
					QuickSort(data, 100);
				}
			}
			duration = clock() - start;
			printf("*�ǵݹ�����������ʱΪ�� %d ms\n", duration);
			break;

		case 9:
			printf_s("�������10�������ڲ��ԣ�\n");
			srand((unsigned)time(NULL));
			for (int i = 0; i < 10; i++)
			{
				data[i] = rand();
				printf_s("%d ", data[i]);
			}
			printf_s("\n������Kֵ��");
			while (scanf_s("%d", &k) == 0 || getchar() != '\n')
			{
				printf("�Ƿ�����! ���ٴ�����:");
				while (getchar() != '\n');
			}
			if (k < 1 || k>10)
			{
				printf("�����ڵ�%dС����Ŷ\n",k);
				break;
			}
			else
			{
				n = findK(data, 0, 9, k - 1);
				printf("��%dС����Ϊ%d\n", k, n);
				break;
			}

		case 10:
			printf_s("����������ĳ��ȣ�(���ֻ��20w)\n");
			while (scanf_s("%d", &n) == 0 || getchar() != '\n')
			{
				printf("�Ƿ�����! ���ٴ�����:");
				while (getchar() != '\n');
			}
			if (n <= 0 || n > 200000)
			{
				printf_s("���ȹ�С�����\n");
				break;
			}
			printf_s("�������%d�������ڲ��ԣ�\n",n);
			srand((unsigned)time(NULL));
			for (i = 0; i < n; i++)
			{
				data[i] = rand()%3;
				printf_s("%d ", data[i]);
				if ((i+1) % 10 == 0)
					printf_s("\n");
			}
			ColorSort(data, n);
			printf_s("\n�����Ľ��Ϊ��\n");
			for (i = 0; i < n; i++)
			{
				printf_s("%d ", data[i]);
				if ((i+1) % 10 == 0)
					printf_s("\n");
			}
			printf_s("\n");
			break;

		case 11:
			system("cls");
			PrintMenu();
			break;
			
		case 12:
			printf_s("��������\n");
			break;

		default:
			printf_s("ʶ��ʧ��\n");
		}
	}
	system("pause");
	return 0;
}

