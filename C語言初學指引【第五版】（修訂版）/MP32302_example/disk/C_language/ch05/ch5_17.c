/*    �ɦW:ch5_17.c    �\��:continue�ԭz���ܽd   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Sum=0,i,j;
 for(i=1;i<=10;i++)
 {
    if ((i%2)==1)
        continue;
    Sum=Sum+i;
 }
 printf("2+4+6+8+10=%d\n",Sum);
 /*  system("pause");  */
}
