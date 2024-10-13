/*    郎:ch9_03.c    :办跑计籔跋办跑计   */

#include <stdio.h>
#include <stdlib.h>

int a=10;

void func1(void)
{
 int a=5;
 a=a+1;
 printf("func1 a=%d\n",a);
}

void func2(void)
{
 a=a+1;
 printf("办 a=%d\n",a);
}

void main(void)
{
 int a=20;
 a=a+1;
 printf("main a=%d\n",a);
 func1();
 func2();
 /*  system("pause");  */
}
