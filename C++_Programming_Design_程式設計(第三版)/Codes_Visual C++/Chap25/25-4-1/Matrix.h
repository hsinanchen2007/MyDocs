// Matrix.h
#ifndef Matrix_H
#define Matrix_H
#include <iostream>
#include <iomanip>
using namespace std;
// ------  Matrix 摸 ----------------
class Matrix
{
  //  friend ㄧ计
  friend void Randomize(Matrix&);
  friend Vector SumVector(Matrix&);
  private:
    int M, N;
    double** A;
    void Create(int, int);
  public:
    // 篶ㄧ计
    Matrix(int, int);
    Matrix(int, int, const double*);
    Matrix(Matrix&);
    // 秆篶ㄧ计
    ~Matrix();
    // 笲衡更Θㄧ计
    Matrix operator=(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator*(const Matrix&);
    double* operator[](int i)
           {return A[i];}
    void SetCol(int, Vector&);
    Vector PickCol(int);
    void Display();
};
// ------ ﹚竡 Matrix 摸 ----------------
// ﹚竡 private Θㄧ计 Create()
void Matrix::Create(int Row, int Col)
{
   if((Row<1)||(Col<1))
      {M = 0; N=0; A = 0;}
   else
      {   M = Row;
          N = Col;
          A = new double* [M+1];
          A[0]= new double[M*N+1];
          A[1]= A[0];
          for(int i=2; i<= M; i++)
             A[i]=A[i-1]+N;
      }
}
// ﹚竡篶ㄧ计-1
Matrix::Matrix(int Row, int Col)
{
  Create(Row,Col);
  return;
}
// ﹚竡篶ㄧ计-2
Matrix::Matrix
  (int Row, int Col, const double* V)
{
  Create(Row,Col);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=V[(i-1)*Col+(j-1)];
  return;
}
// ﹚竡秆篶ㄧ计
Matrix::~Matrix()
{ delete [] A[0];
  delete [] A;
}
// ﹚竡狡籹篶ㄧ计
Matrix::Matrix(Matrix& OldM)
{
  Create(OldM.M, OldM.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=OldM.A[i][j];
  return;
}
// ﹚竡笲衡 operator = ()
Matrix
Matrix::operator=(const Matrix& M2)
{
  if ((M!=M2.M)||(N!=M2.N))
    Create(M2.M, M2.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
      A[i][j]=M2.A[i][j];
  return *this;
}
// ﹚竡猭笲衡 operator + ()
Matrix
Matrix::operator+(const Matrix& M2)
{
  Check((M!=M2.M)||(N!=M2.N),
   "Addition error (Not of the same size)");
  Matrix temp(M,N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
           temp.A[i][j]=A[i][j]+M2.A[i][j];
  return temp;
}
// ﹚竡猭笲衡  operator * ()
Matrix
Matrix::operator*(const Matrix& M2)
{
  Check(N!=M2.M,
        "Multiplication error!(size)");
  Matrix temp(M,M2.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= M2.N ; j++)
      {
       temp.A[i][j]=0.0;
       for(int k = 1; k <= N ; k++)
         temp.A[i][j]+=A[i][k]*M2.A[k][j];
      }
  return temp;
}
// ﹚竡Θㄧ计 Display()
void Matrix::Display()
{
    cout << setiosflags(ios::right)
         << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << std::setprecision(4);
    for (int i = 1; i <= M; i++)
    {
      for(int j = 1; j <= N ; j++)
        cout << setw(10)
             << A[i][j] << " " ;
      cout << endl;
    }
    return;
}
// ﹚竡Θㄧ计 PickCol()
Vector Matrix::PickCol(int I)
{
  Vector V(M);
  for (int i=1; i<= M; i++)
       V[i]= A[i][I];
  return V;
}
// ﹚竡Θㄧ计 SetCol()
void Matrix::SetCol(int j, Vector& V1)
{
  for (int i=1; i<= M; i++)
     A[i][j]= V1[i];
  return;
}
// ﹚竡 friend ㄧ计 Randomize()
void Randomize(Matrix& M1)
{
  for (int i=1; i<= M1.M; i++)
    for (int j=1; j<= M1.N; j++)
      M1.A[i][j] = (Rand()*2.0-1.0)*Range;
  return;
}
// ﹚竡 friend ㄧ计 SumVector()
Vector SumVector(Matrix& M1)
{
  Vector Temp(M1.M);
  for (int i=1; i<= M1.M; i++)
   {
    Temp[i] =0.0;
    for (int j=1; j<= M1.N; j++)
     Temp[i]+=M1.A[i][j];
   }
  return Temp;
}
#endif