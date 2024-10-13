/*  檔名:ch13_03.c  功能:C語言的多型  */

#include <stdlib.h>
#include <stdio.h>

void action(int *k,void (*pf)(int *k));    /* pf是一種函式指標 */
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
 pf(k);       /* 請注意這一行,看似函式呼叫,但實際上可能執行不同的函式 */
}

void main(void)
{
 int a=100;

 printf("資料開始為%d\n",a);
 action(&a,inc);
 action(&a,inc);
 action(&a,dec);
 printf("資料最後為%d\n",a);
 /* system("pause"); */ 
}
