/*    檔名:ch12_01.c    功能:實現堆疊之疊入與疊出    */

#include <stdio.h>
#include <stdlib.h>

#define MaxStackSize 100     /* 堆疊元素最大容量 */

typedef struct{              /* 宣告堆疊資料結構，當中包含一個頂端指示與陣列 */
   int stack[MaxStackSize];
   int top;
}StackADT;

StackADT CreateStack()       /*  建立堆疊以及初始化堆疊 */
{
  StackADT NewStack;
  NewStack.top=-1;
  return NewStack;
}

int isEmpty(StackADT S)     /*  測試堆疊S是否已空 */
{
   if(S.top<0) return 1;
   else return 0;
}

int isFull(StackADT S)      /*  測試堆疊S是否已滿 */
{
   if(S.top>=MaxStackSize-1) return 1;
   else return 0;
}

void push(StackADT *S,int item)      /*  將item push到堆疊S內 */
{
  if(isFull(*S)==1)
  {
     printf("堆疊已滿!");
     exit(1);
  }
  else
    S->stack[++S->top]=item;
}

int pop(StackADT *S)                /* 由堆疊S pop出一個元素  */
{
  if(isEmpty(*S)==1)
  {
     printf("堆疊已空!");
     exit(1);
  }
  else
    return  S->stack[S->top--];
}

int main(void)
{
 int data;

 StackADT S1;
 S1=CreateStack();      /* 建立堆疊 */

 push(&S1,10);          /* 疊入10 */
 push(&S1,20);          /* 疊入20 */
 push(&S1,30);          /* 疊入30 */
 data=pop(&S1);         /* 疊出,data應該為30 */
 printf("data=%d\n",data);
 data=pop(&S1);         /* 疊出,data應該為20 */
 printf("data=%d\n",data);
 /*  system("pause");  */
 return 0;
}

