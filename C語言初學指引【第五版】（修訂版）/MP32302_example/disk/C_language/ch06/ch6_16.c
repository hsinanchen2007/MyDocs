/*******************************
    �ɦW:ch6_16.c
    �\��:strtok()�m��-���Xtoken
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
 char string1[]="Word:Excel:PowerPointer:Access;C;Java;ASP:PHP";
 char delim1[]=":,;";  
 char *Token=(char *)malloc(sizeof(char)); /* ���Цr��,�᭱���`���� */
 printf("��l�r�ꬰ%s\n",string1);
 printf("�}�l����..........\n");
 printf("Tokens(�y��)�p�U:\n");
 
 Token = strtok(string1,delim1); /* �N�Ĥ@�ӥy���s�JToken */
 while(Token != NULL)            /* �ϥΰj����X�Ѿl�y�� */
 {
    printf("%s\n",Token);
    Token = strtok(NULL,delim1);
 }  
 /*  system("pause");  */
}
