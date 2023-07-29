#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
vector<vector<int>> A={{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
int n=4;
int cnt=0;									//·�������ۼ�
vector<int> bestx;						//�������·��
int bestd=INF;								//�������·������
void disp(vector<int>&x,int d,int s)		//���һ����
{
	printf("  ��%d��·��: ",++cnt);
	for (int j=0;j<x.size();j++)
		printf("%d->",x[j]);
	printf("%d",s);
	printf(", ·������: %d\n",d+A[x[n-1]][s]);
}
void dfs(vector<int>&x,int d,int s,int i)	//���ݷ��㷨
{
	if(i>=n)								//�ﵽһ��Ҷ�ӽ�� 
	{
		disp(x,d,s);
		if(d+A[x[n-1]][s]<bestd)			//�Ƚ������Ž� 
		{
			bestd=d+A[x[n-1]][s];			//��TSP���� 
			bestx=x;						//����bestx 
			bestx.push_back(s);				//ĩβ�����ʼ�� 
		}
	}
	else
	{
		for(int j=i;j<n;j++)				//��̽x[i]�ߵ�x[j]�ķ�֧
		{
			if (A[x[i-1]][x[j]]!=0 && A[x[i-1]][x[j]]!=INF)	//��x[i-1]��x[j]�б�
			{
				if(d+A[x[i-1]][x[j]]<bestd)					//��֧
				{
					swap(x[i],x[j]);
					dfs(x,d+A[x[i-1]][x[i]],s,i+1);
					swap(x[i],x[j]);
				}
			}
		}
	}			
}
void TSP1(int s)								//���TSP(��ʼ��Ϊs)
{
	vector<int> x;								//���������
	x.push_back(s);
	for(int i=0;i<n;i++)						//����s�Ķ�����ӵ�x��
		if(i!=s)
			x.push_back(i);
	int d=0;
	dfs(x,d,s,1);
}
int main()
{
	int s=0; 									//ָ�����
	printf("�����\n");
	TSP1(s);
	printf("  ���·��:  ");					//������·��
	for (int j=0;j<bestx.size();j++)
	{
		if(j==0)
			printf("%d",bestx[j]);
		else
			printf("->%d",bestx[j]);
	}
	printf("\n  ·������: %d\n",bestd);
	return 0;
}
