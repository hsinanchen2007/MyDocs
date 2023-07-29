//求解背包问题的算法
#include<iostream>
#include<vector> 
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 51
//问题表示
int n=5;
double W=100;					//限重
struct Goods
{
	double w;
	double v;
	bool operator<(const Goods &b) const
	{
		return v/w>b.v/b.w;			//按单位重量价值减排序
	}
};
vector<Goods> A={{10,20},{20,30},{30,66},{40,40},{50,60}};
//求解结果表示
double bestv;						//最大价值
double x[MAXN];
void Knap()							//求解背包问题并返回总价值
{
	bestv=0;						//bestv初始化为0
	double rw=W;			//背包中能装入的余下重量
	memset(x,0,sizeof(x));		//初始化x向量
	int i=0;
	while (i<n && A[i].w<rw)		//物品i能够全部装入时循环
	{	x[i]=1;					//装入物品i
		rw-=A[i].w;			//减少背包中能装入的余下重量
		bestv+=A[i].v;				//累计总价值
		printf("i=%d,bestv=%g\n",i,bestv);
		i++;					//继续循环
	}
	if (i<n && rw>0)				//当余下重量大于0
	{	x[i]=rw/A[i].w;		//将物品i的一部分装入
		bestv+=x[i]*A[i].v;			//累计总价值
		printf("i=%d,bestv=%g\n",i,bestv);
	}
}
void dispA()					//输出A
{
	printf("\tw\tv\tv/w\n");
	for (int i=0;i<n;i++)
		printf("\t%g\t%g\t%g\n",A[i].w,A[i].v,1.0*A[i].v/A[i].w);
}
int main()
{
	printf("求解过程\n");
	printf("(1)排序前\n");dispA();
	sort(A.begin(),A.end());				//排序
	printf("(2)排序后:\n"); dispA();
	Knap();
	printf("(3)求解结果\n");		//输出结果
	printf("    x: [");
	for (int j=0;j<n-1;j++)
		printf("%g, ",x[j]);
	printf("%g]\n",x[n]);
	printf("    总价值=%g\n",bestv);
	return 0;
}
