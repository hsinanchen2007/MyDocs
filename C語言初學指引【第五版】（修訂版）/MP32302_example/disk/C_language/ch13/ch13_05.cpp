/*  檔名:ch13_05.cpp  功能:初探C++與C語言之struct的不同。   */

#include <stdlib.h>
#include <stdio.h>

struct student
{
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
  void ComputeAvg()     /* 函式也成為結構體的一個成員 */
  {
     ScoreAvg=(float)(ScoreComputer+ScoreMath+ScoreEng)/3;
  }
  void display()        /* 函式也成為結構體的一個成員 */
  {
     printf("計概\t數學\t英文\t平均\n");
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
 a.ComputeAvg();             /* 結構體a執行ComputeAvg函式計算平均 */
 a.display();                /* 結構體a執行display函式輸出成績 */
 /* system("pause"); */ 
 return 0;
}
