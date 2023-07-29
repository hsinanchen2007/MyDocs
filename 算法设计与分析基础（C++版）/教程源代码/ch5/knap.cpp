#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Goods								//物品结构体类型 
{
	int no;									//物品的编号
	int w;									//物品的重量
	int v;									//物品的价值
	Goods(int no1,int w1,int v1)			//构造函数 
	{
		no=no1;
		w=w1;
		v=v1;
	}
	bool operator<(const Goods&s) const		//用于按v/w递减排序 
	{
		return (double)v/w>(double)s.v/s.w;
	}	
};
int n=4;							//4种物品
int W=6;							//背包容量为6
//vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};
vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};
vector<int> bestx;					//存放最优解向量 
int bestv=0; 						//存放最大价值,初始为0 
void disp()							//输出最优解
{
	printf("最佳装填方案\n");
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  选取第%d个物品\n",g[i].no);
	printf("  总重量=%d,总价值=%d\n",W,bestv);
}

double bound(int cw,int cv,int i)		//计算第i层结点的上界函数值
{
	int rw=W-cw;						//背包的剩余容量
	double b=cv;						//表示物品价值的上界值 
	int j=i;
	while (j<n && g[j].w<=rw)
	{	
		rw-=g[j].w;						//选择物品j
		b+=g[j].v;						//累计价值
		//printf("选择i=%d,rw=%d,b=%g\n",j,rw,b); 
		j++;
	}
	if (j<n)							//最后物品只能部分装入 
		b+=(double)g[j].v/g[j].w*rw;
	return b;
}
int sum=0;									//累计搜索的结点个数 
void dfs(int cw,int cv,vector<int>&x,int i) //回溯算法
{	sum++;
	printf("[%d,%d]\n",cw,cv);
	if (i>=n)								//找到一个叶子结点
	{	printf("找到一个解[%d,%d]\n",cw,cv); 
		if (cw<=W && cv>bestv)				//找到一个满足条件的更优解,保存它
		{	bestv=cv;
			bestx=x;
		}
	}
	else									//没有到达叶子结点品
	{	if(cw+g[i].w<=W)					//左剪支
		{ 
			x[i]=1;								//选取物品i
			dfs(cw+g[i].w,cv+g[i].v,x,i+1);
		}
		else
			printf("左剪支[%d,%d]\n",cw+g[i].w,cv+g[i].v);
		
		double b=bound(cw,cv,i+1);				//计算 
		if(b>bestv)				//右剪支
		{
			printf("扩展右孩子结点b=%g\n",b); 
			x[i]=0;								//不选取物品i 
			dfs(cw,cv,x,i+1);
		}
		else
			printf("右剪支[%d,%d],b=%g\n",cw,cv,b);
	}
}
void dispg()					//输出g 
{
	for(int i=0;i<g.size();i++)
		printf("%d\t%d\t%d\t%g\n",g[i].no,g[i].w,g[i].v,(double)g[i].v/g[i].w);
}

void knap()						//求0/1背包问题 
{
	bestx.resize(n);
	vector<int> x(n);
	sort(g.begin(),g.end());
	printf("sort\n"); dispg();
	dfs(0,0,x,0);				//i从0开始
	disp();
}

int main()
{
	printf("g:\n"); dispg();
	knap();
	printf("sum=%d\n",sum);
	return 0;
}
