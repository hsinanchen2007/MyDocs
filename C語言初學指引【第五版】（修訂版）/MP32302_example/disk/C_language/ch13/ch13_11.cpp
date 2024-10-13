/*    �ɦW:ch13_11.cpp    �\��:�Q�Ϋغc�禡��l�ư��|��top�ܼ�   */

#include <stdlib.h>
#include <stdio.h>

#define MaxStackSize 100     // ���|�����̤j�e�q

class StackADT
{
   private:
      int stack[MaxStackSize];
      int top;
      bool isEmpty()     //  ���հ��|�O�_�w��
      {
         if(top<0) return true;
         else return false;
      }
      bool isFull()      //  ���հ��|�O�_�w��
      {
         if(top>=MaxStackSize-1) return true;
         else return false;
      }
   public:
      StackADT()                //�غc�禡,�|�b�������إ߮ɦ۰ʰ���
      {
         top=-1;
      }
      void push(int item)      //  �Nitem push����|��
      {
         if(isFull()==true)
         {
            printf("���|�w��!");
            exit(1);
         }
         else
            stack[++top]=item;
       }
       int pop()                // �Ѱ��| pop�X�@�Ӥ���
       {
         if(isEmpty()==true)
         {
            printf("���|�w��!");
            exit(1);
         }
         else
           return  stack[top--];
       }
};

int main(void)                        // �D�禡���հ��|�\��
{
 int data;
 StackADT S1;          // �إߤ@�Ӱ��|�������S1,�|�۰ʰ���غc�禡

 S1.push(10);          // �|�J10
 S1.push(20);          // �|�J20
 S1.push(30);          // �|�J30
 data= S1.pop();         // �|�X,data���Ӭ�30
 printf("data=%d\n",data);
 data= S1.pop();         // �|�X,data���Ӭ�20
 printf("data=%d\n",data);
 /* system("pause"); */
 return 0;
}

