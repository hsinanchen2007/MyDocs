#include<iostream>
#include <vector>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f					//定义∞
#define MAXN 21							//最大的n 
int n=4;
int c[MAXN][MAXN]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
vector<int> bestx;										//最优解向量
int bestc=INF;											//最优解的成本,，初始置为∞
bool used[MAXN];										//used[j]表示任务j是否已经分配人员
int bound(vector<int>&x,int cost,int i)				//求下界算法
{	int minsum=0;
	for (int i1=i;i1<n;i1++)						//求c[i..n-1]行中最小元素和
	{	int minc=INF;
		for (int j1=0;j1<n;j1++)
			if (used[x[j1]]==false && c[i1][x[j1]]<minc)
				minc=c[i1][x[j1]];
		minsum+=minc;
	}
	return cost+minsum;
}
int sum=0;
void dfs(vector<int>&x,int cost,int i)			//递归回溯算法
{	sum++;
	if (i>=n)													//到达叶子结点
	{	if (cost<bestc)										//比较求最优解
		{	bestc=cost;
			bestx=x;
		}
	}
	else														//没有到达叶子结点
	{	for (int j=0;j<n;j++)							//为人员i试探任务x[j]
		{	if (used[x[j]]) continue;						//若任务x[j]已经分配，则跳过
			used[x[j]]=true;
			cost+=c[i][x[j]];
			swap(x[i],x[j]);								//为人员i分配任务x[j] 
			if(bound(x,cost,i+1)<bestc)					//剪支
				dfs(x,cost,i+1);							//继续为人员i+1分配任务
			swap(x[i],x[j]);
			cost-=c[i][x[j]];								//cost回溯
			used[x[j]]=false;								//used回溯
		}
	}
}
void alloction()											//基于排列树的递归回溯算法
{	//bestx.resize(n);
	memset(used,false,sizeof(used));
	vector<int> x;											//当前解向量
	for(int i=0;i<n;i++)								//将x[1..n]分别设置为1到n值
		x.push_back(i);
	int cost=0;												//当前解的成本
	dfs(x,cost,0);											//从人员1开始
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






