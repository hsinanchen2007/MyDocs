//Common.h
// --------------------------------------
#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// �w�q inline �˪���� MAX()
template <class T>
inline const T& MAX(const T& x, const T& y)
   {return x > y ? x : y;}
// �w�q�Ω󲧱`�ˬd�� inline ��� Check()
inline void Check(bool ErrorCondition,
  const string& Message = "Requirement failed")
{
    if (ErrorCondition)
    { cerr << Message.c_str() << endl;  exit(1); }
}
// �w�q�W�٪Ŷ� ODEParameters
namespace ODEParameters
{
   const int	SysOrder   = 2,    //  �t�Ϊ�����
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
   char* TitleA    = "van der Pol Oscillator �ۦ��";
   char* FileName2 = "TXPlot.m";
   char* XLabelB   = "�ɶ� (sec)";
   char* YLabelB   = "X_1 �M X_2";
   char* TitleB    = "van der Pol Oscillator �ܤƹ�";
   char* X1Name    = "X_1";
   char* X2Name    = "X_2";
}
#include "Vector.h"
#include "Matrix.h"
using namespace ODEParameters;
// �w�q�n�n���� van der Pol �L����{��
Vector ODESystem(Vector& X)
{
   const double  mu = 2;
   Vector dX(2);
    dX[1] =  X[2];
    dX[2] = -X[1] + mu*(1.0 - X[1]*X[1])*X[2];
   return dX;
}
#endif