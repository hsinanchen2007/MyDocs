/*    �ɦW:ch9_10.c    �\��:�~�b�ܼƫŧi(��@�ɮץܽd)   */

#include <stdio.h>
#include <stdlib.h>

int i;

void func1(void)
{
 extern int i;      /* �i�ٲ����� */
 i++;	
}

void main(void)
{
 extern int i;     /* �i�ٲ����� */
 printf("i=%d\n",i);
 func1();
 printf("i=%d\n",i);
  /*  system("pause");  */
}
