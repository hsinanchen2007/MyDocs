/* ex3_05.c   �e�m��m�B��l */ 
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 int a=3,b=4,c=5;
 a+=b*++c;
 printf("a=%d\n",a);
 printf("b=%d\n",b);
 printf("c=%d\n",c);
 system("pause");
}
