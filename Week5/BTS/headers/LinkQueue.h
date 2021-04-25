/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                   :   Win 10
 *    Create Data              :   2021.4.24
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

#include "Tree.h"
  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   //链式队列结构
typedef struct node
{
    NodePtr data;                  
    struct node* next;            
    int type;
} LQNode;

typedef struct Lqueue
{
    LQNode* front;                   //队头
    LQNode* rear;                    //队尾
    size_t data_size;
} LQueue;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} QStatus;

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
 *  @name        : int IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
int IsEmptyLQueue(const LQueue* Q);


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
QStatus EnLQueue(LQueue* Q, NodePtr data);


/**
 *  @name        : QStatus DeLQueue(LQueue* Q, NodePtr* data)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
QStatus DeLQueue(LQueue* Q, NodePtr* data);


/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q);

/**
 *  @name        : void PrintMenu_1()
 *  @description : Print the menu1
 *  @param       : None
 *  @notice      : None
 */

int LengthLQueue(LQueue* Q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED
