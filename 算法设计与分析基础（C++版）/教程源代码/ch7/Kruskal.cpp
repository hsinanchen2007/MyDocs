//��³˹�����㷨����С������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 100
//----���鼯��������--------
int parent[MAXN];							//���鼯�洢�ṹ
int rnk[MAXN];								//�洢������(�����ڸ߶�)
void Init(int n)								//���鼯��ʼ��
{	for (int i=0;i<n;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)								//�ݹ��㷨�����鼯�в���x���ĸ����
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);			//·��ѹ��
	return parent[x];
}
void Union(int x,int y)							//���鼯��x��y���������ϵĺϲ�
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)											//x��y����ͬһ���������
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;									//rx�����Ϊry�ĺ���
	else
	{	if (rnk[rx]==rnk[ry])						//����ͬ���ϲ���rx������1
			rnk[rx]++;
		parent[ry]=rx;									//ry�����Ϊrx�ĺ���
	}
}
struct Edge
{
	int u;		//�ߵ���ʼ����
	int v;		//�ߵ���ֹ����
	int w;		//�ߵ�Ȩֵ
	Edge(int u,int v,int w):u(u),v(v),w(w) { }
	bool operator<(const Edge &b) const
	{
		return w<b.w;			//���ڰ�w��������
	}
};

vector<vector<int>> Kruskal(vector<vector<int>>& A)		//Kruskal�㷨
{
	vector<vector<int>> T;								//T�����С��������ÿ����Ϊ{���,�յ�,��Ȩֵ}
	int n=A.size();
	vector<Edge> E;
	for (int i=0;i<n;i++)			//��A�����ǲ��ֲ����ı߼�E
	{
		for (int j=0;j<i;j++)
		{
			if (A[i][j]!=0 && A[i][j]!=INF)
				E.push_back(Edge(i,j,A[i][j]));
		}
	}
	sort(E.begin(),E.end());		//��w��������
	Init(n);						//��ʼ�����鼯
	int k=0;						//k��ʾ��ǰ�����������ı��� 
	int j=0;							//E�бߵ��±�,��ֵΪ0
	while (k<n-1)					//���ɵı���С��n-1ʱѭ��
	{	int u1=E[j].u;
		int v1=E[j].v;				//ȡһ���ߵ�ͷβ������u1��v2
		int sn1=Find(u1);
		int sn2=Find(v1);			//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)			//��Ӹñ߲��ṹ�ɻ�·
		{
			T.push_back({u1,v1,E[j].w});	//������С��������һ���� 
			k++;				//���ɱ�����1
			Union(u1,v1);		//��u1��v1��������ϲ�
		}
		j++;					//ɨ����һ����
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
	printf("Kruskal�㷨�������С������:\n");
	vector<vector<int>> T=Kruskal(A);
	for(int i=0;i<T.size();i++)
		printf("  [%d,%d]:%d",T[i][0],T[i][1],T[i][2]);
	return 0;
}

