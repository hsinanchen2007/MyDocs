/*    �ɦW:ch7_17.cpp    �\��:�s�@swap�禡    */

#include <stdio.h>
#include <stdlib.h>

void swap(int &a,int &b)    // �� void swap(int& a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}

int main(void)
{
 int m=20,n=60;
 printf("�ܴ��e(m,n)=(%d,%d)\n",m,n);
 swap(m,n);
 printf("�ܴ���(m,n)=(%d,%d)\n",m,n);
 /*  system("pause");  */
 return 0;
}
