//188K 0MS 
#include<iostream>
#include<cstring>
using namespace std;
struct Matrix								//表示2*2矩阵类型
{
	int data[2][2];
	Matrix() {}									//默认构造函数 
	Matrix(int x00,int x01,int x10,int x11)		//构造函数 
	{
		data[0][0]=x00;
		data[0][1]=x01;
		data[1][0]=x10;
		data[1][1]=x11;
	}
};
Matrix multiply(Matrix& A,Matrix& B)		//返回矩阵A和B相乘的结果
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
Matrix quick_pow(Matrix& A,int n)			//求A^n的快速幂算法
{	Matrix ans(1,0,0,1);					//置ans为单位矩阵
	while(n!=0)
	{	if (n & 1)
			ans=multiply(ans,A);
		A=multiply(A,A);
		n>>=1;								//n右移1位
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
		Matrix A(1,1,1,0);				//先置A为初始矩阵
		Matrix ans=quick_pow(A,n);				//取ans左上角元素
		cout << ans.data[0][1]%10000 << endl;
	}
	return 0;
}

