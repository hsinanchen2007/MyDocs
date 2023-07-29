//188K 0MS 
#include<iostream>
#include<cstring>
using namespace std;
struct Matrix								//��ʾ2*2��������
{
	int data[2][2];
	Matrix() {}									//Ĭ�Ϲ��캯�� 
	Matrix(int x00,int x01,int x10,int x11)		//���캯�� 
	{
		data[0][0]=x00;
		data[0][1]=x01;
		data[1][0]=x10;
		data[1][1]=x11;
	}
};
Matrix multiply(Matrix& A,Matrix& B)		//���ؾ���A��B��˵Ľ��
{	Matrix C;
	memset(C.data,0,sizeof(C.data));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
			{	C.data[i][j]+=A.data[i][k]*B.data[k][j];
				C.data[i][j]%=10000;
			}
	return C;
}
Matrix quick_pow(Matrix& A,int n)			//��A^n�Ŀ������㷨
{	Matrix ans(1,0,0,1);					//��ansΪ��λ����
	while(n!=0)
	{	if (n & 1)
			ans=multiply(ans,A);
		A=multiply(A,A);
		n>>=1;								//n����1λ
	}
	return ans;
}
int main()
{	int n;
	while(cin >> n && n!=-1)
	{	if(n==0)
		{	cout << 0 << endl;
			continue;
		}
		Matrix A(1,1,1,0);				//����AΪ��ʼ����
		Matrix ans=quick_pow(A,n);				//ȡans���Ͻ�Ԫ��
		cout << ans.data[0][1]%10000 << endl;
	}
	return 0;
}

