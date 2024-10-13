/*    檔名:ch12_03.c    功能:使用陣列實現環狀佇列    */

#include <stdio.h>
#include <stdlib.h>

#define MaxCQueueSize 100      /* 環狀佇列元素容量 */

typedef struct{            /* 宣告環狀佇列資料結構，當中包含前端,尾端變數與陣列 */
   int cqueue[MaxCQueueSize];
   int front;
   int rear;
}CQueueADT;

CQueueADT CreateCQueue()      /*  建立環狀佇列以及初始化佇列 */
{
  CQueueADT NewCQueue;
  NewCQueue.front=0;
  NewCQueue.rear=0;
  return NewCQueue;
}

int isEmpty(CQueueADT CQ)        /*  測試環狀佇列CQ是否已空 */
{
   if(CQ.front==CQ.rear) return 1;
   else return 0;
}
                                  /*  測試環狀佇列CQ是否已滿 */
int isFull(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return 1;
   else return 0;
}

void AddCQ(CQueueADT *CQ,int item)    /*  將item加入環狀佇列CQ的尾端 */
{
  CQ->rear=(CQ->rear+1) % MaxCQueueSize;        /* 使用餘數決定 */
  if(isFull(*CQ)==1)
  {
     printf("佇列已滿!");
     exit(1);
  }
  else
    CQ->cqueue[CQ->rear]=item;
}

int DeleteCQ(CQueueADT *CQ)           /* 由環狀佇列CQ前端取出一個元素  */
{
  if(isEmpty(*CQ)==1)
  {
     printf("佇列已空!");
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
 CQ1=CreateCQueue();      /* 建立環狀佇列 */

 AddCQ(&CQ1,10);          /* 加入10 */
 AddCQ(&CQ1,20);          /* 加入20 */
 AddCQ(&CQ1,30);          /* 加入30 */
 data=DeleteCQ(&CQ1);          /* 取出,data應該為10 */
 printf("data=%d\n",data);
 data=DeleteCQ(&CQ1);          /* 取出,data應該為20 */
 printf("data=%d\n",data);
 /*  system("pause");  */
 return 0;
}
