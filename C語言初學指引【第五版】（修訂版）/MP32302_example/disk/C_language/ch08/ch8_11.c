/*    �ɦW:ch8_11.c    �\��:���Цr��P�r���r��   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char s2[]="Welcome";
 char *s3="Welcome";
 char *s4;
 char *s5="Good morning";;

 /*  s2=s5;  */    /*  ���椣�X�k */
 s3=s5;
 s4=s2;
 printf("s2=%s\n",s2);
 printf("s3=%s\n",s3);
 printf("s4=%s\n",s4);
 /*  system("pause");  */
}
