// Common.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
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
   const int	SysOrder   = 3;    //  系統的階數
   const int    NoPoint    = 4001;
   const double	tStart     = 0.0;
   const double tEnd       = 30.0;
   const double Xi[]       = {1.0, 0.0, 2.0};
   const double ErrorBound = 1.0;
   const double h  =
         (tEnd - tStart)/double(NoPoint - 1);
   char* FileName1 = "XYPlot.m";
   char* XLabelA   = "X_1";
   char* YLabelA   = "X_3";
   char* TitleA    =
         "Lorenz Attractor (X_1 vs. X_3)";
   char* FileName2 = "XYZPlot.m";
   char* XLabelB   = "X_1";
   char* YLabelB   = "X_2";
   char* ZLabelB   = "X_3";
   char* TitleB    = "Lorenz Attractor 立體圖";
}
#include "Vector.h"
#include "Matrix.h"
using namespace ODEParameters;
// 定義要積分的 Lorentz 微分方程組
Vector ODESystem(Vector& X)
{
   const double Sigma  = 10.0;
   const double Lambda = 25.0;
   const double Gamma  =  2.0;
   Vector dX(3);
   dX[1] = Sigma*(X[2] - X[1]);
   dX[2] = (Lambda - X[3])*X[1] - X[2];
   dX[3] = X[1]*X[2] - Gamma*X[3];
   return dX;
}
#endif