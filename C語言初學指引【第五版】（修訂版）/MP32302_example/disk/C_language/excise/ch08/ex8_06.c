#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void)
{
 int *A,*B,*C;
 int i,j,m,n;
 
 printf("�п�J�x�}�j�p\n");
 printf("�п�J�C��:");
 scanf("%d",&m);
 printf("�п�J���:");
 scanf("%d",&n);
 
 /*************�[�J�{���X,�H��JA,B�����ç���C=A+B****************/
 
 for(i=0;i<m;i++)
 {
   for(j=0;j<n;j++)
   {
     printf("C[%d,%d]=%2d    ",i+1,j+1,C[i*n+j]);
   }
   printf("\n");
 }
 free(A);
 free(B);
 free(C);
}