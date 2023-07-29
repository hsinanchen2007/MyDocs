//AC:144K 172MS 
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd;									//保存最小时间
void dfs(vector<int>&x,int d,int s,int i)	//回溯法算法
{
	if(i>n)								//达到一个叶子结点 
	{
		if(d+A[x[n]][s]<bestd)			//比较求最优解 
			bestd=d+A[x[n]][s];			//求TSP长度 
	}
	else
	{
		for(int j=i;j<=n;j++)				//试探x[i]走到x[j]的分支
		{
			if (A[x[i-1]][x[j]]!=0 && A[x[i-1]][x[j]]!=INF)	//若x[i-1]到x[j]有边
			{
				if(d+A[x[i-1]][x[j]]<bestd)					//剪支
				{
					swap(x[i],x[j]);
					dfs(x,d+A[x[i-1]][x[i]],s,i+1);
					swap(x[i],x[j]);
				}
			}
		}
	}			
}
void TSP1(int s)								//求解TSP(起始点为s)
{
	vector<int> x;								//定义解向量
	x.push_back(s);
	for(int i=0;i<=n;i++)						//将非s的顶点添加到x中
		if(i!=s)
			x.push_back(i);
	int d=0;
	bestd=INF;
	dfs(x,d,s,1);
}
void Floyd()						//计算最短路径距离
{
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];
}
int main()
{
	//freopen("abc.txt","r",stdin);
    while(scanf("%d",&n)==1 &&n)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//计算最短路径距离
        TSP1(0);
        printf("%d\n",bestd);
    }
    return 0;
} 


