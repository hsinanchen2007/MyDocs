/*    檔名:ch6_05.c    功能:二維陣列的練習    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int m[9][9];  /* 宣告二維陣列m[9][9]，共有81個元素，從m[0][0]~m[8][8] */
 int i,j;
 
 for(i=1;i<=9;i++)
   for(j=1;j<=9;j++)
      m[i-1][j-1]=i*j;         /* 將九九乘法的結果存入二維陣列中 */
 
 for(i=1;i<=9;i++)
 {
   for(j=1;j<=9;j++)
   {
      printf("%d*%d=%d\t",i,j,m[i-1][j-1]);        /* 見說明 */
   }
   printf("\n");
 }     
 /*  system("pause");  */
}
