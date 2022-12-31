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
 const int   DOF    =   2;
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
  Func = pow((X[1]-X[2]),4)+
   pow((X[1]*X[1]+X[2]-2),2)+pow((X[1]*X[2]-1),2);
  return Func;
}
// ------  ㄧ计 Simplex()  ---------------
Vector Simplex(double (*ptFnc)(Vector&));

#endif