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
	for (int j=0;j<N;j++)										//初始化lowcost和closest数组
		lowcost[j]=A[v][j];
	U[v]=1;														//源点v加入U
	for (int i=1;i<N;i++)										//找出(n-1)个顶点
	{	mincost=INF;
		int k=-1;
		for (int j=0;j<N;j++)									//在(V-U)中找出离U最近的顶点k
		{	if (U[j]==0 && lowcost[j]<mincost)
			{	mincost=lowcost[j];
				k=j;												//k记录最近顶点的编号
			}
		}
		if(k==-1) break;
		ans+=mincost;											//产生最小生成树的一条边
		U[k]=1;													//顶点k加入U
		for (int j=0;j<N;j++)									//修改数组lowcost和closest
		{	if (U[j]==0 && A[k][j]<lowcost[j])
				lowcost[j]=A[k][j];
		}
	}
	return ans;
}
double distance(int i,int j)			//求顶点i到j的距离 
{
	return sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int main()
{
    //freopen("abc.txt","r",stdin);
    int M;
    cin >> N >> M;
    for(int i=0;i<N;i++)				//输入N个农场的位置 
    	scanf("%d%d",&X[i],&Y[i]);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
            A[i][j]=A[j][i]=distance(i,j);
    }
    for(int i=0;i<N;i++)				//自己到自己置为INF 
		A[i][i]=INF;
    int i,j;
    while(M--)
    {
    	scanf("%d%d",&i,&j);
        A[i-1][j-1]=A[j-1][i-1]=0;		//已有的道路长度置为0 
    }
    printf("%.2f\n",Prim(0));
    return 0;
}
