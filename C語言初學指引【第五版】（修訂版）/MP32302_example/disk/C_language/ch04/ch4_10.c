/*    �ɦW:ch4_10.c    �\��:scanf()�榡�ƲŸ�     */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char ch1;
 int data1;
 float f1;
 char *str1=(char *)malloc(sizeof(char));   //malloc�аѾ\8.7�`
 printf("�п�J�r��,�r��,���,�B�I��(�ϥ�Enter�[�H���j)\n");
 scanf("%c%s%d%f",&ch1,str1,&data1,&f1);
 
 printf("======���b��X=======\n");
 printf("ch1=%c\n",ch1);
 printf("str1=%s\n",str1);
 printf("data1=%d\n",data1);
 printf("f1=%f\n",f1);
 /*  system("pause");  */
}
