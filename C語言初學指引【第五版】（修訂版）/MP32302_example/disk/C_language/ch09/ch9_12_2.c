/*    �ɦW:ch9_12_2.c    �\��:�R�A�~�b�ܼƫŧi(�h�ɮץܽd)     */

#include <stdio.h>
#include <stdlib.h>

extern int i;
int j; /* extern int j; */

void func1(void)
{
 j=100;
 printf("ch9_12_2.c�ɪ�i=%d\n",i);
 printf("ch9_12_2.c�ɪ�j=%d\n",j);
}
