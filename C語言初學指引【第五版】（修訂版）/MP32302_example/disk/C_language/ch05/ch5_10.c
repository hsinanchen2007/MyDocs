/*    檔名:ch5_10.c    功能:浮點數比較的陷阱    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 float k,tk=40.5;

 printf("一台斤=0.6公斤\n");
 printf("請問%.2f台斤等於幾公斤:",tk);
 scanf("%f",&k);
 if(k==tk*0.6)
   printf("答對了!\n"); 
 else
   printf("答錯了!\n"); system("pause");
 /*  system("pause");  */
}
