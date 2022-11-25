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
// ﹚竡ノ―耕 inline ㄧ计 MIN()
template <class T>
inline const T& MIN(const T& x, const T& y)
  {return x < y ? x : y;}
// ﹚竡ノ钵盽浪琩 inline ㄧ计 Check()
inline void Check(bool ErrorCondition,
  const string& Message = "Requirement failed")
{
 if (ErrorCondition)
 { cerr << Message << endl;  exit(1); }
}
// Rand() 玻ネ (0,1) ぇ丁睹计
inline double Rand()
 {return double(rand())/RAND_MAX;}
// ﹚竡ノ simplex 程ㄎて盽计
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
// ------ ﹚竡ヘ夹ㄧ计 --------------------
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
// ------ ﹚竡块ノㄧ计 ShowPandQ() --------------------
void ShowPandQ(Vector& X)
{
  const double c1 =  60.0;
  const double c2 =   5.0;
  double p;
  p = (X[1]*X[2])-4.0*X[3]*X[3]-c1;
  cout << " p     (瞶稱 = 0): " << p << endl;
  cout << " X[1]  (瞶稱 > 0): " << X[1] << endl;
  cout << " X[2]  (瞶稱 > 0): " << X[2] << endl;
  cout << " X[3]  (瞶稱 < "     << c2
       << " ): "                    << X[3] << endl;
  return;
}
// ------  ㄧ计 Simplex()  ---------------
Vector Simplex(double (*ptFnc)(Vector&));
#endif
