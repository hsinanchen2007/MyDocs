/*    檔名:ch13_01.c    功能:觀察各種資料在記憶體的配置   */

#include <stdlib.h>
#include <stdio.h>

int x;
int ar1[10];

void f1(int a)
{
  int b;
  static int y;
  static int ar2[10];

  printf("f1的參數a的位址  \t:%p\n",&a);
  printf("f1的區域變數b的位址\t:%p\n",&b);
  printf("f1靜態區域變數y位址\t:%p\n",&y);
  printf("f1的靜態陣列ar2位址\t:%p\n",&ar2);
}

void f2(int c)
{
  int d;
  int ar3[10];
  printf("f2的參數c的位址  \t:%p\n",&c);
  printf("f2的區域變數d的位址\t:%p\n",&d);
  printf("f2的一般陣列ar3的位址\t:%p\n",&ar3);
}

void main(void)
{
  int w;
  char* const s1="abc";
  char s2[]="abc";
  void (*pfunc)(int); 

  int *p=&x;
  
  printf("全域變數x的位址  \t:%p\n",p);
  printf("全域陣列ar1的位址\t:%p\n",&ar1);
  printf("一般區域變數w的位址\t:%p\n",&w);
  /* *(s1+1)='k'; */
  /* 上一行,編譯時合法,但執行會有執行階段的錯誤,原因在於您改了常數區的值 */ 
  printf("s1字串abc的起始位址\t:%p\n",s1);
  *(s2+1)='k';
  printf("s2字串abc的起始位址\t:%p\n",s2);  
  printf("指標變數pfunc的位址\t:%p\n",&pfunc);
  printf("指標變數p的位址\t\t:%p\n",&p);
  pfunc=f1;
  printf("函式f1的起始位址   \t:%p\n",pfunc);
  f1(3); 

  pfunc=f2;
  printf("函式f2的起始位址\t:%p\n",pfunc);
  f2(5);
  pfunc=main;
  printf("函式main的起始位址\t:%p\n",pfunc);
  /* system("pause"); */
}
