/*    �ɦW:ch5_09.c    �\��:else-if�榡���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 unsigned int Score;
 printf("�п�J�p�����Z:");
 scanf("%d",&Score);
 if(Score<60) { printf("���Ƶ��Ŭ��B��\n"); }
 else if(Score<=69) { printf("���Ƶ��Ŭ�����\n"); }
 else if(Score<=79) { printf("���Ƶ��Ŭ��A��\n"); }
 else if(Score<=89) { printf("���Ƶ��Ŭ��ҵ�\n"); }
 else if(Score<=99) { printf("���Ƶ��Ŭ��u��\n"); }
 else if(Score==100) { printf("��������\n"); }
 else { printf("�z��J�F���X�k������\n"); }
 /*  system("pause");  */
}
