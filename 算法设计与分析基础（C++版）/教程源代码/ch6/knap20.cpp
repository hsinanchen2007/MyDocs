#include<iostream>
#include<vector>
#include<queue>
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
};
//int n=4;							//4种物品
//int W=6;							//背包容量为6
//vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};

int n=3;							//3种物品
int W=4;							//背包容量为4
vector<Goods> g={Goods(0,1,3),Goods(1,2,3),Goods(2,2,4)};


//int W=8; 
//vector<Goods> g={Goods(0,2,6),Goods(1,4,8),Goods(2,3,3),Goods(3,2,2)};
vector<int> bestx;					//存放最优解向量 
int bestv=0; 						//存放最大价值,初始为0 
int bestw;							//存放最大重量 

struct QNode						//队列中结点类型
{
	int i;							//当前层次(物品序号) 
	int cw;							//当前总重量
	int cv;							//当前总价值
	vector<int> x;					//当前解向量
};

void EnQueue(QNode e,queue<QNode>& qu)		//结点e进队操作
{
	if (e.i==n)							//到达叶子结点
	{	printf("  一个解[%d,%d]\n",e.cw,e.cv); 
		if (e.cv>bestv)						//比较更新最优解
		{	bestv=e.cv;
			bestx=e.x;
			bestw=e.cw;
			printf("  最优解bestv=%d\n",bestv); 
		}
	}
	else
	{
		printf("进队\n"); 
		qu.push(e);						//非叶子结点进队
	} 
}
int sum=0;
void bfs()							//求0/1背包的最优解
{	QNode e,e1,e2;					//定义3个结点
	queue<QNode> qu;				//定义一个队列
	e.i=0;
	e.cw=0; e.cv=0;
	e.x.resize(n);
	//bound(e);							//求根结点的上界
	qu.push(e);							//根结点进队
	//printf("根结点[%d,%d,%g]进队\n",e.w,e.v,e.ub); 
	while (!qu.empty())					//队不空循环
	{
		e=qu.front(); qu.pop();			//出队结点e
		printf("(%d)出队结点[%d,%d,%d]\n",++sum,e.i,e.cw,e.cv); 
		if (e.cw+g[e.i].w<=W)			//左孩子(选择物品e.i剪支
		{	e1.cw=e.cw+g[e.i].w;			//选择物品e.i
			e1.cv=e.cv+g[e.i].v;
			e1.x=e.x;
			e1.x[e.i]=1;				//选择物品e.i
			e1.i=e.i+1;					//左子结点的层次加1
			printf("   左结点[%d,%d,%d],  ",e1.i,e1.cw,e1.cv); 
			EnQueue(e1,qu);
		} 
		else
			printf("   左结点[%d,%d,%d],e1.i=%d ->cut\n",e1.i,e1.cw,e1.cv); 
		e2.cw=e.cw;					//不选择物品e.i
		e2.cv=e.cv;
		e2.x=e.x;
		e2.x[e.i]=0;					//不选择物品i
		e2.i=e.i+1;						//右子结点的层次加1
			printf("   右结点[%d,%d,%d],e2.i=%d,  ",e2.i,e2.cw,e2.cv); 
			EnQueue(e2,qu);
	}
}
void dispg()					//输出g 
{
	for(int i=0;i<g.size();i++)
		printf("%d\t%d\t%d\t%g\n",g[i].no,g[i].w,g[i].v,(double)g[i].v/g[i].w);
}
void disp()							//输出最优解
{
	printf("最佳装填方案\n");
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  选取第%d个物品\n",g[i].no);
	printf("  总重量=%d,总价值=%d\n",bestw,bestv);
}

void knap()									//求0/1背包问题 
{
	bestx.resize(n);
	vector<int> x(n);
	//sort(g.begin(),g.end());
	printf("sort\n"); dispg();
	bfs();							//i从0开始
}
int main()
{
	freopen("xyz.txt","w",stdout); 
	printf("分支限界法求解0/1背包问题:\n"); 
	knap();							//调用队列式分支限界法求0/1背包问题
	disp();
}

