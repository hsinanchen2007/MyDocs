#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
vector<vector<int>> A={{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
int n=4;
int cnt=0;									//路径条数累计
vector<int> bestx;						//保存最短路径
int bestd=INF;								//保存最短路径长度
void disp(vector<int>&x,int d,int s)		//输出一个解
{
	printf("  第%d条路径: ",++cnt);
	for (int j=0;j<x.size();j++)
		printf("%d->",x[j]);
	printf("%d",s);
	printf(", 路径长度: %d\n",d+A[x[n-1]][s]);
}
void dfs(vector<int>&x,int d,int s,int i)	//回溯法算法
{
	if(i>=n)								//达到一个叶子结点 
	{
		disp(x,d,s);
		if(d+A[x[n-1]][s]<bestd)			//比较求最优解 
		{
			bestd=d+A[x[n-1]][s];			//求TSP长度 
			bestx=x;						//更新bestx 
			bestx.push_back(s);				//末尾添加起始点 
		}
	}
	else
	{
		for(int j=i;j<n;j++)				//试探x[i]走到x[j]的分支
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
	for(int i=0;i<n;i++)						//将非s的顶点添加到x中
		if(i!=s)
			x.push_back(i);
	int d=0;
	dfs(x,d,s,1);
}
int main()
{
	int s=0; 									//指定起点
	printf("求解结果\n");
	TSP1(s);
	printf("  最短路径:  ");					//输出最短路径
	for (int j=0;j<bestx.size();j++)
	{
		if(j==0)
			printf("%d",bestx[j]);
		else
			printf("->%d",bestx[j]);
	}
	printf("\n  路径长度: %d\n",bestd);
	return 0;
}
