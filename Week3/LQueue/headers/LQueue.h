/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                   :   Win 10
 *    Create Data              :   2021.4.10
 *    Author/Corportation      :   Yongyuan Zhou
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
  *    Multi-Include-Prevent Section
  **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   //链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
    int type;
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t data_size;
    int judge;
} LQueue;

typedef enum
{
    FALSE = 0, 
    TRUE = 1
} Status;

extern char datatype[30];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


 /**
  *  @name        : void InitLQueue(LQueue *Q)
  *  @description : 初始化队列
  *  @param       : Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* Q);


/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q);


/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q);


/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q e 队列指针Q,返回数据指针e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e);


/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q);


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data);

 
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q);


/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q);


/**
 *  @name        : Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int type))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int type));

/**
 *  @name        : void LPrint(void* q, int type);
 *  @description : 操作函数
 *  @param       : q 指针q, int datatype type
 *  @notice      : None
 */
void LPrint(void* q, int type);

/**
 *  @name        : void PrintMenu_1()
 *  @description : Print the menu1
 *  @param       : None
 *  @notice      : None
 */
void PrintMenu_1();

/**
 *  @name        : void PrintMenu_2()
 *  @description : Print the menu2
 *  @param       : None
 *  @notice      : None
 */
void PrintMenu_2();

void selection(LQueue* q, int selet);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED