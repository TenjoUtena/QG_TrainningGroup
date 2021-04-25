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
   //��ʽ���нṹ
typedef struct node
{
    NodePtr data;                  
    struct node* next;            
    int type;
} LQNode;

typedef struct Lqueue
{
    LQNode* front;                   //��ͷ
    LQNode* rear;                    //��β
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
  *  @description : ��ʼ������
  *  @param       : Q ����ָ��Q
  *  @notice      : None
  */
void InitLQueue(LQueue* Q);


/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *  @description : ���ٶ���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q);


/**
 *  @name        : int IsEmptyLQueue(const LQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
int IsEmptyLQueue(const LQueue* Q);


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
QStatus EnLQueue(LQueue* Q, NodePtr data);


/**
 *  @name        : QStatus DeLQueue(LQueue* Q, NodePtr* data)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
QStatus DeLQueue(LQueue* Q, NodePtr* data);


/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
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
