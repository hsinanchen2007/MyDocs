/*    �ɦW:ch5_20.c    �\��:do-while�j�骺�ܽd    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 char InputChar;
 /* ...........�C���{�����g�B........... */
 printf("Game Over...\n");
 do
 {
     printf("Play Again?(y/n)");
     InputChar=getchar();
     getchar();
 }while((InputChar!='y') && (InputChar!='n'));
 /*  system("pause");  */
}
