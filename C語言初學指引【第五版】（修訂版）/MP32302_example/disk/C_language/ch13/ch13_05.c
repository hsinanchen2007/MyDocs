/* �p�ը��� 13-1 */ 
/*  �ɦW:ch13_05.c  �\��:�챴C++�PC�y����struct�����P�C   */ /* �L�k�sĶ,�n����d��,�а���t�@��ch13_05.cpp */ 

#include <stdlib.h>
#include <stdio.h>

struct student
{
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
  void ComputeAvg()     /* �禡�]�������c�骺�@�Ӧ��� */
  {
     ScoreAvg=(float)(ScoreComputer+ScoreMath+ScoreEng)/3;
  }
  void display()        /* �禡�]�������c�骺�@�Ӧ��� */
  {
     printf("�p��\t�ƾ�\t�^��\t����\n");
     printf("%d\t%d\t%d\t%.4f\n",\
            ScoreComputer,ScoreMath,ScoreEng,ScoreAvg);
  }
};

int main(void)
{
 struct student a,b;

 a.ScoreComputer=80;
 a.ScoreMath=70;
 a.ScoreEng=50;
 a.ComputeAvg();             /* ���c��a����ComputeAvg�禡�p�⥭�� */
 a.display();                /* ���c��a����display�禡��X���Z */
 /* system("pause"); */ 
 return 0;
}
