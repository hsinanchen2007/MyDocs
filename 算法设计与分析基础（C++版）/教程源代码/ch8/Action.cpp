#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 101
//问题表示
struct Action						//活动的类型 
{
	int b;							//开始时间
	int e;							//结束时间
	int length;						//活动的执行时间
    bool operator < (const Action t) const
    {
		return e<t.e;				//按结束时间递增排序
    }
};
int n=4;							//活动个数
//Action A[MAXN]={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};	//存放活动
//Action A[MAXN]={{1,6},{6,8},{1,10},{8,12}};	//存放活动
Action A[MAXN]={{4,6},{6,8},{1,10},{6,12}};	//存放活动
//求解结果表示
int dp[MAXN];					//动态规划数组
int pre[MAXN];					//pre[i]存放前驱活动序号

int plan()						//求dp
{
	memset(dp,0,sizeof(dp));	//dp数组初始化
	sort(A,A+n);				//排序
	dp[0]=A[0].length;
	pre[0]=-2;					//A[0]没有前驱活动
	for (int i=1;i<n;i++)
	{
		int j=i-1;
		while(j>=0 && A[j].e>A[i].b)
			j--;				//在A[0..i-1]找与A[i]兼容的最晚活动A[j]
		if(j==-1)				//A[i]前面没有兼容活动
		{
			dp[i]=A[i].length;
			pre[i]=-2;			//没有前驱活动
		}
		else					//A[i]前面有最晚兼容活动A[j]
		{
			//dp[i]=max(dp[i-1],dp[j]+A[i].length)
			if(i==3)
				printf("j=%d,dp[i-1]=%d,dp[j]+A[i].length=%d\n",j,dp[i-1],dp[j]+A[i].length);
			if (dp[i-1]>dp[j]+A[i].length)
			{
				dp[i]=dp[i-1];
				pre[i]=-1;		//不选择A[i]
			}
			else
			{
				dp[i]=dp[j]+A[i].length;
				pre[i]=j;					//选中活动i,前驱活动为A[j] 
			}
		}
	}
	return dp[n-1];
}

void disp()					//输出计算结果 
{
	printf("i:\t");
	for(int i=0;i<n;i++)
		printf("%3d",i);
	printf("\n"); 


	printf("b:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].b);
	printf("\n"); 

	printf("e:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].e);
	printf("\n"); 

	printf("l:\t");
	for(int i=0;i<n;i++)
		printf("%3d",A[i].length);
	printf("\n"); 

		
	printf("\npre[i]:\t");
	for(int i=0;i<n;i++)
		printf("%3d",pre[i]);
	printf("\n"); 

	printf("\ndp[i]:\t");
	for(int i=0;i<n;i++)
		printf("%3d",dp[i]);
	printf("\n"); 
	

}
void getx()						//求一个最优安排方案
{	vector<int> x;				//存放一个方案 
	int i=n-1;					//从n-1开始
	while(true)
	{
		if (i==-2)				//A[i]没有前驱活动
			break;
		if (pre[i]==-1)			//不选择A[i]
			i--;
		else					//选择A[i]
		{
			x.push_back(i);
			i=pre[i];
		}
	}
	printf("x:");
	for(int i=0;i<x.size();i++)
		printf("%d:[%d,%d] ",x[i],A[x[i]].b,A[x[i]].e);
	printf("\n");

	printf("    选择的活动: ");
	for (int i=x.size()-1;i>=0;i--)
		printf("%d[%d,%d] ",x[i],A[x[i]].b,A[x[i]].e);
	printf("\n");
	printf("    兼容活动的总时间: %d\n",dp[n-1]);
}
int main()
{
	freopen("xyz.txt","w",stdout);
	for (int i=0;i<n;i++)		//求活动的长度
		A[i].length=A[i].e-A[i].b;
	printf("求解结果=%d\n",plan());
	getx();
	disp();
    return 0;
}
