/*    �ɦW:ch6_08.c    �\��:�r��ϦV    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char string1[60],string2[60];
 int i,len;
 
 printf("�п�J�r��:");
 scanf("%s",&string1);
 
 len=0;
 while(string1[len]!='\0')
 {
    len++;
 }
 for(i=0;i<len;i++)
 {
    string2[i]=string1[len-1-i];
 }
 string2[i]='\0';
  
 printf("�ϦV�r�ꬰ:%s\n",string2);
 /*  system("pause");  */
}
