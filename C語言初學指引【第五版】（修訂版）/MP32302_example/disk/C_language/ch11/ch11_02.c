/*    �ɦW:ch11_02.c    �\��:�ƻs�ɮ�(�ϥ�fgetc�Pfputc)  */

#include <stdlib.h>
#include <stdio.h>

FILE *fp1,*fp2;

void main(void)
{
 char filename1[80],filename2[80];
 char c;
 
 printf("�п�J�ӷ��ɦW:");
 scanf("%s",filename1);
 printf("�п�J�ت��ɦW:");
 scanf("%s",filename2);
 
 fp1 = fopen(filename1, "r");
 fp2 = fopen(filename2, "w");
 
 if((fp1 == NULL) || (fp2 == NULL))
 {
  printf("�ɮ׵o�Ϳ��~\n");
  exit(1);   /* �j�������{�� */
 }
 
 printf("Ū���üg�J��......\n");
 
 while((c=fgetc(fp1))!=EOF)    /*  �ϥΰj��Ū���ӷ��ɤ��e  */
 {
     printf("%c",c);
     fputc(c,fp2); /*  �ϥΰj��g�J�ت��ɤ��e  */
 }
 printf("\nŪ���üg�J����......\n");
 
 fclose(fp1);
 fclose(fp2);
 /* system("pause"); */
}
