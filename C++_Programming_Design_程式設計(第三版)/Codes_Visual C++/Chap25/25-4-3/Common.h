#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

const double PI = 2.0*asin(1.0);
// �w�q�Ω�D�X���p�Ȫ� inline ��� MIN()
template <class T>
inline const T& MIN(const T& x, const T& y)
  {return x < y ? x : y;}
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
 const int   DOF    =   2;
 const double Range =10.0;
 const int MaxCount = 1000;
 const double eps   = 1.0e-30;
 const double Alpha = 1.0;
 const double Beta  = 0.5;
 const double Gamma = 2.0;
 const int NoVertices = DOF + 1;
 double fDOF = double(DOF);
}
using namespace SimplexParameters;
#include "Vector.h"
#include "Matrix.h"
// ------ �w�q�ؼШ�� --------------------
double ObjFnc(Vector& X)
{
  double Func;
  Func = pow((X[1]-2),2)/(1+pow((X[1]-2),2))+
         pow((X[2]-3),4)/(1+pow((X[2]-3),4));
  return Func;
}
// ------  ��� Simplex() ���ŧi ---------------
Vector Simplex(double (*ptFnc)(Vector&));
#endif

