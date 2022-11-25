// Simplex.cpp
#include "Common.h"
#include <ctime>

int main()
{

//	cout << srand(1)<<endl;
  Vector Answer(DOF);
  Answer = Simplex(ObjFnc);
  cout << " 答案為:  " << endl;
  Answer.Display();
  system("pause");
  return 0;
}

//************************************************
Vector Simplex(double (*F)(Vector&))
{
  Matrix x(DOF, NoVertices);
  Vector Score(NoVertices);
  Vector Answer(DOF), Temp(DOF);
  Vector xH(DOF), xL(DOF), xC(DOF), xR(DOF);
  Vector xB(DOF), xE(DOF);
  double FxH, FxL, FxR, FxC, FxE, FxB;
  int H, L;
  int Count = 0;
  double  Q = 2.0*eps;
  
  srand(int(time(0))); 
  Randomize(x);
  cout << "各頂點的初始值是: " << endl;
  x.Display();
  
  for (int i = 1; i <= NoVertices; i++)
    {
     Temp    = x.PickCol(i);
     Score[i]= F(Temp);
    }

  while ((Count < MaxCount)&&(Q>eps))
  {
    H   = FindMaxSite(Score);
    L   = FindMinSite(Score);
    xH  = x.PickCol(H);
    xL  = x.PickCol(L);
    xB  = (SumVector(x)-xH)/fDOF;
    xR  = xB+((xB-xH)*Alpha);
    FxR = F(xR);
    FxH = Score[H];
    FxL = Score[L];
    Q   = 0.0;
    for (int i = 1; i <= NoVertices; i++)
       Q+=pow((Score[i]-FxL),2);
    if (FxR>FxH)
     {
       xC = xB+((xH-xB)*Beta);
       FxC= F(xC);
       if (FxC<FxH)
         {x.SetCol(H,xC); Score[H]= FxC;}
       else
       for (int i = 1; i <= NoVertices; i++)
         {
         	Temp = x.PickCol(i);
         	Temp = (Temp+xL)/2.0;
         	x.SetCol(i,Temp);
         	Score[i]= F(Temp);
         }
     }
     else if (FxR>FxL)
         {x.SetCol(H,xR); Score[H]= FxR;}
     else
     {
       xE = xB+((xR-xB)*Gamma);
       FxE= F(xE);
       if (FxE<FxL)
         {x.SetCol(H,xE); Score[H]= FxE;}
       else
         {x.SetCol(H,xR); Score[H]= FxR;}
     }
    Count++;
  }

  Answer = xL;
  cout << " 重覆搜尋次數:     "
       << Count  << " 次" << endl;
  cout << " 最佳目標函數值為: "
       << F(Answer) << endl;
  cout << " Q 的大小是:       "
       << Q << endl;
  return Answer;
}
