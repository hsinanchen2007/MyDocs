/* ex3_07.c  overflow���m��   */
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 short int a=30000,b=30000;
 short int c;
 c=a+b;
 printf("%d\n",c);
 system("pause");
}
