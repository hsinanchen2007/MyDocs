/*    �ɦW:ch4_03.c    �\��:printf()�榡�ƲŸ�     */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int ch1 = 65;
 char ch2='A';
 char *str1="Hello!";
 int data1 = 123456;
 int data2 = -45678;
 float f1,f2,sum;
 int count;
 f1 = 3.1415926;
 f2 = 1.41421;
 sum = f1 + f2;
 
 printf("%%c�榡 %c\n",ch1);
 printf("%%c�榡 %c\n",ch2);
 printf("%%s�榡 %s\n",str1);
 printf("---------------------\n");
 printf("%%d�榡 %d  %%i�榡 %i\n",data1,data2);
 printf("%%o�榡 %o\n",data1);
 printf("%%u�榡 %u  %%u�榡 %u\n",data1,data2);
 printf("%%x�榡 %x  %%X�榡 %X\n",data1,data1);
 printf("---------------------\n");
 printf("%%f�榡 %f\n",f1);
 printf("%%e�榡 %e  %%E�榡 %E\n",f2,f2);
 printf("---------------------\n");
 printf("%%g�榡 %g  %%G�榡 %G\n",sum,sum);
 printf("%%p�榡 %p\n",str1);
 printf("123%n\n",&count);
 printf("conut��%d\n",count);
 /*  system("pause");  */
}
