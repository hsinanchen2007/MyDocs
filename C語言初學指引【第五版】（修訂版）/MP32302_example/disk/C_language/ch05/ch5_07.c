/*    �ɦW:ch5_07.c    �\��:�_����ܪ��m��      */

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
 if(Status)
 {
     printf("�п�J���d�~��:");
     scanf("%f",&Year);
     if(Year>=0.5)
     {
          if(Year<1)
          {
               printf("�w�ɲ{�����B��%.0f��\n",(float)Credit*0.05);
          }
          else
          {
               printf("�w�ɲ{�����B��%.0f��\n",(float)Credit*0.1);
          }
     }
     else
     {
          printf("�w�ɲ{�����B��0��\n");
     }
 }
 else
 {
     printf("�w�ɲ{�����B��0��\n");
 }
 /*  system("pause");  */
}
