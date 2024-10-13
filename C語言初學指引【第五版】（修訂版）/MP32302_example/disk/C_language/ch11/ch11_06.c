/*    �ɦW:ch11_06.c    �\��:�ƻs�ɮ�(�i�ƻs�G�i����)   */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *fp1, *fp2;

void main(int argc, char *argv[])
{
  
 char src_filename[128];  /*  �ӷ��ɮ�  */
 char dest_filename[128]; /*  �ت��ɮ�  */

 int ch;
 
 if(argc <= 2) /*  ���ܨϥΪ̿�J�ӷ��ɦW�P�ت��ɦW  */
 {
     printf("�п�J�ӷ��ɦW�P�ت��ɦW\n");
     exit(0);
 }
 else
 {
     strcpy(src_filename,argv[1]);
     strcpy(dest_filename,argv[2]);
 }
    
 if((fp1 = fopen(src_filename, "rb")) == NULL)  
 {
     printf("�}�Ҩӷ���%s���~\n",src_filename);
     exit(0);
 }
 
 if((fp2 = fopen(dest_filename, "wb")) == NULL) 
 {
     printf("�L�k�إߥت���%s\n",dest_filename);
     exit(0);
 }
    
 while((ch = fgetc(fp1)) != EOF)  /*  ��Ū��EOF��,����ɮ׵���  */
 {
     fputc(ch,fp2);
 }
  
 fclose(fp1);
 fclose(fp2);
 /* system("pause"); */
}
