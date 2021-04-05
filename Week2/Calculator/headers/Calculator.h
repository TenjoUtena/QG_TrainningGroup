#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#define MAXSIZE 1000
#define MAXBUFFER 10

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef struct SqStack
{
	char* elem;
	int top;
	int size;
} SqStack;

typedef struct SqStack_double
{
	double* elem;
	int top;
	int size;
} SqStack_double;

void PrintMenu();//��ӡ�˵�
Status Check_1(char*);//�����ʽ���Ƿ���˺����֣�+��-��*��/���������⻹�б�Ķ���
Status Check_2(char*);//�����ʽ�����ŵ�ƥ���
Status Check_3(char* exp);//������������ǲ������ֻ���')',�ұ��ǲ������ֻ���'('
Status Check_4(char* exp);//����������Ƿ�Ϊ��
Status Check_5(char* exp);//���С���������Ƿ�Ϊ����
Status Check_6(char* exp);//����Ƿ�ȫ������
void initStack(SqStack* s, int sizes);
void initStack_double(SqStack_double* s, int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack* s);//�ж�ջ�Ƿ�Ϊ��
void pushStack(SqStack* s, char data);
void pushStack_double(SqStack_double* s, double data);//��ջ
void popStack(SqStack* s);
void popStack_double(SqStack_double* s);//��ջ
char getTopStack(SqStack* s);
double getTopStack_double(SqStack_double* s);//�õ�ջ��Ԫ��
void TraverseSqStack(SqStack* s, void (*visit)(char e));//��ջ�ױ���ջ
void visit(char e);//��ջ�ױ���ջ
void clearStack(SqStack* s);//���ջ
SqStack* FreePointer(SqStack* s);//���ջexp_suf
void clear(char* str);//�������
SqStack* change(char* exp, SqStack* exp_suf);//��׺���ʽת��׺���ʽ
Status Calculate(SqStack* exp_suf, double* e);//������

#endif