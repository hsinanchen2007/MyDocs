/*    �ɦW:ch11_01.c    �\��:�}�ɻP����    */

#include <stdlib.h>
#include <stdio.h>

FILE *fp1;

void main(void)
{
 char filename[80];
 
 printf("�п�J�ɦW(�i�t���|):");
 scanf("%s",filename);

 fp1 = fopen(filename, "r");
 if(fp1 != NULL)
 {
   printf("�ɮ�%s�}�Ҥ�...\n",filename);
 }
 else
 {
   printf("�ɮ�%s�}�ҥ���\n",filename);
   exit(1); /* �j�������{�� */
 }
 
 fclose(fp1);
 printf("�ɮ�%S����\n",filename);
 /* system("pause"); */
}
