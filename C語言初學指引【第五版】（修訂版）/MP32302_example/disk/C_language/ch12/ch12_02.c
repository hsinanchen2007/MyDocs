/*    �ɦW:ch12_02.c    �\��:��{��C���[�J�P�R��    */

#include <stdio.h>
#include <stdlib.h>

#define MaxQueueSize 100       /* ��C�����̤j�e�q */

typedef struct{               /* �ŧi��C��Ƶ��c�A���]�t�e��,�����ܼƻP�}�C */
   int queue[MaxQueueSize];
   int front;
   int rear;
}QueueADT;

QueueADT CreateQueue()             /*  �إߦ�C�H�Ϊ�l�Ʀ�C */
{
  QueueADT NewQueue;
  NewQueue.front=-1;
  NewQueue.rear=-1;
  return NewQueue;
}

int isEmpty(QueueADT Q)       /*  ���զ�CQ�O�_�w�� */
{
   if(Q.front>=Q.rear) return 1;
   else return 0;
}

int isFull(QueueADT Q)        /*  ���զ�CQ�O�_�w�� */
{
   if(Q.rear>=MaxQueueSize-1) return 1;
   else return 0;
}

void AddQ(QueueADT *Q,int item)     /*  �Nitem�[�J��CQ������ */
{
  if(isFull(*Q)==1)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
    Q->queue[++Q->rear]=item;
}

int DeleteQ(QueueADT *Q)            /* �Ѧ�CQ�e�ݨ��X�@�Ӥ���  */
{
  if(isEmpty(*Q)==1)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
    return  Q->queue[++Q->front];
}

int main(void)
{
 int data;

 QueueADT Q1;
 Q1=CreateQueue();      /* �إߦ�C */

 AddQ(&Q1,10);          /* �[�J10 */
 AddQ(&Q1,20);          /* �[�J20 */
 AddQ(&Q1,30);          /* �[�J30 */
 data=DeleteQ(&Q1);          /* ���X,data���Ӭ�10 */
 printf("data=%d\n",data);
 data=DeleteQ(&Q1);          /* ���X,data���Ӭ�20 */
 printf("data=%d\n",data);
 /*  system("pause"); */
 return 0;
}
