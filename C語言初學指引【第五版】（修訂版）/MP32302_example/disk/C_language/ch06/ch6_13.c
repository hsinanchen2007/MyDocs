/***************************************************
    �ɦW:ch6_13.c
    �\��:strcpy(),strncpy()�m��-�ƻs�r��γ����r��
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
 char src_string[]="�{���]�pC�y��";
 char dest_string[60],dest_substring[60];
  
 strcpy(dest_string,src_string);
 strncpy(dest_substring,src_string,8);
  
 printf("�ƻs������r�ꬰ:%s\n",dest_string);
 printf("�ƻs�������r�ꬰ:%s\n",dest_substring);
 /*  system("pause");  */
}
