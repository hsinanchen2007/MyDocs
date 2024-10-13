/*  檔名:ch13_04.c  功能:結構體中包含函式指標   */

#include <stdlib.h>
#include <stdio.h>

struct student
{
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
  void (*pf)(struct student *k);    /* 函式指標成為結構體的一個成員 */
};

void ComputeAvg(struct student *i);
void display(struct student *tempStu);

void ComputeAvg(struct student *i)
{
 i->ScoreAvg=(float)(i->ScoreComputer+i->ScoreMath+i->ScoreEng)/3;
}

void display(struct student *tempStu)
{
 printf("計概\t數學\t英文\t平均\n");
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
 a.pf(&a);                  /* 執行ComputeAvg函式計算平均 */
 a.pf=display;
 a.pf(&a);                  /* 執行display函式輸出成績 */
 /* system("pause"); */ 
}
