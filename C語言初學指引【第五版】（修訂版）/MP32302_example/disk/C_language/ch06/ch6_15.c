/*******************************************
    �ɦW:ch6_15.c
    �\��:strcmp()�Pstrncmp()�m��-����r��
 *******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
 char s1[]="output";
 char s2[]="outside";
 char s3[]="output";
 char s4[]="outlook";
  
 printf("%s�P%s\t��������G==>%d\n",s1,s1,strcmp(s1,s1));
 printf("%s�P%s\t��������G==>%d\n",s1,s2,strcmp(s1,s2));
 printf("%s�P%s\t��������G==>%d\n",s1,s3,strcmp(s1,s3));
 printf("%s�P%s\t��������G==>%d\n",s1,s4,strcmp(s1,s4));
 printf("%s�P%s\t���e3�Ӧr��������G==>%d\n",s1,s2,strncmp(s1,s2,3));
 /*  system("pause");  */
}
