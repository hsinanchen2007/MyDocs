/*    �ɦW:ch11_09.c    �\��:�t�X���c��Ū���G�i���ɸ��   */

#include <stdlib.h>
#include <stdio.h>

struct student
{
  char   stu_id[12];
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
};

FILE *fp;

void display(struct student);

void display(struct student tempStu)
{
  printf("%s\t%d\t%d\t%d\t%.4f\n",\
            tempStu.stu_id,tempStu.ScoreComputer,tempStu.ScoreMath,\
            tempStu.ScoreEng,tempStu.ScoreAvg);
}

/**************main**************/
void main(void)
{
  
 struct student IM[50];
 int i,num;
 
 if((fp = fopen("data4", "rb")) == NULL)
 {
   printf("�ɮ׿��~\n");
   exit(0);
  }
 
 num = fread(IM,sizeof(struct student),2,fp);
 
 printf("�G�i����Ū������,�e�ⵧ�ǥ͸�Ʀp�U\n");
 fclose(fp);
 
 for(i=0;i<2;i++)
    display(IM[i]);
 /* system("pause"); */
}
