/*    �ɦW:ch6_06.c    �\��:�G���}�C���m��  */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 float score[5][4] = { {85,78,65,0},
                       {75,85,69,0},
                       {63,67,95,0},
                       {94,92,88,0},
                       {74,65,73,0} };

 int i,j;
 
 printf("�p��\t�ƾ�\t�^��\t����\n");
 printf("==============================\n");
 for(i=0;i<5;i++)
 {
   score[i][3] = (score[i][0]+score[i][1]+score[i][2])/3;
   for(j=0;j<4;j++)
   {
       printf("%.2f\t",score[i][j]);
   }
   printf("\n");
 }
 /*  system("pause");  */
}
