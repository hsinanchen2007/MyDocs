/*    �ɦW:ch13_10.cpp    �\��:�غc�禡�]�w�����ܼƪ��   */

#include <stdlib.h>
#include <stdio.h>

class myclass
{
  public:
     int VarA;
     myclass();          //�ŧi�غc�禡
     void ShowVar();
  private:
     int VarB;
};
myclass::myclass()    //�w�q�غc�禡
{
    VarA=0;
    VarB=0;
    printf("������Ƥw��l��\n");
}
void myclass::ShowVar()
{
    printf("VarA=%d\n",VarA);
    printf("VarB=%d\n",VarB);
}

int main(void)
{
   myclass X;
 
   X.ShowVar();
   /* system("pause"); */ system("pause");
   return 0;
}
