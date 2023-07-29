#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 30					//最多顶点个数 
int n;
vector<int> A[MAXN];			//邻接表 
int cnt;						//全局变量，累计解个数
int x[MAXN];					//全局变量，x[i]表示顶点i的着色
bool judge(int i,int j)				//判断顶点i是否可以染上颜色j 
{
    for(int k=0;k<A[i].size();k++)
    {
        if(x[A[i][k]]==j)		//存在相同颜色的顶点 
            return false;
    }
    return true;
}
void dfs(int m,int i)			//递归回溯算法 
{
    if(i>=n)					//达到一个叶子结点 
        cnt++;
    else
    {
    	for(int j=0;j<m;j++)
    	{
        	x[i]=j;				//置顶点i为颜色j 
        	if(judge(i,j))	//若顶点i可以染上颜色j
            	dfs(m,i+1);
            x[i]=-1; 			//回溯 
    	}
	}
}
int Colors(int m)				//求图的m着色问题
{
	cnt=0;
	memset(x,0xff,sizeof(x));		//所以元素初始化为-1 
	dfs(m,0);						//从顶点0开始搜索
	return cnt;
}
int main()
{
	n=4;
	A[0]={1,2,3};
	A[1]={0};
	A[2]={0,3};
	A[3]={0,2};
	int m=3;
	printf("共有%d种着色方案\n",Colors(m));
	return 0;
}


