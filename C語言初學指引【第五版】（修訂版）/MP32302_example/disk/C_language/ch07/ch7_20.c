/*    �ɦW:ch7_20.c    �\��:�G���j�M�k   */

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int Target,int *arr,int arr_index)
{
 int Low,Upper,m;
 
 Low=0;
 Upper=arr_index-1;
 while (Low<=Upper)
 {
    m=(Low+Upper)/2;     /* �p�⤤����m */
    if(arr[m]==Target)   /* ���F */
    {
       return m;
    }
    else
    {
      if(arr[m]>Target)  /* Target���W�b�� */
           Upper=m-1;
      else               /* Target���U�b�� */
           Low=m+1;
    }
 }
 return -1;
}

void main(void)
{
 int work[8]={33,41,52,54,63,74,79,86};
 int FindNumber,location;
 
 printf("�п�J�z�n�䪺�ƭ�:");
 scanf("%d",&FindNumber);
 location=BinarySearch(FindNumber,work,8);
 if(location==-1)
    printf("�b�}�C���䤣��n�䪺�ƭ�\n");
 else
    printf("�ƭ�%d���work[%d]\n",FindNumber,location);
 /*  system("pause");  */
}
