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

void PrintMenu();//打印菜单
Status Check_1(char*);//检查表达式中是否除了含数字，+，-，*，/，（，）外还有别的东西
Status Check_2(char*);//检查表达式中括号的匹配度
Status Check_3(char* exp);//检查运算符左边是不是数字或者')',右边是不是数字或者'('
Status Check_4(char* exp);//检查括号内是否为空
Status Check_5(char* exp);//检查小数点两边是否为数字
Status Check_6(char* exp);//检查是否全是数字
void initStack(SqStack* s, int sizes);
void initStack_double(SqStack_double* s, int sizes);//初始化栈
Status isEmptyStack(SqStack* s);//判断栈是否为空
void pushStack(SqStack* s, char data);
void pushStack_double(SqStack_double* s, double data);//入栈
void popStack(SqStack* s);
void popStack_double(SqStack_double* s);//出栈
char getTopStack(SqStack* s);
double getTopStack_double(SqStack_double* s);//得到栈顶元素
void TraverseSqStack(SqStack* s, void (*visit)(char e));//从栈底遍历栈
void visit(char e);//从栈底遍历栈
void clearStack(SqStack* s);//清空栈
SqStack* FreePointer(SqStack* s);//清空栈exp_suf
void clear(char* str);//清空数组
SqStack* change(char* exp, SqStack* exp_suf);//中缀表达式转后缀表达式
Status Calculate(SqStack* exp_suf, double* e);//计算结果

#endif