/*    檔名:ch8_13.c    功能:回傳字串指標(設計反轉字串函式)    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverse(char *src);

char *inverse(char *src)
{
 char *dest=(char*)malloc(sizeof(src));   /* malloc詳見8.7節 */
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
 char *s2=inverse(s1); /* 可分解為 char *s2; s2=inverse(s1); */
 
 printf("s1=%s\n",s1);
 printf("s2=%s\n",s2);
 /*  system("pause");  */
}
