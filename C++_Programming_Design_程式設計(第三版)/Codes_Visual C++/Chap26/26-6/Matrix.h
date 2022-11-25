// Matrix.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// ���{�����v�ݩ� �iģ��
// �ϥήɥ����n��.
// --------------------------------------
#ifndef Matrix_H
#define Matrix_H
#include <iomanip>
using std::cout;
using std::endl;
using std::ios;
using std::setw;
// ------ �ŧi Matrix ���O ----------------
class Matrix
{
  // �ŧi friend ���
  friend Vector SumVector(Matrix&);
  private:
    int M, N;
    double** A;
    void Create(int, int);
  public:
    // �ŧi�غc���
    Matrix(int, int);
    Matrix(int, int, const double*);
    Matrix(Matrix&);
    // �ŧi�Ѻc���
    ~Matrix();
    // �ŧi�B��l�����������
    Matrix operator=(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator*(const Matrix&);
    double* operator[](int i)
           {return A[i];}
    void SetCol(int, Vector&);
    Vector PickCol(int);
    void Display();
};
// ------ �w�q Matrix ���O ----------------
// �w�q private ������� Create()
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
// �w�q�غc���-1
Matrix::Matrix(int Row, int Col)
{
  Create(Row,Col);
  return;
}
// �w�q�غc���-2
Matrix::Matrix
  (int Row, int Col, const double* V)
{
  Create(Row,Col);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=V[(i-1)*Col+(j-1)];
  return;
}
// �w�q�Ѻc���
Matrix::~Matrix()
{ delete [] A[0];
  delete [] A;
}
// �w�q�ƻs�غc���
Matrix::Matrix(Matrix& OldM)
{
  Create(OldM.M, OldM.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=OldM.A[i][j];
  return;
}
// �w�q�����B��l operator = ()
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
// �w�q�[�k�B��l operator + ()
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
// �w�q���k�B��l  operator * ()
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
// �w�q������� Display()
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
// �w�q������� PickCol()
Vector Matrix::PickCol(int I)
{
  Vector V(M);
  for (int i=1; i<= M; i++)
       V[i]= A[i][I];
  return V;
}
// �w�q������� SetCol()
void Matrix::SetCol(int j, Vector& V1)
{
  for (int i=1; i<= M; i++)
     A[i][j]= V1[i];
  return;
}
// �w�q friend ��� SumVector()
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