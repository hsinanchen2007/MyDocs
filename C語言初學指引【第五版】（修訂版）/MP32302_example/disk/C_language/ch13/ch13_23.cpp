/*    �ɦW:ch13_23.cpp    �\��:�Ѻc�禡�P�ʺA�O����t�m   */

#include <stdio.h>
#include <stdlib.h>

class student
{
 public:
    ~student();
    int stu_size();
    void showdata();
  
 private:
   struct stu
   {
     char   stu_id[12];
     int    ScoreComputer;
     int    ScoreMath;
     int    ScoreEng;
     float  ScoreAvg;
   };
   stu Entry;     //C++�y�k
};

student::~student()
{
  printf("���b�R��1��student���O������\n");
   //�z�٥i�H�b�o�䰵��L�Ƴ�~
}

int student::stu_size()
  {
    return sizeof(stu);   //C++�y�k
  }

void student::showdata()
{
  printf("%s\t%d\t%d\t%d\t%f\n",Entry.stu_id,Entry.ScoreComputer, \
         Entry.ScoreMath,Entry.ScoreEng,Entry.ScoreAvg);
}

FILE* fp;      //C++�y�k

/**************main**************/
int main(void)
{  
 student* IM;      //C++�y�k
 IM=new student[10];
 int i;
 
 if((fp = fopen("data4", "rb")) == NULL)
 {
   printf("�ɮ׿��~\n");
   exit(0);
  }
 int num = fread(IM,sizeof(student),2,fp);   //C++�y�k
 fclose(fp);
 
 printf("�G�i����Ū������,�e�ⵧ�ǥ͸�Ʀp�U\n");
  
 for(i=0;i<2;i++)
    IM[i].showdata();
 delete [] IM;
 system("pause");
 return 0;
}
