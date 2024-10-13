/*    檔名:ch7_17.cpp    功能:製作swap函式    */

#include <stdio.h>
#include <stdlib.h>

void swap(int &a,int &b)    // 或 void swap(int& a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}

int main(void)
{
 int m=20,n=60;
 printf("變換前(m,n)=(%d,%d)\n",m,n);
 swap(m,n);
 printf("變換後(m,n)=(%d,%d)\n",m,n);
 /*  system("pause");  */
 return 0;
}
