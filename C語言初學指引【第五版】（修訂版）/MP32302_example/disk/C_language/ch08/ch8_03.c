/*    �ɦW:ch8_03.c    �\��:�����ܼƪ����w�B��    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int a=100;
 int *p,*q;

 printf("============�ŧi�ܼƮ�=============\n");
 printf("&a=%p\t a=%d\n",&a,a);
 printf("&p=%p\n",&p);
 printf("&q=%p\n",&q);

 p=&a;
 printf("============�]�wp=&a��=============\n");
 printf("p=%p\t *p=%d\n",p,*p);

 q=p;
 printf("============�]�wq=p��=============\n");
 printf("q=%p\t *q=%d\n",q,*q);

 *q=50;
 printf("===========�]�w*q=50��============\n");
 printf("p=%p\t *p=%d\n",p,*p);
 printf("q=%p\t *q=%d\n",q,*q);
 printf("a=%d\n",a);
 /*  system("pause");  */
}
