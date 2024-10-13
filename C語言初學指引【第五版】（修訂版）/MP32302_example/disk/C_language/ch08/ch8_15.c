/*    檔名:ch8_15.c    功能:傳遞二維陣列    */

#include <stdio.h>
#include <stdlib.h>

print99(int *n,int p,int q)
{
 int i,j;
 for(i=1;i<=p;i++)
 {
   for(j=1;j<=q;j++)
   {
     printf("%d*%d=%d\t",i,j,*(n+(i-1)*q+(j-1)));
   }
   printf("\n");
 }     
}

void main(void)
{
 int m[9][9];
 int i,j;
  
 for(i=1;i<=9;i++)
   for(j=1;j<=9;j++)
     m[i-1][j-1]=i*j;
 
 print99(m,9,9);
 /*  system("pause");  */
}
