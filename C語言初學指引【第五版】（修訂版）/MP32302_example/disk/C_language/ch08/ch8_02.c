/*    �ɦW:ch8_02.c    �\��:�����ܼƪ����e�H�Ϋ����ܼƪ��j�p    */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int a=100;
 double b=5.5;
 int *ptr1=&a;        /* �۷��  int *ptr1; ��  ptr1=&a;  */
 double *ptr2=&b;     /* �۷��  double *ptr2; ��  ptr2=&b;  */
  
 printf("a=%d\n",a);
 printf("b=%e\n",b);
 printf("&a=%p\n",&a);
 printf("&b=%p\n",&b);
 printf("*ptr1=%d\n",*ptr1);
 printf("*ptr2=%e\n",*ptr2);
 printf("ptr1=%p\n",ptr1);
 printf("ptr2=%p\n",ptr2);
 printf("&ptr1=%p\n",&ptr1);
 printf("&ptr2=%p\n",&ptr2);
 printf("&*ptr1=%p\n",&*ptr1); /*   &*ptr1�۷��&a�۷��ptr1  */
 printf("&*ptr2=%p\n",&*ptr2); /*   &*ptr2�۷��&b�۷��ptr2  */
 printf("===============================\n");
 printf("�ܼ�a����%d�Ӧ줸��\n",sizeof(a));
 printf("�ܼ�b����%d�Ӧ줸��\n",sizeof(b));
 printf("===============================\n");
 printf("�ܼ�ptr1����%d�Ӧ줸��\n",sizeof(ptr1));
 printf("�ܼ�ptr2����%d�Ӧ줸��\n",sizeof(ptr2));
 /*  system("pause");  */
}
