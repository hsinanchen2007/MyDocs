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
int sum=0;									//累计解个数 
void dfs(vector<int>&x,int cost,int i)					//为第i个人员分配任务
{
	sum++; 
	if (i>=n)					//到达叶子结点
	{
		if (cost<bestc)		//比较求最优解
		{
			bestc=cost;
			bestx=x;
		}
	}
	else
	{
		for (int j=0;j<n;j++)			//为人员i试探任务j:1到n
		{
			if (!used[j])				//若任务j还没有分配
			{
				used[j]=true;
				x[i]=j;					//任务j分配给人员i
				cost+=c[i][j];
				dfs(x,cost,i+1);			//为人员i+1分配任务
				used[j]=false;				//回退
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
	printf("sum=%d\n",sum);
}
int main()
{
	memset(used,0,sizeof(used));	//used初始化为false
	alloction();							
	printf("最优方案:\n");
	for (int k=0;k<n;k++)
		printf("   第%d个人安排任务%d\n",k,bestx[k]);
	printf("   总成本=%d\n",bestc);
	return 0;
}






