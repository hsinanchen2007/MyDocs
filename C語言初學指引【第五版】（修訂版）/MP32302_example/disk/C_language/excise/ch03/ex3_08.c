/* ex3_08.c  underflowªº½m²ß   */
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 float a=3.3E-38;
 float c=0;
 c=a*a;
 printf("%E\n",c);
 system("pause");
}
