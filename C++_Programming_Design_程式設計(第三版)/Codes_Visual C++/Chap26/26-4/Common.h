//Common.h
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
    { 
		cerr << Message.c_str() << endl;
		exit(1); 
	}
}
// �w�q�W�٪Ŷ� ODEParameters
namespace ODEParameters
{
   // �w�q�t�Ϊ�����
   const int	SysOrder   = 2,
		NoPoint    = 251;
   const double	tStart     = 0.0,
		tEnd       = 10.0;
   // �w�q��l��
   const double Xi[]       = {2, 0.5};
   const double ErrorBound = 1.0;
   const double h  =
         (tEnd - tStart)/double(NoPoint - 1);
   char* FileName1 = "XYPlot.m";
   char* XLabelA   = "x_1 (�y��)";
   char* YLabelA   = "x_2 (������)";
   char* TitleA    = "�y��-������ �ڸs�j�p�ܤƹ�";
   char* FileName2 = "TXPlot.m";
   char* XLabelB   = "�ɶ� (�~)";
   char* YLabelB   = "�ڸs�j�p";
   char* TitleB    = "�y��-������ �ڸs������";
   char* X1Name    = "�y��";
   char* X2Name    = "������";
}
#include "Vector.h"
#include "Matrix.h"
using namespace ODEParameters;
// �w�q�n�n���� ODE ��{��
Vector ODESystem(Vector& X)
{
   const double  b1=1,b2=1,c1=1,c2=1;
   Vector dX(2);
   dX[1] = ( b1 - c1*X[2])*X[1];
   dX[2] = (-b2 + c2*X[1])*X[2];
   return dX;
}

#endif