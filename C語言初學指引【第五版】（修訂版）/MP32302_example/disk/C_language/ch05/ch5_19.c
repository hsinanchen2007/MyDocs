/*    �ɦW:ch5_19.c    �\��:while�j�骺�ܽd    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int x,y,gcd,temp;
 printf("��Jx:");  scanf("%d",&x);
 printf("��Jy:");  scanf("%d",&y);
 printf("(%d,%d)=",x,y);
 if (x<y)          /* �N���j���ƭȩ�bx,���p����by */
 {
     temp = x;   x = y;   y = temp;    /* x,y�ƭȹ�� */
 }
 while(x!=0)
 {
     x=x%y;
     if(x!=0)
     {
         temp = x;   x = y;   y = temp;    /* x,y�ƭȹ�� */
     }
 }
 gcd=y;
 printf("%d\n",gcd);
 /*  system("pause");  */
}
