#include<iostream>
#include<vector>
using namespace std;
vector<int> x;					//解向量,全局变量 
void disp(vector<int>&a)		//输出一个解
{
	printf("   {");
	for (int i=0;i<x.size();i++)
		if (x[i]==1)
			printf("%d",a[i]);
	printf("}");
}
void dfs(vector<int>&a,int i)	//递归回溯算法
{
	if (i>=a.size())
		disp(a);
	else
	{
		x[i]=1;
		dfs(a,i+1);				//选择a[i]
		x[i]=0;
		dfs(a,i+1);				//不选择a[i]
	}
}
void subsets(vector<int>&a)		//求a的幂集
{
	int n=a.size();
	x.resize(n);				//指定x的长度为n
	dfs(a,0);
} 
int main()
{
	vector<int> a{1,2,3};
	vector<int> x(a.size(),0);		//解向量，初始化为0 
	printf("求解结果\n");
	subsets(a);
	printf("\n");
	return 0; 
}
