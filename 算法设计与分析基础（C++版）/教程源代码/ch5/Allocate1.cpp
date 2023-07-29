#include<iostream>
#include <vector>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f					//定义∞
#define MAXN 21							//最大的n 
int n=4;
int c[MAXN][MAXN]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
vector<int> bestx;				//最优解向量 
int bestc=INF;					//最优解的成本
bool used[MAXN];				//used[j]表示任务j是否已经分配人员
int bound(int cost,int i)									//求下界算法
{	int minsum=0;
	for (int i1=i;i1<n;i1++)						//求c[i..n-1]行中最小元素和
	{	int minc=INF;										//置为∞
		for (int j1=0;j1<n;j1++)
			if (used[j1]==false && c[i1][j1]<minc)
				minc=c[i1][j1];
		minsum+=minc;
	}
	return cost+minsum;
}
int sum=0;
void dfs(vector<int>&x,int cost,int i)				//为第i个人员分配任务
{
	sum++;
	if (i>=n)													//到达叶子结点
	{	if (cost<bestc)										//比较求最优解
		{	bestc=cost;
			bestx=x;
		}
	}
	else														//没有到达叶子结点
	{	for (int j=0;j<n;j++)								//为人员i试探任务j
		{	if (used[j]==0)								//若任务j还没有分配
			{	used[j]=true;
				x[i]=j;										//任务j分配给人员i
				cost+=c[i][j];
				if(bound(cost,i+1)<bestc)					//剪支
					dfs(x,cost,i+1);						//继续为人员i+1分配任务
				used[j]=false;								//回溯
				x[i]=0;
				cost-=c[i][j];
			}
		}
	}
}
void alloction()
{
	memset(used,false,sizeof(used));
	vector<int> x(n,0);						//临时解
	int cost=0;							//临时解的成本
	dfs(x,cost,0);							//从人员0开始
}
int main()
{
	memset(used,0,sizeof(used));	//used初始化为false
	alloction();	
	printf("sum=%d\n",sum);						
	printf("最优方案:\n");
	for (int k=0;k<n;k++)
		printf("   第%d个人安排任务%d\n",k,bestx[k]);
	printf("   总成本=%d\n",bestc);
	return 0;
}






