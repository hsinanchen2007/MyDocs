// Vector.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// セ祘Α舦妮 眎模く
// ㄏノゲ惠羘.
// --------------------------------------
#ifndef Vector_H
#define Vector_H
#include <iomanip>
using std::cout;
using std::endl;
using std::ios;
// -----  Vector 摸 ----------------
class Vector
{
  //  friend 笲衡更ㄧ计
  friend Vector operator*
        (const double& , const Vector& );
  friend Vector operator*
        (const Vector& , const double& );
  //  friend ㄧ计
  friend double  InfNorm(Vector&);
  friend double  SquareNorm(Vector&);
  friend int FindMaxSite(Vector&);
  friend int FindMinSite(Vector&);
  private:
    int Size;
    double* V;
    void Create(int);
  public:
    // 篶ㄧ计
    Vector(int);
    Vector(int, const double*);
    // 狡籹篶ㄧ计
    Vector(Vector&);
    // 秆篶ㄧ计
    ~Vector();
    // 笲衡更Θㄧ计
    Vector operator=(const Vector&);
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    Vector operator/(const double&);
    double& operator[](int i)
            {return V[i];}
    // Θㄧ计 Display()
    void Display();
};
// ------ ﹚竡 Vector 摸 ----------------
// ﹚竡 private Θㄧ计 Create()
void Vector::Create(int N)
{
   if(N<1)
      {Size = 0; V = 0;}
   else
      {Size = N; V = new double[N+1];}
}
// ﹚竡篶ㄧ计
Vector::Vector(int N)
{
  Create(N);
  return;
}
// ﹚竡秆篶ㄧ计
Vector::~Vector()
  { delete [] V; }
// ﹚竡狡籹篶ㄧ计 - 1
Vector::Vector(int N, const double* OldV)
{
  Create(N);
  for (int i=1; i<= Size; i++)
   V[i]= OldV[i-1];
  return;
}
// ﹚竡狡籹篶ㄧ计 - 2
Vector::Vector(Vector& OldV)
{
  Create(OldV.Size);
  for (int i=1; i<= Size; i++)
   V[i]= OldV.V[i];
  return;
}
// ﹚竡笲衡 operator = ()
Vector Vector::operator=(const Vector& V2)
{
  if (Size!=V2.Size)
    Create(V2.Size);
  for (int i=1; i<= Size; i++)
       V[i] = V2.V[i];
  return *this;
}
// ﹚竡猭笲衡 operator + ()
Vector Vector::operator+(const Vector& V2)
{
  Check(Size!=V2.Size,
   "Addition error (Not of the same size)");
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]+V2.V[i];
  return temp;
}
// ﹚竡搭猭笲衡 operator - ()
Vector Vector::operator-(const Vector& V2)
{
  Check(Size!=V2.Size,
   "Subtraction error (Not of the same size)");
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]-V2.V[i];
  return temp;
}
// ﹚竡埃猭笲衡 operator / ()
Vector Vector::operator/(const double& f)
{
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]/f;
  return temp;
}
// ﹚竡猭笲衡-1  operator * ()
Vector operator*
  (const double& f, const Vector& V1)
{
     Vector doubleemp(V1.Size);
     for(int i=1; i<=V1.Size; i++)
        doubleemp.V[i] = f * V1.V[i];
     return doubleemp;
}
// ﹚竡猭笲衡-2  operator * ()
Vector operator*
  (const Vector& V1, const double& f)
{
     Vector doubleemp(V1.Size);
     for(int i=1; i<=V1.Size; i++)
        doubleemp.V[i] = f * V1.V[i];
     return doubleemp;
}
// ﹚竡Θㄧ计 Display()
void Vector::Display()
{
  for(int i = 1; i <= Size; i++)
    cout << setiosflags(ios::right)
         << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << std::setprecision(4)
         << std::setw(12) << V[i];
    cout << endl;
  return;
}
// ﹚竡 friend ㄧ计 InfNorm()
double InfNorm(Vector& V1)
{
  double InN, xtemp;
  InN = fabs(V1.V[1]);
  for (int i = 2; i <= V1.Size; i++)
      { xtemp=fabs(V1.V[i]);
      	if (InN < xtemp)  InN=xtemp;
      }
return InN;
}
// ﹚竡 friend ㄧ计 SquareNorm()
double SquareNorm(Vector& V1)
{
  double S;
  S = 0.0;
  for (int i = 1; i <= V1.Size; i++)
    S += V1.V[i]*V1.V[i];
  return S;
}
// ﹚竡 friend ㄧ计 FindMaxSite()
int FindMaxSite(Vector& V1)
{
  int Count=1;
  for (int i = 2; i <= V1.Size; i++)
      { if (V1.V[Count] < V1.V[i])  Count=i; }
  return Count;
}

// ﹚竡 friend ㄧ计 FindMinSite()
int FindMinSite(Vector& V1)
{
  int Count=1;
  for (int i = 2; i <= V1.Size; i++)
      { if (V1.V[Count] > V1.V[i])  Count=i; }
  return Count;
}
#endif