/*    郎:ch5_12.c    :switch-case絤策    */

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
       break;
   case 9:
       printf("だ计单纔单\n");
       break;
   case 8:
       printf("だ计单ヒ单\n");
       break;
   case 7:
       printf("だ计单单\n");
       break;
   case 6:
       printf("だ计单单\n");
       break;
   default:
       printf("だ计单单\n");
       break;
  }
 /*  system("pause");  */
}
