#include <stdio.h>

void main(void)
{
 char *str1="Hello C�y��";
 char str2[100]="";
 char *str3=mystrcpy(str2,str1);
 printf("str1��:%s\n",str1);
 printf("str2��:%s\n",str2);
 printf("str3��:%s\n",str3);
}