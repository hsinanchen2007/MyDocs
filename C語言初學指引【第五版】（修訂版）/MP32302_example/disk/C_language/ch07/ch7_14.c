/*    �ɦW:ch7_14.c    �\��:�ǫ��ЩI�s   */

#include <stdio.h>
#include <stdlib.h>

void func1(int *a,int b)
{
 *a=*a + 10;
 b=b+100;
 printf("func1()��*a=%d\n",*a);
 printf("func1()��b=%d\n",b);
}

void main(void)
{
 int m=1,n=1;
 func1(&m,n);
 printf("main( )��m=%d\n",m);
 printf("main( )��n=%d\n",n);
 /*  system("pause");  */
}
