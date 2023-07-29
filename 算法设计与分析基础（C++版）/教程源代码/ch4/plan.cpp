#include<iostream>
using namespace std;
#define MAX 101
//问题表示
int k;
//求解结果表示
int a[MAX][MAX];						//存放比赛日程表（行列下标为0的元素不用）
void Plan11(int k)						//被Plan1调用
{
	if(k==1)							//求解2个选手比赛日程
	{	a[1][1]=1; a[1][2]=2;
		a[2][1]=2; a[2][2]=1;
	}
	else
	{
		Plan11(k-1);
		int n=1<<(k-1);
		for (int i=n+1;i<=2*n;i++ )			//填左下角元素
			for (int j=1;j<=n; j++)
				a[i][j]=a[i-n][j]+n; 		//左下角元素和左上角元素的对应关系
		for (int i=1;i<=n;i++)				//填右上角元素
			for (int j=n+1;j<=2*n;j++)
				a[i][j]=a[i+n][(j+n)%(2*n)];
		for (int i=n+1;i<=2*n;i++)			//填右下角元素
			for (int j=n+1;j<=2*n; j++)
				a[i][j]=a[i-n][j-n];
    }
}
void Plan1(int k)						//递归算法：求解循环日程安排问题 
{
	Plan11(k);
}

void Plan2(int k)						//迭代算法：求解循环日程安排问题 
{
	int n=2;							//n从2^1=2开始
	a[1][1]=1; a[1][2]=2;   			//求解2个选手比赛日程,得到左上角元素
	a[2][1]=2; a[2][2]=1;
	for (int t=1;t<k;t++)					//迭代处理,依次求2^2，…,2^k个选手的安排 
	{
		int tmp=n;								//tmp=2^t
		n=n*2; 									//n=2^(t+1)
		for (int i=tmp+1;i<=n;i++ )			//填左下角元素
			for (int j=1;j<=tmp; j++)
				a[i][j]=a[i-tmp][j]+tmp; 	//左下角元素和左上角元素的对应关系
		for (int i=1;i<=tmp; i++)				//填右上角元素
			for (int j=tmp+1;j<=n; j++)
				a[i][j]=a[i+tmp][(j+tmp)% n];
		for (int i=tmp+1; i<=n; i++)			//填右下角元素
			for (int j=tmp+1;j<=n; j++)
				a[i][j]=a[i-tmp][j-tmp];
    }
}

int main()
{
	k=3;
	int n=1<<k;							//n等于2的k次方即n=2^k
	printf("n=%d\n",n);
	printf("递归算法:\n"); 
	Plan1(k);							//产生n个选手的比赛日程表
	for(int i=1; i<=n; i++)				//输出比赛日程表
	{	for(int j=1; j<=n; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	printf("迭代算法:\n"); 
	Plan2(k);							//产生n个选手的比赛日程表
	for(int i=1; i<=n; i++)				//输出比赛日程表
	{	for(int j=1; j<=n; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
