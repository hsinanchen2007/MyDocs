/*    �ɦW:ch5_18.c    �\��:break�ԭz���ܽd   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 short int Sum,n,i;
 printf("�D1~N���`�M,�п�JN��:");
 scanf("%d",&n);
 Sum=0;
 for(i=1;i<=n;i++)
 {
    if(Sum>30000)
        break;
    Sum=Sum+i;
 }
 printf("1~%d���`�M��%d\n",i-1,Sum);
 /*  system("pause");  */
}
