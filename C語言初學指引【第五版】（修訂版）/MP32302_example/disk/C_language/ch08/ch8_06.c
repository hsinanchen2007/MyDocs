/*    �ɦW:ch8_06.c    �\��:�p��۹j�����Ӽ�    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 double array[8][15];
 double *p,*q;
 int blocksize,count;
 
 p=&array[2][6];
 q=&array[6][11];
 
 count=q-p;
 blocksize=count*sizeof(double);
 
 printf("p=%p\t q=%p\n",p,q);
 printf("����[2][6](�t)~[6][10](�t)�����@��%d�Ӥ���\n",count);
 printf("����[2][6](�t)~[6][10](�t)�������O����϶��j�p��");
 printf("%d�줸��\n",blocksize);
 /*  system("pause");  */
}
