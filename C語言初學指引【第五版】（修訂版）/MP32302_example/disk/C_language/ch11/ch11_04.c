/*    �ɦW:ch11_04.c    �\��:�ƻs�ɮ�(�ϥ�fscanf�Pfprintf)   */

#include <stdlib.h>
#include <stdio.h>

FILE *fp1,*fp2;

void main(void)
{
 char filename1[80],filename2[80];
 char tempstr[32];
 
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
 
 while((fscanf(fp1,"%s",tempstr))!=EOF)  /* �ϥΰj��Ū���ӷ��ɤ��e */
 {
      /*  printf("%s\n",tempstr); */
      fprintf(fp2,"%s\n",tempstr); /* �ϥΰj��g�J�ت��ɤ��e */
 }
 printf("Ū���üg�J����......\n");
 
 fclose(fp1);
 fclose(fp2);
 /* system("pause"); */
}
