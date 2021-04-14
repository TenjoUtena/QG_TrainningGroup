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
//ѭ�����нṹ

typedef struct Aqueue
{
    void* data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
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
  *  @description : ��ʼ������
  *  @param       : Q ����ָ��Q
  *  @notice      : None
  */
void InitAQueue(AQueue* Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *  @description : ���ٶ���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q);


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *  @description : �������Ƿ�����
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q);


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q);


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q ����ָ��Q�����Ԫ��e
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue* Q, void* e);


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *  @description : ȷ�����г���
 *  @param       : Q ����ָ��Q
 *  @return      : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q);


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue* Q, void* data);


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q);


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q);


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *  @description : ������������
 *  @param       : Q ����ָ��Q����������ָ��foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q, int type));


/**
 *  @name        : void APrint(void* q, int type)
 *  @description : ��������
 *  @param       : q ָ��q, type ��������
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
 *  @param       : Q ָ��Q, seletion selet
 *  @notice      : None
 */
void selection(AQueue* q, int selet);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED