/*    �ɦW:ch5_13.c    �\��:falling through���ܽd    */

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
   case 9:
       printf("���Ƶ��Ŭ��u��\n");
   case 8:
       printf("���Ƶ��Ŭ��ҵ�\n");
   case 7:
       printf("���Ƶ��Ŭ��A��\n");
   case 6:
       printf("���Ƶ��Ŭ�����\n");
   default:
       printf("���Ƶ��Ŭ��B��\n");
  }
 /*  system("pause");  */
}
