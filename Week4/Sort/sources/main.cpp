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
		printf_s("你的选择是：");
		while (scanf_s("%d", &choice) == 0 || getchar() != '\n')
		{
			printf("非法输入! 请再次输入:");
			while (getchar() != '\n');
		}
		switch (choice)
		{
		case 1:
			writetxt_1(data);
			flag1 = 1;
			printf_s("已随机生成数据量为10,000的数组数据。\n");
			break;

		case 2:
			writetxt_2(data);
			flag2 = 1;
			printf_s("已随机生成数据量为50,000的数组数据。\n");
			break;


		case 3:
			writetxt_3(data);
			flag3 = 1;
			printf_s("已随机生成数据量为200,000的数组数据。\n");
			break;

		case 4:
			if (flag1 == 0)
			{
				printf_s("请先随机生成相应的数据！\n");
				break;
			}
			else
			{
				printf_s("以下输出的是数据量为10000的排序函数运行时间\n");
				Time_1(data, temp);
				break;
			}

		case 5:
			if (flag2 == 0)
			{
				printf_s("请先随机生成相应的数据！\n");
				break;
			}
			else
			{
				printf_s("以下输出的是数据量为50000的排序函数运行时间\n");
				Time_2(data, temp);
				break;
			}

		case 6:
			if (flag3 == 0)
			{
				printf_s("请先随机生成相应的数据！\n");
				break;
			}
			else
			{
				printf_s("以下输出的是数据量为200000的排序函数运行时间，请稍等一下~\n");
				Time_3(data, temp);
				break;
			}

		case 7:
			printf_s("请输入想生成的整数数量:");
			while (scanf_s("%d", &n) == 0 || getchar() != '\n')
			{
				printf("非法输入! 请再次输入:");
				while (getchar() != '\n');
			}
			if (n < 1 || n > 200000)
			{
				printf("输入数过大或过小！\n", n);
				break;
			}
			else
			{
				writetxt(data,n);
				printf_s("已随机生成数据量为%d的数组数据。\n",n);
				printf_s("以下输出的是数据量为%d的排序函数运行时间，请稍等一下~\n",n);
				Time(data, temp, n);
				break;
			}
		
		case 8:
			printf_s("请输入排序次数k:");
			while (scanf_s("%d", &k) == 0 || getchar() != '\n')
			{
				printf("非法输入! 请再次输入:");
				while (getchar() != '\n');
			}
			printf_s("可能要耐心等候一段时间\n");
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
			printf("*插入排序的用时为： %d ms\n", duration);

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
			printf("*归并排序的用时为： %d ms\n", duration);

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
			printf("*三数取中法快速排序的用时为： %d ms\n", duration);

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
			printf("*计数排序的用时为： %d ms\n", duration);

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
			printf("*基数计数排序的用时为： %d ms\n", duration);

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
			printf("*非递归快速排序的用时为： %d ms\n", duration);
			break;

		case 9:
			printf_s("随机生成10个数用于测试：\n");
			srand((unsigned)time(NULL));
			for (int i = 0; i < 10; i++)
			{
				data[i] = rand();
				printf_s("%d ", data[i]);
			}
			printf_s("\n请输入K值：");
			while (scanf_s("%d", &k) == 0 || getchar() != '\n')
			{
				printf("非法输入! 请再次输入:");
				while (getchar() != '\n');
			}
			if (k < 1 || k>10)
			{
				printf("不存在第%d小的数哦\n",k);
				break;
			}
			else
			{
				n = findK(data, 0, 9, k - 1);
				printf("第%d小的数为%d\n", k, n);
				break;
			}

		case 10:
			printf_s("请输入数组的长度：(最大只能20w)\n");
			while (scanf_s("%d", &n) == 0 || getchar() != '\n')
			{
				printf("非法输入! 请再次输入:");
				while (getchar() != '\n');
			}
			if (n <= 0 || n > 200000)
			{
				printf_s("长度过小或过大！\n");
				break;
			}
			printf_s("随机生成%d个数用于测试：\n",n);
			srand((unsigned)time(NULL));
			for (i = 0; i < n; i++)
			{
				data[i] = rand()%3;
				printf_s("%d ", data[i]);
				if ((i+1) % 10 == 0)
					printf_s("\n");
			}
			ColorSort(data, n);
			printf_s("\n排序后的结果为：\n");
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
			printf_s("结束程序\n");
			break;

		default:
			printf_s("识别失败\n");
		}
	}
	system("pause");
	return 0;
}

