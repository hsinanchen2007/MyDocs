/*    �ɦW:ch9_05.c    �\��:auto�ܼ�    */

#include <stdio.h>
#include <stdlib.h>

void func1(void)
{
 auto int var2=30;
 printf("�Ϭq�~var2 = %d\n",var2);
 /* printf("�Ϭq�~var3 = %d\n",var3); */
 {
    auto int var3 = 40;
    printf("�Ϭq��var3 = %d\n",var3);
    printf("�Ϭq��var2 = %d\n",var2);
 }
 /* printf("�Ϭq�~var3 = %d\n",var3); */
}

void main(void)
{
 auto int var1 = 10;
 printf("�Ϭq�~var1 = %d\n",var1);
 {
    auto int var1 = 20;
    printf("�Ϭq��var1 = %d\n",var1);
 }
 func1();
 /*  system("pause");  */
}
