/*******************************
    �ɦW:pro7_1.c
    �\��:�~�b�ܼƫŧi(�h�ɮץܽd)
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int i;
extern void func1(void);

int main(void)
{
 extern int i;     /*  �i�ٲ����� */
 printf("i=%d\n",i);
 func1();
 printf("i=%d\n",i);
 return 0;
 system("pause");/*  system("pause");  */
}
