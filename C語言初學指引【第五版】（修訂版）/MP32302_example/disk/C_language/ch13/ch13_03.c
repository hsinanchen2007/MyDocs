/*  �ɦW:ch13_03.c  �\��:C�y�����h��  */

#include <stdlib.h>
#include <stdio.h>

void action(int *k,void (*pf)(int *k));    /* pf�O�@�ب禡���� */
void inc(int *i);
void dec(int *i);

void inc(int *i)
{
 (*i)++;
}
void dec(int *i)
{
 (*i)--;
}

void action(int *k,void (*pf)(int *k))
{
 pf(k);       /* �Ъ`�N�o�@��,�ݦ��禡�I�s,����ڤW�i����椣�P���禡 */
}

void main(void)
{
 int a=100;

 printf("��ƶ}�l��%d\n",a);
 action(&a,inc);
 action(&a,inc);
 action(&a,dec);
 printf("��Ƴ̫ᬰ%d\n",a);
 /* system("pause"); */ 
}
