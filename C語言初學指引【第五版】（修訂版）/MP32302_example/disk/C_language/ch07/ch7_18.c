/*    �ɦW:ch7_18.c    �\��:�ǫ��ЩI�s�ǻ��޼�    */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_lotto(int *arr,int arr_index)
{
 int i;
 srand((unsigned) time(NULL));
 printf("�ֳz���X�}����.....\n");
 for (i=0;i<arr_index;i++)
 {
  arr[i]=rand()%49+1;
  printf("��%d�Ӹ��X��%d\n",i+1,arr[i]);
 }
}

void main(void)
{
 int lotto[6],i;
 generate_lotto(lotto,6);
 printf("�ֳz���X�p�U.....\n");
 for (i=0;i<6;i++)
  printf("%d\t",lotto[i]);
 printf("\n");
 /*  system("pause");  */
}
