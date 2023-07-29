//����ķ�㷨����С������
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int>> Prim(vector<vector<int>>& A,int v)
{
	vector<vector<int>> T;				//�����С������
	int n=A.size();
	vector<int> lowcost(n,INF);
	vector<int> U(n,0);
	vector<int> closest(n);
	int mincost;
	for (int j=0;j<n;j++)				//����ʼ��lowcost��closest����
	{	lowcost[j]=A[v][j];
		closest[j]=v;
	}
	U[v]=1;								//Դ�����U 
	for (int i=1;i<n;i++)				//�ҳ�(n-1)������
	{	mincost=INF;
		int k=-1; 
		for (int j=0;j<n;j++)			//��(V-U)���ҳ���U����Ķ���k
		{
			if (U[j]==0 && lowcost[j]<mincost)
			{	mincost=lowcost[j];
				k=j;					//k��¼�������ı��
			}
		}
		T.push_back({closest[k],k,mincost});	//������С��������һ���� 
		U[k]=1;									//����k����U 
		for (int j=0;j<n;j++)					//�޸�����lowcost��closest
		{
			if (U[j]==0 && A[k][j]<lowcost[j])
			{
				lowcost[j]=A[k][j];
				closest[j]=k;
			}
		}
	}
	return T;
}

void dispA(vector<vector<int>>& A)			//���ͼ���ڽӾ���
{	for (int i=0;i<A.size();i++)
	{	for (int j=0;j<A.size();j++)
			if (A[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",A[i][j]);
		printf("\n");
	}
}

int main()
{
	vector<vector<int>> A={			//һ����Ȩ����ͼ
		{0,  6,  INF,INF,INF,1,  INF},
		{6,  0,  4,  INF,INF,INF,3},
		{INF,4,  0,  2,  INF,INF,INF},
		{INF,INF,2,  0,  6,  INF,5},
		{INF,INF,INF,6,  0,  8,  7},
		{1,  INF,INF,INF,8,  0,  INF},
		{INF,3,  INF,5,  7,  INF,0}};
	printf("ͼ���ڽӾ���:\n");
	dispA(A);						//����ڽӾ���A
	printf("Prim�㷨�������С������:\n");
	vector<vector<int>> T=Prim(A,0);
	for(int i=0;i<T.size();i++)
		printf("  [%d,%d]:%d",T[i][0],T[i][1],T[i][2]);
	return 0;
}
