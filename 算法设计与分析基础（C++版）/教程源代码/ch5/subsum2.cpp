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
int sum=0;											//�ۼ����������� 
void dfs(int cs,vector<int>&x,int i) 		//�ݹ��㷨
{
	sum++;
	if (i>=n)												//�ҵ�һ��Ҷ�ӽ��
	{	if (cs==t)											//�ҵ�һ�����������Ľ�,���
			disp(x);
	}
	else													//û�е���Ҷ�ӽ��
	{
		if (cs+a[i]<=t)										//���ӽ���֧
		{	x[i]=1;											//ѡȡa[i]
			dfs(cs+a[i],x,i+1);
		}
		x[i]=0;												//��ѡȡ��i������a[i]
		dfs(cs,x,i+1);
	}
}
void subs2()												//����Ӽ�������
{	vector<int> x(n);										//���������
	dfs(0,x,0);												//i��0��ʼ
}
int main()
{
	printf("�Ӽ��������\n"); 
	subs2();
	printf("sum=%d\n",sum);
	return 0;
}
