/*    �ɦW:ch8_05.c    �\��:�����ܼƪ�����B��   */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int a,b;
 int *p=&a,*q=&b;
 
 printf("����p���V�O�����}%p\n",p);
 printf("����q���V�O�����}%p\n",q);
 if(p>q)
   printf("�ܼ�a���O�����}�����ܼ�b���O�����}\n");
 else
   printf("�ܼ�b���O�����}�����ܼ�a���O�����}\n");
 /*  system("pause");  */
}
