/*    �ɦW:ch11_07.c    �\��:Ū�g�G�i����   */

#include <stdlib.h>
#include <stdio.h>

FILE *fp;

void main(int argc, char *argv[])
{

 char output[]="This is a binary file!";
 char input[100]={0};
 int num;

 /************�g�J�G�i���� ****************/
 if((fp = fopen("data3", "wb")) == NULL)
 {
   printf("�ɮ׿��~\n");
   exit(0);
  }

 num = fwrite(output,sizeof(char),sizeof(output),fp);
 printf("�G�i���ɼg�J����\n");
 fclose(fp);

 /************Ū���G�i���� ****************/
 
 if((fp = fopen("data3", "rb")) == NULL)
 {
   printf("�ɮ׿��~\n");
   exit(0);
 }
 num = fread(input,sizeof(char),23,fp);
 printf("�G�i����Ū������\n");
 printf("�G�i���ɤ��e�p�U\n");
 printf("%s\n",input);
 fclose(fp);
 /* system("pause"); */
}
