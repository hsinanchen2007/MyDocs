/*    �ɦW:ch6_05.c    �\��:�G���}�C���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int m[9][9];  /* �ŧi�G���}�Cm[9][9]�A�@��81�Ӥ����A�qm[0][0]~m[8][8] */
 int i,j;
 
 for(i=1;i<=9;i++)
   for(j=1;j<=9;j++)
      m[i-1][j-1]=i*j;         /* �N�E�E���k�����G�s�J�G���}�C�� */
 
 for(i=1;i<=9;i++)
 {
   for(j=1;j<=9;j++)
   {
      printf("%d*%d=%d\t",i,j,m[i-1][j-1]);        /* ������ */
   }
   printf("\n");
 }     
 /*  system("pause");  */
}
