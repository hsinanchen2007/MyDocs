/*    �ɦW:ch5_08.c    �\��:����B�⦡���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 long Credit;    /*  �H���B�� */
 int Status;     /*  ú�ڪ��A */
 float Year;     /*  ���d�~�� */
 printf("�п�J�H���B��:");
 scanf("%d",&Credit);
 printf("ú�ڬO�_���`(1:���`,0:�����`):");
 scanf("%d",&Status);
 if(!(Status))
 {
      printf("�w�ɲ{�����B��0��\n");
 }
 else
 {
      printf("�п�J���d�~��:");
      scanf("%f",&Year);
 }
 if((Status) && (Year>=0.5) && (Year<1))
      printf("�w�ɲ{�����B��%.0f��\n",(float)Credit*0.05);
 if((Status) && (Year>=1))
      printf("�w�ɲ{�����B��%.0f��\n",(float)Credit*0.1);
 if((Status) && (Year<0.5))
      printf("�w�ɲ{�����B��0��\n");
 /*  system("pause");  */
}
