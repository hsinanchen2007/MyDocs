/*    �ɦW:ch5_14.c    �\��:for�j�骺�ܽd    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Sum,n,i;
 printf("�п�JN��:");
 scanf("%d",&n);
 for(Sum=0,i=1;i<=n;i=i+2)
     Sum=Sum+i;
 if((n%2)==1)
     printf("1+3+...+N=%d\n",Sum);
 else
     printf("1+3+...+N-1=%d\n",Sum);
 /*  system("pause");  */
}
