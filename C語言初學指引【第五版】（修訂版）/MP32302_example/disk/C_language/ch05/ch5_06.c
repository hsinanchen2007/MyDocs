/*    �ɦW:ch5_06.c    �\��:?����B��l���m��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Ans=38; /* ���׬�38 */
 int Guess;
 printf("�вq�@��1~99�����X:");
 scanf("%d",&Guess);
 if(Guess==Ans)
     printf("���߱z�q��F.\n");
 else
     (Guess>Ans) ? printf("�z�q�o�Ӥj�F\n") : printf("�z�q�o�Ӥp�F\n");
 /*  system("pause");  */
}
