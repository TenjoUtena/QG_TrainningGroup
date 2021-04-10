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
   //��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
    int type;
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
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
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q);


/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q e ����ָ��Q,��������ָ��e
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e);


/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : ȷ�����г���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q);


/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q ����ָ��Q,�������ָ��data
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data);

 
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : ���Ӳ���
 *  @param       : Q ����ָ��Q
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q);


/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q);


/**
 *  @name        : Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int type))
 *  @description : ������������
 *  @param       : Q ����ָ��Q����������ָ��foo
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int type));

/**
 *  @name        : void LPrint(void* q, int type);
 *  @description : ��������
 *  @param       : q ָ��q, int datatype type
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