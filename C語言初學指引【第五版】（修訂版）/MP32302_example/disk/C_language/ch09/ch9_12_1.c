/*    �ɦW:ch9_12_1.c    �\��:�R�A�~�b�ܼƫŧi(�h�ɮץܽd)    */

#include <stdio.h>
#include <stdlib.h>

int i=10;
static int j=10;

extern void func1(void);

int main(void)
{
 extern int i;     /*  �i�ٲ�����  */
 extern int j;     /*  �i�ٲ�����  */
 func1();
 printf("ch9_12_1.c�ɪ�i=%d\n",i);
 printf("ch9_12_1.c�ɪ�j=%d\n",j);
 return 0;
 /*  system("pause");  */
}
