#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>

void PrintMenu()
{
	printf_s(
	" ******************************************************\n"
		"               *欢迎使用测试程序*\n"
		"               *请输入对应的序号*\n"
		"|-----1.随机生成10,000个正整数               -----|\n"
		"|-----2.随机生成50,000个正整数               -----|\n"
		"|-----3.随机生成200,000个正整数              -----|\n"
		"|-----4.数据量为10,000的情况下输出排序用时   -----|\n"
		"|-----5.数据量为50,000的情况下输出排序用时   -----|\n"
		"|-----6.数据量为200,000的情况下输出排序用时  -----|\n"
		"|-----7.随机n个正整数并输出排序用时          -----|\n"
		"|-----           (0<n<=200,000)              -----|\n"
		"|-----8.输出排序函数在大量小数组下的排序用时 -----|\n"
		"|-----           (100数据*k次排序)           -----|\n"
		"|-----9.在一个无序序列中找到第K小的数        -----|\n"
		"|-----10.颜色排序                            -----|\n"
		"|-----11.清屏                                -----|\n"
		"|-----12.结束程序                            -----|\n"
		"***************************************************\n\n\n");
}

void writetxt(int* data, int n)
{
	int i;
	FILE* fp;
	fp = fopen("data.txt", "w");
	fclose(fp);
	fp = fopen("data.txt", "a");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
		data[i] = rand();
	for (i = 0; i < n; i++)
		fprintf_s(fp, "%d ", data[i]);
	fclose(fp);
}

void readtxt(int* data, int n)
{
	int i;
	FILE* fp;
	fp = fopen("data.txt", "r");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	for (i = 0; i < n; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);
}

void writetxt_1(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_1.txt", "w");
	fclose(fp);
	fp = fopen("data_1.txt", "a");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < 10000; i++)
		data[i] = rand();
	for (i = 0; i < 10000; i++)
		fprintf_s(fp, "%d ", data[i]);
	fclose(fp);
}

void writetxt_2(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_2.txt", "w");
	fclose(fp);
	fp = fopen("data_2.txt", "a");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < 50000; i++)
		data[i] = rand();
	for (i = 0; i < 50000; i++)
		fprintf_s(fp, "%d ", data[i]);
	fclose(fp);
}

void writetxt_3(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_3.txt", "w");
	fclose(fp);
	fp = fopen("data_3.txt", "a");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < 200000; i++)
		data[i] = rand();
	for (i = 0; i < 200000; i++)
		fprintf_s(fp, "%d ", data[i]);
	fclose(fp);
}

void readtxt_1(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_1.txt", "r");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	for (i = 0; i < 10000; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);
}

void readtxt_2(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_2.txt", "r");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	for (i = 0; i < 50000; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);
}

void readtxt_3(int* data)
{
	int i;
	FILE* fp;
	fp = fopen("data_3.txt", "r");
	if (!fp)
	{
		printf_s("打开文档失败!");
		return;
	}
	for (i = 0; i < 200000; i++)
	{
		fscanf_s(fp, "%d", &data[i]);
	}
	fclose(fp);
}

void Time(int* data, int* temp, int n)
{
	readtxt(data, n);
	clock_t start = clock();
	insertSort(data, n);
	clock_t duration = clock() - start;
	printf("*插入排序的用时为： %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	MergeSort(data, 0, n - 1, temp);
	duration = clock() - start;
	printf("*归并排序的用时为： %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	QuickSort_Recursion(data, 0, n - 1);
	duration = clock() - start;
	printf("*三数取中法快速排序的用时为： %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	CountSort(data, n, FindMax(data, n));
	duration = clock() - start;
	printf("*计数排序的用时为： %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	RadixCountSort(data, n);
	duration = clock() - start;
	printf("*基数计数排序的用时为： %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	QuickSort(data, n);
	duration = clock() - start;
	printf("*非递归快速排序的用时为： %d ms\n", duration);
}

void Time_1(int* data, int* temp)
{
	readtxt_1(data);
	clock_t start = clock();
	insertSort(data, 10000);
	clock_t duration = clock() - start;
	printf("*插入排序的用时为： %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	MergeSort(data, 0, 10000 - 1, temp);
	duration = clock() - start;
	printf("*归并排序的用时为： %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	QuickSort_Recursion(data, 0, 10000 - 1);
	duration = clock() - start;
	printf("*三数取中法快速排序的用时为： %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	CountSort(data, 10000, FindMax(data, 10000));
	duration = clock() - start;
	printf("*计数排序的用时为： %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	RadixCountSort(data, 10000);
	duration = clock() - start;
	printf("*基数计数排序的用时为： %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	QuickSort(data, 10000);
	duration = clock() - start;
	printf("*非递归快速排序的用时为： %d ms\n", duration);
}

void Time_2(int* data, int* temp)
{
	readtxt_2(data);
	clock_t start = clock();
	insertSort(data, 50000);
	clock_t duration = clock() - start;
	printf("*插入排序的用时为： %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	MergeSort(data, 0, 50000 - 1, temp);
	duration = clock() - start;
	printf("*归并排序的用时为： %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	QuickSort_Recursion(data, 0, 50000 - 1);
	duration = clock() - start;
	printf("*三数取中法快速排序的用时为： %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	CountSort(data, 50000, FindMax(data, 50000));
	duration = clock() - start;
	printf("*计数排序的用时为： %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	RadixCountSort(data, 50000);
	duration = clock() - start;
	printf("*基数计数排序的用时为： %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	QuickSort(data, 50000);
	duration = clock() - start;
	printf("*非递归快速排序的用时为： %d ms\n", duration);
}

void Time_3(int* data, int* temp)
{
	readtxt_3(data);
	clock_t start = clock();
	insertSort(data, 200000);
	clock_t duration = clock() - start;
	printf("*插入排序的用时为： %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	MergeSort(data, 0, 200000 - 1, temp);
	duration = clock() - start;
	printf("*归并排序的用时为： %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	QuickSort_Recursion(data, 0, 200000 - 1);
	duration = clock() - start;
	printf("*三数取中法快速排序的用时为： %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	CountSort(data, 200000, FindMax(data, 200000));
	duration = clock() - start;
	printf("*计数排序的用时为： %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	RadixCountSort(data, 200000);
	duration = clock() - start;
	printf("*基数计数排序的用时为： %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	QuickSort(data, 200000);
	duration = clock() - start;
	printf("*非递归快速排序的用时为： %d ms\n", duration);
}

