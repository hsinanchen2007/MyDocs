/*    �ɦW:ch7_12.c    �\��:����6��1~49���H���ü�   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
 int lotto[6];
 int i;
 srand((unsigned) time(NULL));
 for (i=1;i<=6;i++)
 {
    lotto[i-1]=rand()%49+1;
    printf("��%d�Ӹ��X��%d\n",i,lotto[i-1]);
 }
 /*  system("pause");  */
}
