//8176K 94MS 
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 1000000000.0
#define MAXN 1010
double A[MAXN][MAXN];
double lowcost[MAXN];
bool U[MAXN];
int X[MAXN],Y[MAXN];
int N;
int parent[MAXN];											//���鼯�洢�ṹ
int rnk[MAXN];												//�洢������(�����ڸ߶�)
void Init()												//���鼯��ʼ��
{	for (int i=0;i<N;i++)
	{	parent[i]=i;
		rnk[i]=0;
	}
}
int Find(int x)													//�ݹ��㷨�����鼯�в���x���ĸ����
{	if (x!=parent[x])
		parent[x]=Find(parent[x]);						//·��ѹ��
	return parent[x];
}
void Union(int x,int y)										//���鼯��x��y���������ϵĺϲ�
{	int rx=Find(x);
	int ry=Find(y);
	if (rx==ry)													//x��y����ͬһ���������
		return;
	if (rnk[rx]<rnk[ry])
		parent[rx]=ry;											//rx�����Ϊry�ĺ���
	else
	{	if (rnk[rx]==rnk[ry])								//����ͬ���ϲ���rx������1
			rnk[rx]++;
		parent[ry]=rx;											//ry�����Ϊrx�ĺ���
	}
}
struct Edge														//������
{	int u;															//�ߵ����
	int v;															//�ߵĶ���
	double w;															//�ߵ�Ȩֵ
	Edge(int u,int v,double w):u(u),v(v),w(w) { }
	bool operator<(const Edge &b) const
	{
		return w<b.w;											//���ڰ�w��������
	}
};
double Kruskal()							//Kruskal�㷨
{
	double ans=0.0;
	vector<Edge> E;
	for (int i=0;i<N;i++)										//��A�����ǲ��ֲ����ı߼�E
	{	for (int j=i+1;j<N;j++)
			E.push_back(Edge(i,j,A[i][j]));
	}
	sort(E.begin(),E.end());								//��w��������
	Init();														//��ʼ�����鼯
	int k=0;														//k��ʾ�������ı���
	int j=0;														//E�бߵ��±�,��ֵΪ0
	while (k<N-1)												//���ɵı���С��n-1ʱѭ��
	{	int u1=E[j].u;
		int v1=E[j].v;											//ȡһ���ߵ�ͷβ������u1��v2
		int sn1=Find(u1);
		int sn2=Find(v1);									//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)											//��Ӹñ߲��ṹ�ɻ�·
		{	ans+=E[j].w;								//������С��������һ���� 
			k++;													//���ɱ�����1
			Union(u1,v1);										//��u1��v1���������ϲ�
		}
		j++;														//������һ����
	}
	return ans;
}
double distance(int i,int j)			//�󶥵�i��j�ľ��� 
{
	return sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main()
{
    freopen("abc.txt","r",stdin);
    int M;
    cin >> N >> M;
    for(int i=0;i<N;i++)				//����N��ũ����λ�� 
    	scanf("%d%d",&X[i],&Y[i]);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
            A[i][j]=A[j][i]=distance(i,j);
    }
    for(int i=0;i<N;i++)				//�Լ����Լ���ΪINF 
		A[i][i]=INF;
    int i,j;
    while(M--)
    {
    	scanf("%d%d",&i,&j);
        A[i-1][j-1]=A[j-1][i-1]=0;		//���еĵ�·������Ϊ0 
    }
    printf("%.2f\n",Kruskal());
    return 0;
}
