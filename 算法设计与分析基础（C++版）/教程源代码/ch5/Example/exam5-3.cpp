#include<iostream>
#include<vector>
using namespace std;
#define N 5
void dfs(vector<int>&a,int sum,vector<char> &x,int i)
{
	if (i==N)					//到达一个叶子结点(可能解)
	{
		//printf("sum=%d\n",sum); 
		if (sum==5)				//找到一个可行解
		{
			printf("  %d",a[0]);	//输出解
			for (int j=1;j<N;j++)
			{
				printf("%c",x[j]);
				printf("%d",a[j]);
			}
			printf("=5\n");
		}
	}
	else
	{ 
		x[i]='+';						//位置i插入'+'
		sum+=a[i];						//计算结果
		dfs(a,sum,x,i+1);				//继续搜索
		sum-=a[i];						//回溯

		x[i]='-';						//位置i插入'-'
		sum-=a[i];						//计算结果
		dfs(a,sum,x,i+1);				//继续搜索
		sum+=a[i];						//回溯
	}
}
void solve(vector<int>&a)		//求解算法
{
	vector<char> x(a.size());	//定义解向量
	dfs(a,a[0],x,1);			//i从1开始 
}
int main()
{
	vector<int> a={1,2,3,4,5};
	printf("求解结果\n");
	solve(a); 
	return 0;
}
