/*    �ɦW:ch13_01.c    �\��:�[��U�ظ�Ʀb�O���骺�t�m   */

#include <stdlib.h>
#include <stdio.h>

int x;
int ar1[10];

void f1(int a)
{
  int b;
  static int y;
  static int ar2[10];

  printf("f1���Ѽ�a����}  \t:%p\n",&a);
  printf("f1���ϰ��ܼ�b����}\t:%p\n",&b);
  printf("f1�R�A�ϰ��ܼ�y��}\t:%p\n",&y);
  printf("f1���R�A�}�Car2��}\t:%p\n",&ar2);
}

void f2(int c)
{
  int d;
  int ar3[10];
  printf("f2���Ѽ�c����}  \t:%p\n",&c);
  printf("f2���ϰ��ܼ�d����}\t:%p\n",&d);
  printf("f2���@��}�Car3����}\t:%p\n",&ar3);
}

void main(void)
{
  int w;
  char* const s1="abc";
  char s2[]="abc";
  void (*pfunc)(int); 

  int *p=&x;
  
  printf("�����ܼ�x����}  \t:%p\n",p);
  printf("����}�Car1����}\t:%p\n",&ar1);
  printf("�@��ϰ��ܼ�w����}\t:%p\n",&w);
  /* *(s1+1)='k'; */
  /* �W�@��,�sĶ�ɦX�k,������|�����涥�q�����~,��]�b��z��F�`�ưϪ��� */ 
  printf("s1�r��abc���_�l��}\t:%p\n",s1);
  *(s2+1)='k';
  printf("s2�r��abc���_�l��}\t:%p\n",s2);  
  printf("�����ܼ�pfunc����}\t:%p\n",&pfunc);
  printf("�����ܼ�p����}\t\t:%p\n",&p);
  pfunc=f1;
  printf("�禡f1���_�l��}   \t:%p\n",pfunc);
  f1(3); 

  pfunc=f2;
  printf("�禡f2���_�l��}\t:%p\n",pfunc);
  f2(5);
  pfunc=main;
  printf("�禡main���_�l��}\t:%p\n",pfunc);
  /* system("pause"); */
}
