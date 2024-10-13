/*    郎:ch7_20.c    :だ穓碝猭   */

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int Target,int *arr,int arr_index)
{
 int Low,Upper,m;
 
 Low=0;
 Upper=arr_index-1;
 while (Low<=Upper)
 {
    m=(Low+Upper)/2;     /* 璸衡い丁竚 */
    if(arr[m]==Target)   /* т */
    {
       return m;
    }
    else
    {
      if(arr[m]>Target)  /* Target场 */
           Upper=m-1;
      else               /* Target场 */
           Low=m+1;
    }
 }
 return -1;
}

void main(void)
{
 int work[8]={33,41,52,54,63,74,79,86};
 int FindNumber,location;
 
 printf("叫块眤璶т计:");
 scanf("%d",&FindNumber);
 location=BinarySearch(FindNumber,work,8);
 if(location==-1)
    printf("皚いтぃ璶т计\n");
 else
    printf("计%dwork[%d]\n",FindNumber,location);
 /*  system("pause");  */
}
