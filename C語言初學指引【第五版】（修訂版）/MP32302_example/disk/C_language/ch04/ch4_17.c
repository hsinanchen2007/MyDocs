/*    �ɦW:ch4_17.c    �\��:fgets�禡     */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char str1[]="";
 char *str2="�z�ҿ�J���r��p�W";

 printf("�п�J�@�Ӧr��:");
 fgets(str1,80,stdin);      /*�ϥ�fgets���Ngets*/
 printf("%s",str1);
 printf("%s",str2);
 /*  system("pause");  */
}
