/***************************
    �ɦW:ch3_05.c
    �\��:�޿�B��l
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int x=1,y=0;      /*  x���u,y����  */
 printf("1�N��u,0�N��\n");
 printf(" x=%d",x);
 printf(" y=%d\n",y);
 printf("--------------------\n");
 printf("not x    ==> %d\n",!x);
 printf("x and y  ==> %d\n",(x && y));
 printf("x or y   ==> %d\n",(x || y));
 printf("x nand y ==> %d\n",!(x && y));
 printf("x nor y  ==> %d\n",!(x || y));
 system("pause");
}
