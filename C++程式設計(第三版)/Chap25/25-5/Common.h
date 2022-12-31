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
 const int   DOF    =   3;
 const double Range =10.0;
 const int MaxCount = 1000;
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
// ------ �w�q�ؼШ�� --------------------
double ObjFnc(Vector& X)
{
  double Func;
  const double c1 =  60.0;
  const double c2 =   5.0;
  const double mu = 1000.0;
  double f, p, q1, q2, q3, q4, temp;
  f=-(X[1]-2.0*X[3])*(X[2]-2.0*X[3])*X[3];
  p= (X[1]*X[2])-4.0*X[3]*X[3]-c1;
  temp=X[1]-eps;
  q1=MIN(temp, 0.0);
  temp=X[2]-eps;
  q2=MIN(temp, 0.0);
  temp=X[3]-eps;
  q3=MIN(temp, 0.0);
  temp = c2-X[3]-eps;
  q4=MIN(temp, 0.0);  
  Func = f+ mu*( p*p + q1*q1 + q2*q2 + q3*q3 + q4*q4);
  return Func;
}
// ------ �w�q��X�Ψ�� ShowPandQ() --------------------
void ShowPandQ(Vector& X)
{
  const double c1 =  60.0;
  const double c2 =   5.0;
  double p;
  p = (X[1]*X[2])-4.0*X[3]*X[3]-c1;
  cout << " p    �� (�z�Q�� = 0): " << p << endl;
  cout << " X[1] �� (�z�Q�� > 0): " << X[1] << endl;
  cout << " X[2] �� (�z�Q�� > 0): " << X[2] << endl;
  cout << " X[3] �� (�z�Q�� < "     << c2
       << " ): "                    << X[3] << endl;
  return;
}
// ------  ��� Simplex() ���ŧi ---------------
Vector Simplex(double (*ptFnc)(Vector&));
#endif
