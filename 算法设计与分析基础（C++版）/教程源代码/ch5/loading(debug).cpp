#include<iostream>
#include<vector>
using namespace std;
//问题表示
int	n=5,t=10;
int w[]={5,2,6,4,3};					//各集装箱重量,不用下标0的元素
vector<int> bestx;						//存放最优解向量
int bestw=0;							//存放最优解的总重量，初始化为0 
void dfs(int cw,int rw,vector<int>x,int i) //递归算法
{
	if (i>=n)							//找到一个叶子结点
	{
		printf("一个解i=%d,[%d,%d]\n",i,cw,rw); 
		if (cw>bestw)					//找到一个满足条件的更优解
		{	bestw=cw;					//保存更优解
			bestx=x;		
		}
	}
	else								//尚未找完所有集装箱
	{
		rw-=w[i];						//求剩余集装箱的重量和
		if (cw+w[i]<=t)					//左孩子结点剪支：选择满足条件的集装箱
		{		
			x[i]=1;						//选取集装箱i 
			cw+=w[i];					//累计当前所选集装箱的重量和 
			printf("选择左分支i=%d [%d,%d]\n",i+1,cw,rw); 
			dfs(cw,rw,x,i+1);
			cw-=w[i];					//恢复当前所选集装箱的重量和(回溯)
		}
		else
			printf("不选择左分支\n"); 
		if (cw+rw>bestw)				//右孩子结点剪支
		{
			x[i]=0;						//不选择集装箱i
			printf("选择右分支i=%d [%d,%d]\n",i+1,cw,rw); 
			dfs(cw,rw,x,i+1);
		}
		else
			printf("不选择右分支\n"); 
		
		rw+=w[i];						//恢复剩余集装箱的重量和(回溯)
	}
}
void disp()								//输出最优解
{
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  选取第%d个集装箱\n",i);
	printf("总重量=%d\n",bestw);
}
void loading()		//求解简单装载问题
{
	bestx.resize(n);
	vector<int> x(n);
	int rw=0;
	for (int i=0;i<n;i++)
		rw+=w[i];
	dfs(0,rw,x,0);
}
int main()
{
	printf("最优方案\n");
	loading();
	disp();
	return 0;
}
