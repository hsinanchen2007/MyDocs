/*    �ɦW:ch5_21.c    �\��:goto�ԭz���ܽd    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Sum,FactNum,x,y,m;
 printf("�p��1!+2!+...+m!,(0<m<10)\n");
 printf("�п�Jm:");
 scanf("%d",&m);
 
 for(Sum=0,x=1;x<10;x++)
 {
    for(FactNum=1,y=1;y<=x;y++)
    {
    	FactNum=FactNum*y;
    	if(y==m+1)
    	    goto ProgEnd;
    }
    Sum=Sum+FactNum;
  }
ProgEnd:  printf("1!+2!+...+m!=%d(m=%d)\n",Sum,m);
 /*  system("pause");  */
}
