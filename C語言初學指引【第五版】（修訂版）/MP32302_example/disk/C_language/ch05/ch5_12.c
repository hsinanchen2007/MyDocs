/*    �ɦW:ch5_12.c    �\��:switch-case���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Score;
 printf("�п�J�p�����Z:");
 scanf("%d",&Score);
 if((Score>=0) && (Score<=100))
  switch(Score / 10)
  {
   case 10:
       printf("��������\n");
       break;
   case 9:
       printf("���Ƶ��Ŭ��u��\n");
       break;
   case 8:
       printf("���Ƶ��Ŭ��ҵ�\n");
       break;
   case 7:
       printf("���Ƶ��Ŭ��A��\n");
       break;
   case 6:
       printf("���Ƶ��Ŭ�����\n");
       break;
   default:
       printf("���Ƶ��Ŭ��B��\n");
       break;
  }
 /*  system("pause");  */
}
