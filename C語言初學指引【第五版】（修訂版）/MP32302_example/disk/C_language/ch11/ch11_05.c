/*    �ɦW:ch11_05.c    �\��:�����ɮ׫���(�ϥ�fseek)   */

#include <stdlib.h>
#include <stdio.h>

FILE *fp1;

void main(void)
{
 char filename1[80];
 char tempstr[32];
 
 printf("�п�J�ɦW:");
 scanf("%s",filename1);
  
 fp1 = fopen(filename1, "r");
  
 if(fp1 == NULL)
 {
    printf("�ɮ׵o�Ϳ��~\n");
    exit(1);   /* �j�������{�� */
 }
 
 if(fseek(fp1,-17L,SEEK_END) == 0)
 {
    fscanf(fp1,"%s",tempstr);
    printf("�ɧ��˼�17�Ӧr���B��token�O%s\n",tempstr);
 }
 else
 {
    printf("fseek���Ϳ��~\n");
 }
  
 fclose(fp1);
 /* system("pause"); */
}
