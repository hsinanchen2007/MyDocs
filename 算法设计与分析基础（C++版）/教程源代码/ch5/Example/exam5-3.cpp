#include<iostream>
#include<vector>
using namespace std;
#define N 5
void dfs(vector<int>&a,int sum,vector<char> &x,int i)
{
	if (i==N)					//����һ��Ҷ�ӽ��(���ܽ�)
	{
		//printf("sum=%d\n",sum); 
		if (sum==5)				//�ҵ�һ�����н�
		{
			printf("  %d",a[0]);	//�����
			for (int j=1;j<N;j++)
			{
				printf("%c",x[j]);
				printf("%d",a[j]);
			}
			printf("=5\n");
		}
	}
	else
	{ 
		x[i]='+';						//λ��i����'+'
		sum+=a[i];						//������
		dfs(a,sum,x,i+1);				//��������
		sum-=a[i];						//����

		x[i]='-';						//λ��i����'-'
		sum-=a[i];						//������
		dfs(a,sum,x,i+1);				//��������
		sum+=a[i];						//����
	}
}
void solve(vector<int>&a)		//����㷨
{
	vector<char> x(a.size());	//���������
	dfs(a,a[0],x,1);			//i��1��ʼ 
}
int main()
{
	vector<int> a={1,2,3,4,5};
	printf("�����\n");
	solve(a); 
	return 0;
}
