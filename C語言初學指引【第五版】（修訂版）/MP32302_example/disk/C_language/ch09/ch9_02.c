/*    �ɦW:ch9_02.c    �\��:�����ܼƻP�ϰ��ܼ�     */

#include <stdio.h>
#include <stdlib.h>

int a=10;
void func1(void);

void main(void)
{
 int c=20;
 
 printf("a=%d\n",a);
 /* printf("b=%d\n",b); */  /*  �o�O�����ԭz  */
 func1();
 /*  system("pause");  */
}

int b=100;

void func1(void)
{
 printf("a=%d\n",a);
 printf("b=%d\n",b);
}
