//8176K 94MS 
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define INF 1000000000.0
#define MAXN 1010
double A[MAXN][MAXN];
double lowcost[MAXN];
bool U[MAXN];
int X[MAXN],Y[MAXN];
int N;
double Prim(int v)
{
	double ans=0.0;
	for(int i=0;i<N;i++)
		lowcost[i]=INF;
	memset(U,0,sizeof(U));
	double mincost;
	for (int j=0;j<N;j++)										//��ʼ��lowcost��closest����
		lowcost[j]=A[v][j];
	U[v]=1;														//Դ��v����U
	for (int i=1;i<N;i++)										//�ҳ�(n-1)������
	{	mincost=INF;
		int k=-1;
		for (int j=0;j<N;j++)									//��(V-U)���ҳ���U����Ķ���k
		{	if (U[j]==0 && lowcost[j]<mincost)
			{	mincost=lowcost[j];
				k=j;												//k��¼�������ı��
			}
		}
		if(k==-1) break;
		ans+=mincost;											//������С��������һ����
		U[k]=1;													//����k����U
		for (int j=0;j<N;j++)									//�޸�����lowcost��closest
		{	if (U[j]==0 && A[k][j]<lowcost[j])
				lowcost[j]=A[k][j];
		}
	}
	return ans;
}
double distance(int i,int j)			//�󶥵�i��j�ľ��� 
{
	return sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main()
{
    //freopen("abc.txt","r",stdin);
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
    printf("%.2f\n",Prim(0));
    return 0;
}
