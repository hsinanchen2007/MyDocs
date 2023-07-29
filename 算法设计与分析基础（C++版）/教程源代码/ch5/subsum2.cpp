#include<iostream>
#include<vector>
using namespace std;
//int n=4,t=31;
//vector<int> a={11,13,24,7};							//存放所有整数
int n=4,t=8;
vector<int> a={3,1,5,2};							//存放所有整数
int cnt=0;													//累计解个数
void disp(vector<int>&x)								//输出一个解
{	printf("  第%d个解  ",++cnt);
	printf("选取的数为");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d ",a[i]);
	printf("\n");
}
int sum=0;											//累计搜索结点个数 
void dfs(int cs,vector<int>&x,int i) 		//递归算法
{
	sum++;
	if (i>=n)												//找到一个叶子结点
	{	if (cs==t)											//找到一个满足条件的解,输出
			disp(x);
	}
	else													//没有到达叶子结点
	{
		if (cs+a[i]<=t)										//左孩子结点剪支
		{	x[i]=1;											//选取a[i]
			dfs(cs+a[i],x,i+1);
		}
		x[i]=0;												//不选取第i个整数a[i]
		dfs(cs,x,i+1);
	}
}
void subs2()												//求解子集和问题
{	vector<int> x(n);										//定义解向量
	dfs(0,x,0);												//i从0开始
}
int main()
{
	printf("子集和问题解\n"); 
	subs2();
	printf("sum=%d\n",sum);
	return 0;
}
