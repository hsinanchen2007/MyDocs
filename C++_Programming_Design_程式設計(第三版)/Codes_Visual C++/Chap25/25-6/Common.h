// Common.h
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

const double PI = 2.0*asin(1.0);
// �w�q�Ω󲧱`�ˬd�� inline ��� Check()
inline void Check(bool ErrorCondition,
  const string& Message = "Requirement failed")
{
 if (ErrorCondition)
 { cerr << Message << endl;  exit(1); }
}
// Rand() �i�H���� (0,1) �������ü�
inline double Rand()
 {return double(rand())/RAND_MAX;}
// �w�q�Ω� simplex �̨Τƪ��`��
namespace SimplexParameters
{
 const int   DOF    =   5;
 const int   Size   = 200;
 const double   h   = 0.1;
 const double Range = 10.0;
 const int MaxCount = 10000;
 const double eps   = 1.0e-20;
 const double Alpha = 1.0;
 const double Beta  = 0.5;
 const double Gamma = 2.0;
 const int NoVertices = DOF + 1;
 double fDOF = double(DOF);
}
using namespace SimplexParameters;
#include "Vector.h"
#include "Matrix.h"
// ------ �w�q�x�s��l�ƾڪ��V�q Data -----
Vector Data(Size);
// ------ �w�q�ؼШ�� --------------------
double ObjFnc(Vector& V)
{
  double Func;
  Vector y(200), Temp(200);
  double t;
  for (int i = 1; i<= 200; i++)
  { 
    t   = h*double(i);
    y[i]= V[1]*exp(-V[2]*t)*cos(V[3]*t+V[4])+V[5];
  }
  Temp  = y-Data;
  Func = SquareNorm(Temp);
  return Func;
}
// ------  ��� Simplex() ���ŧi ---------------
Vector Simplex(double (*ptFnc)(Vector&));
#endif