/*    �ɦW:ch3_08.c    �\��:sizeof�B��l */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int a=10,b=10;
 int w,x,y,z;
 
 w=sizeof a++;
 x=sizeof(a+b);
 y=sizeof("Hello!");
 z=sizeof(double);
 
 printf("w = %d\n",w);
 printf("x = %d\n",x);
 printf("y = %d\n",y);
 printf("z = %d\n",z);
 system("pause");
}
