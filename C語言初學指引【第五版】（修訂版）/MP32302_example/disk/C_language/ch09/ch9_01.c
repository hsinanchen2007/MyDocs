/*    �ɦW:ch9_01.c    �\��:�����ܼƻP�ϰ��ܼ�    */

#include <stdio.h>
#include <stdlib.h>

int a=10;

void func1(void)
{
 int b=5;
 a=a+1;
 b=b+1;
 /* c=c+1; */  /* �o�O�����ԭz  */
 printf("b=%d\n",b);
}

void main(void)
{
 int c=20;
 
 a=a+1;
 /* b=b+1; */  /*  �o�O�����ԭz  */
 c=c+1;
 printf("a=%d\n",a);
 func1();
 printf("a=%d\n",a);
 printf("c=%d\n",c);
 /*  system("pause");  */
}
