/*    �ɦW:ch6_09.c    �\��:fgets()�禡�m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char fgets_string[100];
 char scanf_string[100];
 
 printf("�п�Jfgets�r��:");
 fgets(fgets_string,100,stdin);
 printf("�п�Jscanf�r��:");
 scanf("%s",&scanf_string);
 
 printf("�z��J��fgets�r��O%s",fgets_string);
 printf("�z��J��scanf�r��O%s\n",scanf_string);
 /*  system("pause");  */
}
