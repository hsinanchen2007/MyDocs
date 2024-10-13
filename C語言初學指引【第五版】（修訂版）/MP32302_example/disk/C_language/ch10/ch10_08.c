/*    檔名:ch10_08.c    功能:union結構體    */

#include <stdio.h>
#include <stdlib.h>

union u_member
{
 short int id;
 int income;
};

struct s_member
{
 short int id;
 int income;
};

void main(void)
{
 union u_member John;
 struct s_member Mary;
 
 John.income  = 0x00000000;
 John.income  = 0x66666666;
 John.id      = 0x0010;
 
 Mary.income  = 0x00000000;
 Mary.income  = 0x55555555;
 Mary.id      = 0x0011;
 
 printf("John.income  =%X\n",John.income);
 printf("John.id      =%X\n",John.id);
 printf("Mary.phone   =%X\n",Mary.income);
 printf("Mary.id      =%X\n",Mary.id);
 /* system("pause"); */
}
