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
void dfs(int cs,int rs,vector<int>&x,int i) 		//递归算法
{	//cs为考虑第i个整数时选取的整数和，rs为剩余整数和
	sum++;
	printf("[%d,%d]\n",cs,rs);
	if (i>=n)												//找到一个叶子结点
	{	if (cs==t)											//找到一个满足条件的解,输出
			disp(x);
	}
	else													//没有到达叶子结点
	{
		rs-=a[i];											//求剩余的整数和
		if (cs+a[i]<=t)										//左孩子结点剪支
		{	x[i]=1;											//选取整数a[i]
			dfs(cs+a[i],rs,x,i+1);
		}
		else 
			printf("左剪支[%d,%d]\n",cs+a[i],rs);
		
		if (cs+rs>=t)										//右孩子结点剪支
		{	x[i]=0;											//不选取整数a[i]
			dfs(cs,rs,x,i+1);
		}
		else
			printf("右剪支[%d,%d]\n",cs,rs);
		rs+=a[i];											//恢复剩余整数和
	}
}
void subs3()													//求解子集和问题
{	vector<int> x(n);										//解向量
	int rs=0;												//表示所有整数和
	for (int j=0;j<n;j++)									//求rs
		rs+=a[j];
	dfs(0,rs,x,0);											//i从0开始	
}
int main()
{
	printf("子集和问题解\n"); 
	subs3();
	printf("sum=%d\n",sum);
	return 0;
}
