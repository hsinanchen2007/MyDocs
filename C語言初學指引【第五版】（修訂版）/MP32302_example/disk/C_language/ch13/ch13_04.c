/*  �ɦW:ch13_04.c  �\��:���c�餤�]�t�禡����   */

#include <stdlib.h>
#include <stdio.h>

struct student
{
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
  void (*pf)(struct student *k);    /* �禡���Ц������c�骺�@�Ӧ��� */
};

void ComputeAvg(struct student *i);
void display(struct student *tempStu);

void ComputeAvg(struct student *i)
{
 i->ScoreAvg=(float)(i->ScoreComputer+i->ScoreMath+i->ScoreEng)/3;
}

void display(struct student *tempStu)
{
 printf("�p��\t�ƾ�\t�^��\t����\n");
 printf("%d\t%d\t%d\t%.4f\n",\
            tempStu->ScoreComputer,tempStu->ScoreMath,\
            tempStu->ScoreEng,tempStu->ScoreAvg);
}

void main(void)
{
 struct student a;

 a.ScoreComputer=80;
 a.ScoreMath=70;
 a.ScoreEng=50;
 a.pf=ComputeAvg;
 a.pf(&a);                  /* ����ComputeAvg�禡�p�⥭�� */
 a.pf=display;
 a.pf(&a);                  /* ����display�禡��X���Z */
 /* system("pause"); */ 
}
