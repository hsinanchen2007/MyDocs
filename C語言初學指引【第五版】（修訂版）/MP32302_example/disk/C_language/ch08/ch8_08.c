/*    �ɦW:ch8_08.c    �\��:�ϥΫ��Цs���}�C����    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 float Temper[12],sum=0,average;
 int i;

 for(i=0;i<12;i++)
 {
    printf("%d�몺�����ū�:",i+1);
    scanf("%f",(Temper+i));
    sum=sum+*(Temper+i);
 }
 average=sum/12;
 printf("=========================\n");
 printf("�~�ץ����ū�:%f\n",average);
 /*  system("pause");  */
}

