//Common.h
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
    { 
		cerr << Message.c_str() << endl;
		exit(1); 
	}
}
// 定義名稱空間 ODEParameters
namespace ODEParameters
{
   // 定義系統的階數
   const int	SysOrder   = 2,
		NoPoint    = 251;
   const double	tStart     = 0.0,
		tEnd       = 10.0;
   // 定義初始值
   const double Xi[]       = {2, 0.5};
   const double ErrorBound = 1.0;
   const double h  =
         (tEnd - tStart)/double(NoPoint - 1);
   char* FileName1 = "XYPlot.m";
   char* XLabelA   = "x_1 (獵物)";
   char* YLabelA   = "x_2 (掠食者)";
   char* TitleA    = "獵物-掠食者 族群大小變化圖";
   char* FileName2 = "TXPlot.m";
   char* XLabelB   = "時間 (年)";
   char* YLabelB   = "族群大小";
   char* TitleB    = "獵物-掠食者 族群消長圖";
   char* X1Name    = "獵物";
   char* X2Name    = "掠食者";
}
#include "Vector.h"
#include "Matrix.h"
using namespace ODEParameters;
// 定義要積分的 ODE 方程組
Vector ODESystem(Vector& X)
{
   const double  b1=1,b2=1,c1=1,c2=1;
   Vector dX(2);
   dX[1] = ( b1 - c1*X[2])*X[1];
   dX[2] = (-b2 + c2*X[1])*X[2];
   return dX;
}

#endif