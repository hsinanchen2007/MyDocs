/*    檔名:ch13_23.cpp    功能:解構函式與動態記憶體配置   */

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
   stu Entry;     //C++語法
};

student::~student()
{
  printf("正在刪除1個student類別的物件\n");
   //您還可以在這邊做其他事喔~
}

int student::stu_size()
  {
    return sizeof(stu);   //C++語法
  }

void student::showdata()
{
  printf("%s\t%d\t%d\t%d\t%f\n",Entry.stu_id,Entry.ScoreComputer, \
         Entry.ScoreMath,Entry.ScoreEng,Entry.ScoreAvg);
}

FILE* fp;      //C++語法

/**************main**************/
int main(void)
{  
 student* IM;      //C++語法
 IM=new student[10];
 int i;
 
 if((fp = fopen("data4", "rb")) == NULL)
 {
   printf("檔案錯誤\n");
   exit(0);
  }
 int num = fread(IM,sizeof(student),2,fp);   //C++語法
 fclose(fp);
 
 printf("二進位檔讀取完成,前兩筆學生資料如下\n");
  
 for(i=0;i<2;i++)
    IM[i].showdata();
 delete [] IM;
 system("pause");
 return 0;
}
