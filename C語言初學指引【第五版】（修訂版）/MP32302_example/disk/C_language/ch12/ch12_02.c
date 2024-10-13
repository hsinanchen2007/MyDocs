/*    檔名:ch12_02.c    功能:實現佇列之加入與刪除    */

#include <stdio.h>
#include <stdlib.h>

#define MaxQueueSize 100       /* 佇列元素最大容量 */

typedef struct{               /* 宣告佇列資料結構，當中包含前端,尾端變數與陣列 */
   int queue[MaxQueueSize];
   int front;
   int rear;
}QueueADT;

QueueADT CreateQueue()             /*  建立佇列以及初始化佇列 */
{
  QueueADT NewQueue;
  NewQueue.front=-1;
  NewQueue.rear=-1;
  return NewQueue;
}

int isEmpty(QueueADT Q)       /*  測試佇列Q是否已空 */
{
   if(Q.front>=Q.rear) return 1;
   else return 0;
}

int isFull(QueueADT Q)        /*  測試佇列Q是否已滿 */
{
   if(Q.rear>=MaxQueueSize-1) return 1;
   else return 0;
}

void AddQ(QueueADT *Q,int item)     /*  將item加入佇列Q的尾端 */
{
  if(isFull(*Q)==1)
  {
     printf("佇列已滿!");
     exit(1);
  }
  else
    Q->queue[++Q->rear]=item;
}

int DeleteQ(QueueADT *Q)            /* 由佇列Q前端取出一個元素  */
{
  if(isEmpty(*Q)==1)
  {
     printf("佇列已空!");
     exit(1);
  }
  else
    return  Q->queue[++Q->front];
}

int main(void)
{
 int data;

 QueueADT Q1;
 Q1=CreateQueue();      /* 建立佇列 */

 AddQ(&Q1,10);          /* 加入10 */
 AddQ(&Q1,20);          /* 加入20 */
 AddQ(&Q1,30);          /* 加入30 */
 data=DeleteQ(&Q1);          /* 取出,data應該為10 */
 printf("data=%d\n",data);
 data=DeleteQ(&Q1);          /* 取出,data應該為20 */
 printf("data=%d\n",data);
 /*  system("pause"); */
 return 0;
}
