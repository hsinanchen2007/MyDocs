/*    �ɦW:ch7_05.c    �\��:�L�ǤJ�޼ƤΦ^�ǭȪ��禡    */

#include <stdio.h>
#include <stdlib.h>

void print99(void); /* �禡�ŧi */
void print99(void)  /* �禡�w�q */
{
 int i,j;
 for(i=1;i<=9;i++)
 {
   for(j=1;j<=9;j++)
      printf("%d*%d=%d\t",i,j,i*j);
   printf("\n");
 }
}

void main(void)
{
 printf("�H�U�O�`�����E�E���k��\n");
 print99();         /* �禡�I�s */
 /*  system("pause");  */
}
