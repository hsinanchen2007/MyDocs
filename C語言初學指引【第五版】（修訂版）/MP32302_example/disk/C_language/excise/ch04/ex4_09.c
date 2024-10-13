/*    檔名:ex4_09.c    功能:輸入兩個字元     */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char a,b,c;
 printf("請輸入一個字元:",a);
 scanf("%c",a);
 printf("請再輸入一個字元:",b);
 scanf("%c",b);
 printf("您輸入的兩個字元分別為%c,%c\n",a,b);
 system("pause");
}
