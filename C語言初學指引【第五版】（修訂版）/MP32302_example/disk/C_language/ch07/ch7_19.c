/*    �ɦW:ch7_19.c    �\��:�`�Ƿj�M�k    */

#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int Target,int *arr,int arr_index)
{
 int i;
 
 for(i=0;i<arr_index;i++)
    if(Target == arr[i])       /* ���F */
       return i;
 return -1;                  /* �����䤣�� */
}

void main(void)
{
 int work[11]={43,23,67,27,39,15,39,37,57,26,14};
 int FindNumber,location;
 
 printf("�п�J�z�n�䪺�ƭ�:");
 scanf("%d",&FindNumber);
 location=SeqSearch(FindNumber,work,11);
 if(location==-1)
    printf("�b�}�C���䤣��n�䪺�ƭ�\n");
 else
    printf("�ƭ�%d���work[%d]\n",FindNumber,location);
 /*  system("pause");  */
}
