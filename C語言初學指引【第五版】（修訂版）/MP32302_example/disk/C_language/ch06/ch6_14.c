/****************************************
    �ɦW:ch6_14.c
    �\��:strcpy(),strcat( )�m��-�զX�r��
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
 char string1[20],string2[20]="�ѥ��������q",string3[20];
 char dest_string[60];
  
 printf("�п�Jstring1�r��:");
 scanf("%s",&string1);
 printf("�п�Jstring3�r��:");
 scanf("%s",&string3);
 
 strcpy(dest_string,string1);
 strcat(dest_string,string2);
 strcat(dest_string,string3);
  
 printf("dest_string:%s\n",dest_string);
 /*  system("pause");  */
}
