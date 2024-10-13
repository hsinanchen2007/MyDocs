/*    郎:ch5_13.c    :falling throughボ絛    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int Score;
 printf("叫块璸阀Θ罿:");
 scanf("%d",&Score);
 if((Score>=0) && (Score<=100))
  switch(Score / 10)
  {
   case 10:
       printf("Чだ计\n");
   case 9:
       printf("だ计单纔单\n");
   case 8:
       printf("だ计单ヒ单\n");
   case 7:
       printf("だ计单单\n");
   case 6:
       printf("だ计单单\n");
   default:
       printf("だ计单单\n");
  }
 /*  system("pause");  */
}
