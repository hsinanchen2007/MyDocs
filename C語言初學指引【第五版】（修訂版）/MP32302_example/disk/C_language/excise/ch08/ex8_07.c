#include <stdio.h>

void main(void)
{
  int A[5]={5,6,7,8,9};
  char *p=(char *)A;
  int temp;
    
 /*************�[�J�{���X,�ϱotemp���e��A[3]����****************/
 temp=*p;
 printf("A[3]=%d\n",temp);
}