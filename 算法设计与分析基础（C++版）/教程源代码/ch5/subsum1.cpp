#include<iostream>
#include<vector>
using namespace std;
//int n=4,t=31;
//vector<int> a={11,13,24,7};							//�����������
int n=4,t=8;
vector<int> a={3,1,5,2};							//�����������
int cnt=0;													//�ۼƽ����
void disp(vector<int>&x)								//���һ����
{	printf("  ��%d����  ",++cnt);
	printf("ѡȡ����Ϊ");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d ",a[i]);
	printf("\n");
}
void dfs(int cs,vector<int>&x,int i) 		//�ݹ��㷨
{
	if (i>=n)											//����һ��Ҷ�ӽ��
	{	if (cs==t)										//�ҵ�һ�����������Ľ�,���
			disp(x);
	}
	else												//û�е���Ҷ�ӽ��
	{	x[i]=1;											//ѡȡ����a[i]
		dfs(cs+a[i],x,i+1);
		x[i]=0;											//��ѡȡ����a[i]
		dfs(cs,x,i+1);
	}
}
void subs1()											//����Ӽ�������
{	vector<int> x(n);									//������
	dfs(0,x,0);											//i��0��ʼ
}
int main()
{
	printf("�Ӽ��������\n"); 
	subs1();
	return 0;
}
