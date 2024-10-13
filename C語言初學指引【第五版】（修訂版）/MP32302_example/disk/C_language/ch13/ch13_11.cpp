/*    檔名:ch13_11.cpp    功能:利用建構函式初始化堆疊的top變數   */

#include <stdlib.h>
#include <stdio.h>

#define MaxStackSize 100     // 堆疊元素最大容量

class StackADT
{
   private:
      int stack[MaxStackSize];
      int top;
      bool isEmpty()     //  測試堆疊是否已空
      {
         if(top<0) return true;
         else return false;
      }
      bool isFull()      //  測試堆疊是否已滿
      {
         if(top>=MaxStackSize-1) return true;
         else return false;
      }
   public:
      StackADT()                //建構函式,會在物件實體建立時自動執行
      {
         top=-1;
      }
      void push(int item)      //  將item push到堆疊內
      {
         if(isFull()==true)
         {
            printf("堆疊已滿!");
            exit(1);
         }
         else
            stack[++top]=item;
       }
       int pop()                // 由堆疊 pop出一個元素
       {
         if(isEmpty()==true)
         {
            printf("堆疊已空!");
            exit(1);
         }
         else
           return  stack[top--];
       }
};

int main(void)                        // 主函式測試堆疊功能
{
 int data;
 StackADT S1;          // 建立一個堆疊物件實體S1,會自動執行建構函式

 S1.push(10);          // 疊入10
 S1.push(20);          // 疊入20
 S1.push(30);          // 疊入30
 data= S1.pop();         // 疊出,data應該為30
 printf("data=%d\n",data);
 data= S1.pop();         // 疊出,data應該為20
 printf("data=%d\n",data);
 /* system("pause"); */
 return 0;
}

