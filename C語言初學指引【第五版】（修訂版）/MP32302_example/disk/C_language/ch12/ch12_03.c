/*    �ɦW:ch12_03.c    �\��:�ϥΰ}�C��{������C    */

#include <stdio.h>
#include <stdlib.h>

#define MaxCQueueSize 100      /* ������C�����e�q */

typedef struct{            /* �ŧi������C��Ƶ��c�A���]�t�e��,�����ܼƻP�}�C */
   int cqueue[MaxCQueueSize];
   int front;
   int rear;
}CQueueADT;

CQueueADT CreateCQueue()      /*  �إ�������C�H�Ϊ�l�Ʀ�C */
{
  CQueueADT NewCQueue;
  NewCQueue.front=0;
  NewCQueue.rear=0;
  return NewCQueue;
}

int isEmpty(CQueueADT CQ)        /*  ����������CCQ�O�_�w�� */
{
   if(CQ.front==CQ.rear) return 1;
   else return 0;
}
                                  /*  ����������CCQ�O�_�w�� */
int isFull(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return 1;
   else return 0;
}

void AddCQ(CQueueADT *CQ,int item)    /*  �Nitem�[�J������CCQ������ */
{
  CQ->rear=(CQ->rear+1) % MaxCQueueSize;        /* �ϥξl�ƨM�w */
  if(isFull(*CQ)==1)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
    CQ->cqueue[CQ->rear]=item;
}

int DeleteCQ(CQueueADT *CQ)           /* ��������CCQ�e�ݨ��X�@�Ӥ���  */
{
  if(isEmpty(*CQ)==1)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
  {
    CQ->front=(CQ->front+1)%MaxCQueueSize;
    return  CQ->cqueue[CQ->front];
  }
}

int main(void)
{
 int data;

 CQueueADT CQ1;
 CQ1=CreateCQueue();      /* �إ�������C */

 AddCQ(&CQ1,10);          /* �[�J10 */
 AddCQ(&CQ1,20);          /* �[�J20 */
 AddCQ(&CQ1,30);          /* �[�J30 */
 data=DeleteCQ(&CQ1);          /* ���X,data���Ӭ�10 */
 printf("data=%d\n",data);
 data=DeleteCQ(&CQ1);          /* ���X,data���Ӭ�20 */
 printf("data=%d\n",data);
 /*  system("pause");  */
 return 0;
}
