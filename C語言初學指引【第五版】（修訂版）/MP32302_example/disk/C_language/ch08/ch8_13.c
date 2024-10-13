/*    �ɦW:ch8_13.c    �\��:�^�Ǧr�����(�]�p����r��禡)    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverse(char *src);

char *inverse(char *src)
{
 char *dest=(char*)malloc(sizeof(src));   /* malloc�Ԩ�8.7�` */
 int i,len;
 len=strlen(src);
 for(i=len-1;i>=0;i--)
    *(dest+len-1-i)=*(src+i);
 *(dest+len)='\0';
 return dest;
}
void main(void)
{
 char *s1="Welcome";
 char *s2=inverse(s1); /* �i���Ѭ� char *s2; s2=inverse(s1); */
 
 printf("s1=%s\n",s1);
 printf("s2=%s\n",s2);
 /*  system("pause");  */
}
