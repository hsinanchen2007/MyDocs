//Common.h
// --------------------------------------
#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// 定義 inline 樣版函數 MAX()
template <class T>
inline const T& MAX(const T& x, const T& y)
   {return x > y ? x : y;}
// 定義用於異常檢查的 inline 函數 Check()
inline void Check(bool ErrorCondition,
  const string& Message = "Requirement failed")
{
    if (ErrorCondition)
    { cerr << Message.c_str() << endl;  exit(1); }
}
// 定義名稱空間 ODEParameters
namespace ODEParameters
{
   const int	SysOrder   = 2,    //  系統的階數
		NoPoint    = 501;
   const double	tStart     = 0.0,
		tEnd       = 20.0;
   const double Xi[]       = {0.5, 0};
   const double ErrorBound = 1.0;
   const double h  =
         (tEnd - tStart)/double(NoPoint - 1);
   char* FileName1 = "XYPlot.m";
   char* XLabelA   = "X_1";
   char* YLabelA   = "X_2";
   char* TitleA    = "van der Pol Oscillator 相位圖";
   char* FileName2 = "TXPlot.m";
   char* XLabelB   = "時間 (sec)";
   char* YLabelB   = "X_1 和 X_2";
   char* TitleB    = "van der Pol Oscillator 變化圖";
   char* X1Name    = "X_1";
   char* X2Name    = "X_2";
}
#include "Vector.h"
#include "Matrix.h"
using namespace ODEParameters;
// 定義要積分的 van der Pol 微分方程組
Vector ODESystem(Vector& X)
{
   const double  mu = 2;
   Vector dX(2);
    dX[1] =  X[2];
    dX[2] = -X[1] + mu*(1.0 - X[1]*X[1])*X[2];
   return dX;
}
#endif