/*    �ɦW:ch7_02.c    �\��:�ŧi,�w�q,�I�s�禡   */

#include <stdio.h>
#include <stdlib.h>

double Power(double,int);

double Power(double X,int n)
{
 int i;
 double PowerXn=1;
 
 for(i=1;i<=n;i++)
     PowerXn=PowerXn*X;
 return PowerXn;
}

void main(void)
{
 int k;
 double Ans;
     
 printf("�p��3.5��k����?�п�Jk=");
 scanf("%d",&k);
 Ans=Power(3.5,k);        /*  �I�s�禡  */
 printf("3.5��%d����=%f\n",k,Ans);
 /*  system("pause");  */
}
