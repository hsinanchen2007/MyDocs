/*    �ɦW:ch8_01.c    �\��:���}�B��l�P���йB��l    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int a=50,b;
 int *ptr;
 
 printf("a=%d\n",a);
 ptr=&a;          /*  �Nptr���Va  */
 printf("*ptr=%d\n",*ptr);
 b=*ptr;          /*  �Na����(ptr���V����)�]�w��b  */
 printf("b=%d\n",b);
 /*  system("pause");  */
}
