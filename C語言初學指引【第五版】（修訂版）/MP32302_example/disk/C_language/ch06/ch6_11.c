/*    �ɦW:ch6_11.c    �\��:puts()�禡�m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char string1[100],string2[100];

 printf("�п�Jstring1�r��:");
 fgets(string1,100,stdin);
 printf("�п�Jstring2�r��:");
 scanf("%s",&string2);
 
 printf("string1�r��O");
 puts(string1);
 printf("string2�r��O");
 puts(string2);
 /*  system("pause");  */
}
