// Common.h
#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <iomanip>
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
 const int   DOF   =   2;
 const int MaxCount= 1000;
 const double eps   = 1.0e-20;
 const double Alpha = 1.0;
 const double Beta  = 0.5;
 const double Gamma = 2.0;
 const double Range = 5.0;
 const int NoVertices = DOF + 1;
 double fDOF = double(DOF);
}
using namespace SimplexParameters;
#include "Vector.h"
#include "Matrix.h"

// ------ �w�q Ackley ��� --------------------
double ObjFnc(Vector& V)
{
  double Func;
  const double c1 = 20.0;
  const double c2 = 0.2;
  const double c3 = 2 * PI;
  Func = -c1*exp(-c2*(0.5*sqrt(V[1]*V[1]+V[2]*V[2])))
         -exp(0.5*(cos(c3*V[1])+cos(c3*V[2])));
  return Func;
}
// ------  ��� Simplex() ���ŧi ---------------
Vector Simplex(double (*ptFnc)(Vector&));

#endif