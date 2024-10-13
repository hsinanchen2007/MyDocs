/*    �ɦW:ch12_01.c    �\��:��{���|���|�J�P�|�X    */

#include <stdio.h>
#include <stdlib.h>

#define MaxStackSize 100     /* ���|�����̤j�e�q */

typedef struct{              /* �ŧi���|��Ƶ��c�A���]�t�@�ӳ��ݫ��ܻP�}�C */
   int stack[MaxStackSize];
   int top;
}StackADT;

StackADT CreateStack()       /*  �إ߰��|�H�Ϊ�l�ư��| */
{
  StackADT NewStack;
  NewStack.top=-1;
  return NewStack;
}

int isEmpty(StackADT S)     /*  ���հ��|S�O�_�w�� */
{
   if(S.top<0) return 1;
   else return 0;
}

int isFull(StackADT S)      /*  ���հ��|S�O�_�w�� */
{
   if(S.top>=MaxStackSize-1) return 1;
   else return 0;
}

void push(StackADT *S,int item)      /*  �Nitem push����|S�� */
{
  if(isFull(*S)==1)
  {
     printf("���|�w��!");
     exit(1);
  }
  else
    S->stack[++S->top]=item;
}

int pop(StackADT *S)                /* �Ѱ��|S pop�X�@�Ӥ���  */
{
  if(isEmpty(*S)==1)
  {
     printf("���|�w��!");
     exit(1);
  }
  else
    return  S->stack[S->top--];
}

int main(void)
{
 int data;

 StackADT S1;
 S1=CreateStack();      /* �إ߰��| */

 push(&S1,10);          /* �|�J10 */
 push(&S1,20);          /* �|�J20 */
 push(&S1,30);          /* �|�J30 */
 data=pop(&S1);         /* �|�X,data���Ӭ�30 */
 printf("data=%d\n",data);
 data=pop(&S1);         /* �|�X,data���Ӭ�20 */
 printf("data=%d\n",data);
 /*  system("pause");  */
 return 0;
}

