/*    �ɦW:ch10_02.c    �\��:�C�|��ƫ��A   */

#include <stdio.h>
#include <stdlib.h>

enum manufacturer {IBM,MAXTOR,WD,SEAGATE};

void main(void)
{
 enum manufacturer HardDisk;
 
 HardDisk=SEAGATE;
 
 switch(HardDisk)
 {
  case 0:
   printf("�w�мt�P�OIBM\n");      break;
  case 1:
   printf("�w�мt�P�OMAXTOR\n");   break;
  case 2:
   printf("�w�мt�P�OWD\n");       break;
  case 3:
   printf("�w�мt�P�OSEAGATE\n");  break;
 } 
 /* system("pause"); */
}
