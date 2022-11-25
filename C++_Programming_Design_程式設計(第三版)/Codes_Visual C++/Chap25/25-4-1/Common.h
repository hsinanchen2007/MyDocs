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

// ------ ﹚竡 Ackley ㄧ计 --------------------
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
// ------  ㄧ计 Simplex()  ---------------
Vector Simplex(double (*ptFnc)(Vector&));

#endif