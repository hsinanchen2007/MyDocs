/*    �ɦW:ch5_14.c    �\��:for�j�骺�ܽd   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Sum,n,i;
 printf("�п�JN��:");
 scanf("%d",&n);
 Sum=0;
 for(i=1;(n%2)?(i<=n):(i<=n-1);i++)
    if((i%2)==1)
         Sum=Sum+i;
 if((n%2)==1)
    printf("1+3+...+N=%d\n",Sum);
 else
    printf("1+3+...+N-1=%d\n",Sum);
 /*  system("pause");  */
}
