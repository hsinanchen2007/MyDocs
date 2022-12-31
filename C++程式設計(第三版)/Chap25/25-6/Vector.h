// Vector.h
#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <iomanip>
using namespace std;
// ----- �ŧi Vector ���O ----------------
class Vector
{
  // �ŧi friend �B��l�������
  friend Vector operator*
        (const double& , const Vector& );
  friend Vector operator*
        (const Vector& , const double& );
  // �ŧi friend ���
  friend double  InfNorm(Vector&);
  friend double  SquareNorm(Vector&);
  friend int FindMaxSite(Vector&);
  friend int FindMinSite(Vector&);
  private:
    int Size;
    double* V;
    void Create(int);
  public:
    // �ŧi�غc���
    Vector(int);
    Vector(int, const double*);
    // �ŧi�ƻs�غc���
    Vector(Vector&);
    // �ŧi�Ѻc���
    ~Vector();
    // �ŧi�B��l�����������
    Vector operator=(const Vector&);
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    Vector operator/(const double&);
    double& operator[](int i)
            {return V[i];}
    // �ŧi������� Display()
    void Display();
};
// ------ �w�q Vector ���O ----------------
// �w�q private ������� Create()
void Vector::Create(int N)
{
   if(N<1)
      {Size = 0; V = 0;}
   else
      {Size = N; V = new double[N+1];}
}
// �w�q�غc���
Vector::Vector(int N)
{
  Create(N);
  return;
}
// �w�q�Ѻc���
Vector::~Vector()
  { delete [] V; }
// �w�q�ƻs�غc��� - 1
Vector::Vector(int N, const double* OldV)
{
  Create(N);
  for (int i=1; i<= Size; i++)
   V[i]= OldV[i-1];
  return;
}
// �w�q�ƻs�غc��� - 2
Vector::Vector(Vector& OldV)
{
  Create(OldV.Size);
  for (int i=1; i<= Size; i++)
   V[i]= OldV.V[i];
  return;
}
// �w�q�����B��l operator = ()
Vector Vector::operator=(const Vector& V2)
{
  if (Size!=V2.Size)
    Create(V2.Size);
  for (int i=1; i<= Size; i++)
       V[i] = V2.V[i];
  return *this;
}
// �w�q�[�k�B��l operator + ()
Vector Vector::operator+(const Vector& V2)
{
  Check(Size!=V2.Size,
   "Addition error (Not of the same size)");
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]+V2.V[i];
  return temp;
}
// �w�q��k�B��l operator - ()
Vector Vector::operator-(const Vector& V2)
{
  Check(Size!=V2.Size,
   "Subtraction error (Not of the same size)");
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]-V2.V[i];
  return temp;
}
// �w�q���k�B��l operator / ()
Vector Vector::operator/(const double& f)
{
  Vector temp(Size);
  for (int i=1; i<= Size; i++)
       temp.V[i]= V[i]/f;
  return temp;
}
// �w�q���k�B��l-1  operator * ()
Vector operator*
  (const double& f, const Vector& V1)
{
     Vector doubleemp(V1.Size);
     for(int i=1; i<=V1.Size; i++)
        doubleemp.V[i] = f * V1.V[i];
     return doubleemp;
}
// �w�q���k�B��l-2  operator * ()
Vector operator*
  (const Vector& V1, const double& f)
{
     Vector doubleemp(V1.Size);
     for(int i=1; i<=V1.Size; i++)
        doubleemp.V[i] = f * V1.V[i];
     return doubleemp;
}
// �w�q������� Display()
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
// �w�q friend ��� InfNorm()
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
// �w�q friend ��� SquareNorm()
double SquareNorm(Vector& V1)
{
  double S;
  S = 0.0;
  for (int i = 1; i <= V1.Size; i++)
    S += V1.V[i]*V1.V[i];
  return S;
}
// �w�q friend ��� FindMaxSite()
int FindMaxSite(Vector& V1)
{
  int Count=1;
  for (int i = 2; i <= V1.Size; i++)
      { if (V1.V[Count] < V1.V[i])  Count=i; }
  return Count;
}

// �w�q friend ��� FindMinSite()
int FindMinSite(Vector& V1)
{
  int Count=1;
  for (int i = 2; i <= V1.Size; i++)
      { if (V1.V[Count] > V1.V[i])  Count=i; }
  return Count;
}
#endif