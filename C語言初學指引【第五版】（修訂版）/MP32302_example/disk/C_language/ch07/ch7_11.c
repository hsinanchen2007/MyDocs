/*    �ɦW:ch7_11.c    �\��:srand�Prand�禡�m��   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
 int i;
 srand((unsigned) time(NULL));
 for (i=1;i<=6;i++)
 {
   printf("��%d���H���üƬ�%d\n",i,rand());
 }
 /*  system("pause");  */
}
