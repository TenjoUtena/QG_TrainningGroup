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
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size);
int partsort(int* a, int left, int right);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : int findK(int* a, int left, int right, int k)
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : arraypointer a��startpoint left, endpoint right, the position of num
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