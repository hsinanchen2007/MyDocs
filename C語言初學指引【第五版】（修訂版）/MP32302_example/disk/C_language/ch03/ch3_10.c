/*    �ɦW:ch3_10.c    �\��:atoi�Batof�Batol���A�ഫ   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
   char *string;
   double d;
   int i;
   long l;

   string = "1234567";
   l = atol( string );
   printf("%s \t�ഫ��long=>%d\n",string,l);
   
   string = "12345jhchen";
   l = atol( string );
   printf("%s \t�ഫ��long=>%d\n",string,l);

   string = "1234567persons";
   i = atoi( string );
   printf("%s \t�ഫ��int=>%d\n",string,i);
   
   string = "-1234.56E-7";
   d = atof( string );
   printf("%s \t�ഫ��double=>%.9f\n",string,d);
   system("pause");
}
