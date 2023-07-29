//�ҿ�˹�����㷨����Դ���·��
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> Dijkstra(vector<vector<int>>& A,int v)	//Dijkstra�㷨
{
	int n=A.size();
	vector<int> dist(n);
	vector<bool> S(n,false);
	for (int i=0;i<n;i++)
		dist[i]=A[v][i];			//�����ʼ��
	S[v]=true;							//Դ��v����S��
	for (int i=0;i<n-1;i++)			//ѭ��n-1��
	{	int u=-1;
		int mindis=INF;					//mindis����С·������
		for (int j=0;j<n;j++)			//ѡȡ����s���Ҿ�����С����Ķ���u
		{ 
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		}
		if(u==-1) break; 
		S[u]=true;							//����u����S��
		for (int j=0;j<n;j++)				//�޸Ĳ���S�еĶ���ľ���
		{
			if (!S[j] && A[u][j]!=0 && A[u][j]<INF)
				dist[j]=min(dist[j],dist[u]+A[u][j]);
		}
	}
	return dist;
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
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	printf("ͼ���ڽӾ���:\n");
	dispA(A);						//����ڽӾ���A
	int v=0;
	printf("Dijkstra�㷨��Դ��%d�����·������:\n",v);
	vector<int> ans=Dijkstra(A,v);
	for(int i=0;i<ans.size();i++)
		printf("  Դ��%d��%d�����·������=%d\n",v,i,ans[i]);
	return 0;
}
