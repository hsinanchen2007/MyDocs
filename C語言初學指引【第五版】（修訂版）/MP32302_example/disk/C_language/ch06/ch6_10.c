/*    �ɦW:ch6_10.c    �\��:�зǿ�J�˸m     */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char fgets_string[100];
 char scanf_string[100];
 
 printf("�п�Jscanf�r��:");
 scanf("%s",&scanf_string);
 printf("�п�Jfgets�r��:");
 fgets(fgets_string,100,stdin);
 
 printf("�z��J��scanf�r��O%s\n",scanf_string);
 printf("�z��J��fgets�r��O%s",fgets_string);
 /*  system("pause");  */
}
