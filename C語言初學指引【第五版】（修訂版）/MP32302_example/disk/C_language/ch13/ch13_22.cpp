/*    �ɦW:ch13_22.cpp    �\��:new��delete������  */

#include <stdio.h>
#include <stdlib.h>
#include "./lotto.h"

/**************main()**************/
int main(int argc,char *argv[])
{
 int i,special,ball_qty=6,temp;
 int* lotto;  //�o�OC++�ŧi���Ъ��y�k

 if(argc>1)
 {
    ball_qty=atoi(argv[1]);  /* atoi���ޤJstdlib.h */
    if(ball_qty==0)
    {
       printf("�Ѽƿ��~,�Ҧp��J�y�ƫD�Ʀr\n");
       return -1;
    }
    if(!((ball_qty>=1) && (ball_qty<=48)))
    {
       printf("�Ѽƿ��~,�Ҧp��J�y�ƫD1~48\n");
       return -1;
    }
 }
 lotto=new int[ball_qty];
 generate_lotto_sort(&special,lotto,ball_qty);

 printf("�ֳz���X�p�U.....\n");
 for(i=0;i<ball_qty;i++)
 {
   if((i%6==0) && (i!=0))
         printf("\n");
   printf("%d\t",lotto[i]);
 }   
 if(ball_qty==1)
   delete lotto;
 else
   delete [] lotto;
 printf("\n");
 printf("�S�O��:%d\n",special);
 return 1;
}
