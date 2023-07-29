#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f			//定义∞
#define MAXN 21
//问题表示
int n=4;
int c[MAXN][MAXN]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
vector<int> bestx;				//最优分配方案
int bestc=INF;				//最小成本
struct QNode					//队列结点类型
{
	int i;						//人员编号
	vector<int> x;					//当前解向量
	vector<int> used;			//used[i]=true表示任务i已经分配
	int cost;					//已经分配任务所需要的成本
	int lb;						//下界
	bool operator<(const QNode& b) const	//重载<关系函数
	{
		return lb>b.lb;			//lb越小越优先出队 
	}
};
void bound(QNode& e)				//求结点e的下界值	
{
	int minsum=0;
	for (int i1=e.i;i1<n;i1++)	//求c[e.i..n-1]行中最小元素和
	{
		int minc=INF;
		for (int j1=0;j1<n;j1++)
			if (e.used[j1]==false && c[i1][j1]<minc)
				minc=c[i1][j1];
		minsum+=minc;
	}
	e.lb=e.cost+minsum;
}
void disptmp(QNode e)
{
	printf("（i=%d,cost=%d,",e.i,e.cost);
	printf("x=[");
	for(int j=0;j<e.x.size()-1;j++)
		printf("%d,",e.x[j]);
	printf("%d],used=[",e.x[e.x.size()-1]);
	for(int j=0;j<e.used.size()-1;j++)
		printf("%d,",e.used[j]);
	printf("%d],lb=%d）",e.used[e.used.size()-1],e.lb);	
}
void EnQueue(QNode e,priority_queue<QNode>& pqu)		//结点e进队操作
{
	if (e.i==n)							//到达叶子结点
	{	printf("  一个解 "); disptmp(e); 
		if (e.cost<bestc)						//比较更新最优解
		{	bestc=e.cost;
			bestx=e.x;
			printf("  最优解bestc=%d\n",bestc); 
		}
	}
	else
		pqu.push(e);						//非叶子结点进队
}
int sum=0;
void bfs()									//求解任务分配
{
	QNode e,e1;
	priority_queue<QNode> pqu;
	e.i=0;									//根结点，指定人员为0
	e.cost=0;
	e.x.resize(n);
	e.used.resize(n);
	bound(e);								//求根结点的lb
	pqu.push(e);							//根结点进队列
	while (!pqu.empty())
	{
		e=pqu.top(); pqu.pop();				//出队结点e，考虑为人员e.i分配任务 
		printf(" (%d)出队结点 ",++sum); disptmp(e); printf("\n");
		for (int j=0;j<n;j++)				//共n个任务
		{
			if (e.used[j]) continue;		//任务j已分配时跳过
			e1.i=e.i+1;						//子结点的层次加1
			e1.x=e.x;
			e1.x[e.i]=j;					//为人员e.i分配任务j
			e1.used=e.used;
			e1.used[j]=true;				//标志任务j已经分配
			e1.cost=e.cost+c[e.i][j];
			bound(e1);						//求e1的lb
			printf("    选择任务j=%d 结点",j); disptmp(e1); 
			if (e1.lb<bestc)				//剪支 
			{
				printf(" ->进队\n"); 
				EnQueue(e1,pqu);
			}
			else
				printf(" ->cut\n");
		}
	}
}
int main()
{
	freopen("xyz.txt","w",stdout);
	bfs();
	printf("最优方案:\n");
	for (int k=0;k<n;k++)
		printf("   第%d个人员分配第%d个任务\n",k,bestx[k]);
	printf("   总成本=%d\n",bestc);
	return 0;
}






