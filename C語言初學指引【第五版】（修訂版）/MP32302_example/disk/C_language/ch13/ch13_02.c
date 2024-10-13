/*    檔名:ch13_02.c    功能:透過函式指標執行不同的函式   */

#include <stdlib.h>
#include <stdio.h>

int add(int a,int b)
{
    return a+b;
}

int mul(int a,int b)
{
    return a*b;
}

void main(void)
{
  int result1,result2;
  typedef int (*funcT)(int,int); /* 定義funcT為函式指標型態的別名 */
  funcT pfunc;               /* 利用別名，宣告pfunc函式指標 */
  pfunc=add;                 /* pfunc指向add函式起始位址 */
  result1=pfunc(3,5);/*說明1 */ /*可替換為result1=(*pfunc)(3,5);*/
  printf("result1=%d\n",result1);
  pfunc=mul;                 /* pfunc指向mul函式起始位址 */
  result2=(*pfunc)(3,5);/*見說明2 */ /*可替換為result2=pfunc(3,5);*/
  printf("result2=%d\n",result2);
  /* system("pause"); */ 
}
