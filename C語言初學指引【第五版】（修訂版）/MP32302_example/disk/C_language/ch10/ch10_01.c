/*    �ɦW:ch10_01.c    �\��:typedef���A�w�q���m��    */

#include <stdio.h>
#include <stdlib.h>

typedef float score;

void main(void)
{
 score stu[3],total,avg;
 int i;

 total=0;
 for(i=1;i<=3;i++)
 {
   printf("�п�J��%d��P�Ǫ����Z:",i);
   scanf("%f",&stu[i-1]);
   total=total+stu[i-1];
 }
 avg=total/3;
 printf("�������Z=%.3f\n",avg);
 /* system("pause"); */
}
