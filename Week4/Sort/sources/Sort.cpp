#include <stdio.h>
#include "Sort.h"
#include <malloc.h>
#include <time.h>
#include <stdlib.h>


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n)
{
	if (n < 2)
		return;
	int temp, i, j;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; (j >= 0 && a[j] > temp); j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
	return;
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid + 1, end, temp);
	MergeArray(a, begin, mid+1, end, temp);
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin, j = mid, k = 0;
	while (i < mid && j <= end)
			temp[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i < mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[begin + i] = temp[i];
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin > end)
		return;
	Partition(a, begin, end);
	int i, j, temp, t;
	i = begin;
	j = end;
	temp = Partition(a, begin, end);
	while (i != j)
	{
		while (a[i] <= temp && i < j)
			i++;
		while (a[j] >= temp && i < j)
			j--;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	if (i < end)
		swap(&a[i], &a[end - 1]);
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
	return;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		if (a[begin] > a[mid])
			swap(&a[begin], &a[mid]);
		if (a[begin] > a[end])
			swap(&a[begin], &a[end]);
		if (a[end] < a[mid])
			swap(&a[end], &a[mid]);
		swap(&a[end - 1], &a[mid]);
		return a[end - 1];
	}
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size)
{
	LinkStack* inn = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(inn);
	pushLStack(inn, 0);
	pushLStack(inn, size-1);

	while (isEmptyLStack(inn) == 0)
	{
		int right = getTopLStack(inn);
		popLStack(inn);
		int left = getTopLStack(inn);
		popLStack(inn);

		int temp = partsort(a, left, right);
		if (temp - 1 > left)
		{
			pushLStack(inn, left);
			pushLStack(inn, temp - 1);
		}
		if (temp + 1 < right)
		{
			pushLStack(inn, temp + 1);
			pushLStack(inn, right);
		}
	}
}

int partsort(int* a, int left, int right)
{
	int ponit = a[left];
	int temp = left;

	while (left <= right)
	{
		while (left <= right)
		{
			if (a[right] < ponit)
			{
				a[left] = a[right];
				left++;
				temp = right;
				break;
			}
			else
				right--;
		}
		while (left <= right)
		{
			if (a[left] > ponit)
			{
				a[right] = a[left];
				right--;
				temp = left;
				break;
			}
			else
				left++;
		}
	}
	a[temp] = ponit;
	return temp;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
	int i,j,k=0;
	int* p = (int*)malloc(sizeof(int) * (max+1));
	for (i = 0; i < max + 1; i++)
	{
		p[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		p[a[i]]++;
	}
	for (i = 0; i < max+1; i++)
	{
		for (j = 0; j < p[i]; j++)
			a[k++] = i;
	}
	free(p);
	p = NULL;
	return;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	int max = FindMax(a,size);
	int iexp, i;
	int* p = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		p[i] = 0;
	}
	for (iexp = 1; max / iexp > 0; iexp = iexp * 10)
	{
		int buckets[10] = { 0 };

		for (i = 0; i < size; i++)
			buckets[(a[i] / iexp) % 10]++;
		for (i = 1; i < 10; i++)
			buckets[i] += buckets[i - 1];
		for (i = size-1; i >= 0; i--)
			p[--buckets[(a[i] / iexp) % 10]] = a[i];
		for (i = 0; i < size; i++)
			a[i] = p[i];
	}
	free(p);
	p = NULL;
}

/**
  *  @name        : int FindMax(int* a, int n)
  *  @description : find max in the array
  *  @param       : arraypointer a, the lenth of array n
  */
int FindMax(int* a,int n)
{
	int i, max = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

/**
 *  @name        : int findK(int* a, int left, int right, int k)
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : arraypointer a，startpoint left, endpoint right, the position of num
 */
int findK(int* a, int left, int right, int k)
{
	if (left >= right)
		return a[left];
	int i = left;
	int j = right;
	int temp = a[left];
	while (i < j)
	{
		while (i < j && a[j] >= temp)
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp)
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	if (i == k)
		return a[k];
	else
	{
		if (i > k)
			return findK(a, left, i, k);
		else
			return findK(a, i + 1, right, k);
	}
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	int p0 = 0,  p2 = size - 1, p = 0;
	while (p < p2)
	{
		if (a[p] == 0)
		{
			while (a[p0] == 0 && p0 < p)
				p0++;
			if (p0 < p)
				swap(&a[p],&a[p0]);
		}
		if (a[p] == 2 )
		{
			while (a[p2] == 2 && p2 > p)
				p2--;
			if (p2 > p)
				swap(&a[p], &a[p2]);
		}
		if (a[p] == 1 || p == p0)
			p++;
	}
}
/**
 *  @name        : void swap(int* a, int* b)
 *  @description : exchang two int numbers
 *  @param       : intpointer a, intpointer b
 */
void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
