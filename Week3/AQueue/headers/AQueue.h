#pragma once
/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Win10
 *    Create Data               :   2021.4.10
 *    Author/Corportation       :   Yongyuan Zhou
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
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

/**************************************************************
*    Macro Define Section
**************************************************************/
#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//循环队列结构

typedef struct Aqueue
{
    void* data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
    int type[MAXQUEUE];
} AQueue;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} Status;

extern char datatype[MAXQUEUE];
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
  *  @name        : void InitAQueue(AQueue *Q)
  *  @description : 初始化队列
  *  @param       : Q 队列指针Q
  *  @notice      : None
  */
void InitAQueue(AQueue* Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q);


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *  @description : 检查队列是否已满
 *  @param       : Q 队列指针Q
 *  @return      : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q);


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q);


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q 队列指针Q，存放元素e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue* Q, void* e);


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q 队列指针Q
 *  @return      : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q);


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue* Q, void* data);


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q);


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q);


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, int type));


/**
 *  @name        : void APrint(void* q, int type)
 *  @description : 操作函数
 *  @param       : q 指针q, type 数据类型
 *  @notice      : None
 */
void APrint(void* q, int type);


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

/**
 *  @name        : void selection(AQueue* Q, int selet)
 *  @description : a selection menu
 *  @param       : Q 指针Q, seletion selet
 *  @notice      : None
 */
void selection(AQueue* q, int selet);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED