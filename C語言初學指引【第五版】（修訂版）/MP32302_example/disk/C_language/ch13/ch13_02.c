/*    �ɦW:ch13_02.c    �\��:�z�L�禡���а��椣�P���禡   */

#include <stdlib.h>
#include <stdio.h>

int add(int a,int b)
{
    return a+b;
}

int mul(int a,int b)
{
    return a*b;
}

void main(void)
{
  int result1,result2;
  typedef int (*funcT)(int,int); /* �w�qfuncT���禡���Ы��A���O�W */
  funcT pfunc;               /* �Q�ΧO�W�A�ŧipfunc�禡���� */
  pfunc=add;                 /* pfunc���Vadd�禡�_�l��} */
  result1=pfunc(3,5);/*����1 */ /*�i������result1=(*pfunc)(3,5);*/
  printf("result1=%d\n",result1);
  pfunc=mul;                 /* pfunc���Vmul�禡�_�l��} */
  result2=(*pfunc)(3,5);/*������2 */ /*�i������result2=pfunc(3,5);*/
  printf("result2=%d\n",result2);
  /* system("pause"); */ 
}
