#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>

void PrintMenu()
{
	printf_s(
	" ******************************************************\n"
		"               *��ӭʹ�ò��Գ���*\n"
		"               *�������Ӧ�����*\n"
		"|-----1.�������10,000��������               -----|\n"
		"|-----2.�������50,000��������               -----|\n"
		"|-----3.�������200,000��������              -----|\n"
		"|-----4.������Ϊ10,000����������������ʱ   -----|\n"
		"|-----5.������Ϊ50,000����������������ʱ   -----|\n"
		"|-----6.������Ϊ200,000����������������ʱ  -----|\n"
		"|-----7.���n�������������������ʱ          -----|\n"
		"|-----           (0<n<=200,000)              -----|\n"
		"|-----8.����������ڴ���С�����µ�������ʱ -----|\n"
		"|-----           (100����*k������)           -----|\n"
		"|-----9.��һ�������������ҵ���KС����        -----|\n"
		"|-----10.��ɫ����                            -----|\n"
		"|-----11.����                                -----|\n"
		"|-----12.��������                            -----|\n"
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
		printf_s("���ĵ�ʧ��!");
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
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	MergeSort(data, 0, n - 1, temp);
	duration = clock() - start;
	printf("*�鲢�������ʱΪ�� %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	QuickSort_Recursion(data, 0, n - 1);
	duration = clock() - start;
	printf("*����ȡ�з������������ʱΪ�� %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	CountSort(data, n, FindMax(data, n));
	duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	RadixCountSort(data, n);
	duration = clock() - start;
	printf("*���������������ʱΪ�� %d ms\n", duration);

	readtxt(data, n);
	start = clock();
	QuickSort(data, n);
	duration = clock() - start;
	printf("*�ǵݹ�����������ʱΪ�� %d ms\n", duration);
}

void Time_1(int* data, int* temp)
{
	readtxt_1(data);
	clock_t start = clock();
	insertSort(data, 10000);
	clock_t duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	MergeSort(data, 0, 10000 - 1, temp);
	duration = clock() - start;
	printf("*�鲢�������ʱΪ�� %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	QuickSort_Recursion(data, 0, 10000 - 1);
	duration = clock() - start;
	printf("*����ȡ�з������������ʱΪ�� %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	CountSort(data, 10000, FindMax(data, 10000));
	duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	RadixCountSort(data, 10000);
	duration = clock() - start;
	printf("*���������������ʱΪ�� %d ms\n", duration);

	readtxt_1(data);
	start = clock();
	QuickSort(data, 10000);
	duration = clock() - start;
	printf("*�ǵݹ�����������ʱΪ�� %d ms\n", duration);
}

void Time_2(int* data, int* temp)
{
	readtxt_2(data);
	clock_t start = clock();
	insertSort(data, 50000);
	clock_t duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	MergeSort(data, 0, 50000 - 1, temp);
	duration = clock() - start;
	printf("*�鲢�������ʱΪ�� %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	QuickSort_Recursion(data, 0, 50000 - 1);
	duration = clock() - start;
	printf("*����ȡ�з������������ʱΪ�� %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	CountSort(data, 50000, FindMax(data, 50000));
	duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	RadixCountSort(data, 50000);
	duration = clock() - start;
	printf("*���������������ʱΪ�� %d ms\n", duration);

	readtxt_2(data);
	start = clock();
	QuickSort(data, 50000);
	duration = clock() - start;
	printf("*�ǵݹ�����������ʱΪ�� %d ms\n", duration);
}

void Time_3(int* data, int* temp)
{
	readtxt_3(data);
	clock_t start = clock();
	insertSort(data, 200000);
	clock_t duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	MergeSort(data, 0, 200000 - 1, temp);
	duration = clock() - start;
	printf("*�鲢�������ʱΪ�� %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	QuickSort_Recursion(data, 0, 200000 - 1);
	duration = clock() - start;
	printf("*����ȡ�з������������ʱΪ�� %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	CountSort(data, 200000, FindMax(data, 200000));
	duration = clock() - start;
	printf("*�����������ʱΪ�� %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	RadixCountSort(data, 200000);
	duration = clock() - start;
	printf("*���������������ʱΪ�� %d ms\n", duration);

	readtxt_3(data);
	start = clock();
	QuickSort(data, 200000);
	duration = clock() - start;
	printf("*�ǵݹ�����������ʱΪ�� %d ms\n", duration);
}

