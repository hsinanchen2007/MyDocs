/*    �ɦW:ch4_04.c    �\��:printf()[width]�Ѽ�    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int data1=1234;
 float data2 = 45.67;
 
 printf("        ==>123456789\n");               //�����Ƥ���
 printf("           ---------\n");
 printf(" %%3d�榡==>%3d\n",data1);
 printf(" %%6d�榡==>%6d\n",data1);
 printf("%%03d�榡==>%03d\n",data1);
 printf("%%06d�榡==>%06d\n",data1);
 printf(" %%*d�榡==>%*d\n",5,data1);
 printf("==================================\n");
 printf("         ==>1234567890123456789\n");    //�����Ƥ���
 printf("            -------------------\n");
 printf(" %%15f�榡==>%15f\n",data2);
 printf("%%015f�榡==>%015f\n",data2);
 printf("  %%*f�榡==>%*f\n",12,data2);
 /*  system("pause");  */
}
