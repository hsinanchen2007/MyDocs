/*    �ɦW:ch7_04.c    �\��:�禡����    */

#include <stdio.h>
#include <stdlib.h>

long int factorial(int p); /* �禡�ŧi */
long int factorial(int p)  /* �禡�w�q */
{
 int count;
 long int result = 1;
  
 for(count=1;count<=p;count++)
 {
   result = result * count;
 }
 return result;
}

void main(void)
{
 int m,n;
 long int ans;
 long int temp[3];
   
 printf("�D�ƦC�զXC(m,n)\n");
 printf("m = ");
 scanf("%d",&m);
 printf("n = ");
 scanf("%d",&n);
 
 temp[0] = factorial(m);      /*  �p�� m! ����     */
 temp[1] = factorial(n);      /*  �p�� n! ����     */
 temp[2] = factorial(m-n);    /*  �p�� (m-n)! ���� */
 ans = (temp[0])/(temp[1]*temp[2]);  /* C(m,n) = (m!)/(n!*(m-n)!) */
 printf("C(%d,%d) = %d\n",m,n,ans);
 /*  system("pause");  */
}
