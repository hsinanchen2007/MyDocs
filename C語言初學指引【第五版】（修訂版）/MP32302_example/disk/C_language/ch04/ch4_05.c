/*    �ɦW:ch4_05.c    �\��:printf()[.prec]�Ѽ�      */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int data1=1234;
 float data2 = 45.6789;
 double data3 = 78.900000;
 char *str1="Hello!";
 
 printf("   %%d�榡==>%d\n",data1);
 printf("   %%f�榡==>%f\n",data2);
 printf("   %%g�榡==>%g\n",data3);
 printf("   %%s�榡==>%s\n",str1);
 printf("==================================\n");
 printf("        ==>1234567890123456789\n");  /*�����Ƥ���*/
 printf("           -------------------\n");
 printf("%%.0d�榡==>%.0d\n",data1);
 printf("%%.0f�榡==>%.0f\n",data2);
 printf("==================================\n");
 printf("        ==>1234567890123456789\n");  /*�����Ƥ���*/
 printf("           -------------------\n");
 printf("%%.3s�榡==>%.3s\n",str1);
 printf("%%.1f�榡==>%.1f\n",data2);
 printf("%%.5f�榡==>%.5f\n",data2);
 printf("%%.1g�榡==>%.1g\n",data3);
 printf("%%.5g�榡==>%.5g\n",data3);
 printf("==================================\n");
 printf("        ==>1234567890123456789\n");  /*�����Ƥ���*/
 printf("           -------------------\n");
 printf("%%.*f�榡==>%.*f\n",3,data2);
 /*  system("pause");  */
}
