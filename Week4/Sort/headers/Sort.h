#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size);
int partsort(int* a, int left, int right);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : int findK(int* a, int left, int right, int k)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : arraypointer a，startpoint left, endpoint right, the position of num
 */
int findK(int* a, int left, int right, int k);

 /**
  *  @name        : int FindMax(int* a, int n)
  *  @description : find max in the array
  *  @param       : arraypointer a, the lenth of array n
  */
int FindMax(int* a, int n);

/**
 *  @name        : void swap(int* a, int* b)
 *  @description : exchang two int numbers
 *  @param       : intpointer a, intpointer b
 */
void swap(int* a, int* b);

void writetxt(int* data, int n);
void writetxt_1(int* data);
void writetxt_2(int* data);
void writetxt_3(int* data);

void Time(int* data, int* temp, int n);
void Time_1(int* data, int* temp);
void Time_2(int* data, int* temp);
void Time_3(int* data, int* temp);

void readtxt(int* data, int n);
void readtxt_1(int* data);
void readtxt_2(int* data);
void readtxt_3(int* data);

void PrintMenu();

void initLStack(LinkStack* s);
void clearLStack(LinkStack* s);
void destroyLStack(LinkStack* s);
void pushLStack(LinkStack* s, ElemType data);
void popLStack(LinkStack* s);
int isEmptyLStack(LinkStack* s);
int getTopLStack(LinkStack* s);
#endif // QUEUE_H_INCLUDED