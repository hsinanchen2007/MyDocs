//AC:15MS 1740K 
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 10
struct QNode									//队中元素的类型
{	int x,y;									//搬运工的位置
	int bx,by;									//箱子的位置
	int step;									//推箱子的步数
};
int dx[]={1,-1,0,0};								//x方向偏移量
int dy[]={0,0,1,-1};								//y方向偏移量
int grid[MAXN][MAXN];								//地图 
int n,m;
bool bfsp(int xi,int yi,int xe,int ye,int bx,int by)
//判断是否存在(xi,yi)->(xe,ye)不经过(bx,by)的路径
{	bool visited[MAXN][MAXN];
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;
	QNode p;
	p.x=xi; p.y=yi; 
	visited[xi][yi]=1;
	qu.push(p);
	while(!qu.empty())
	{	p=qu.front(); qu.pop();					//出队一个元素p
		if (p.x==xe && p.y==ye)					//找到(xe,ye)
			return true;
		for(int di=0;di<4;di++)
		{	QNode np=p;							//搬运工沿着di方位走一步
			np.x+=dx[di];
			np.y+=dy[di];
			if (np.x<0 || np.x>=n || np.y<0 || np.y>=m)
				continue;						//超界时跳过
			if (visited[np.x][np.y])
				continue;						//已经访问时跳过
			if (grid[np.x][np.y]==1)
				continue;						//为墙时跳过 
			if (np.x==bx && np.y==by)
				continue;						//为箱子位置时跳过 
			visited[np.x][np.y]=1;
			qu.push(np);
		}
	}
	return false;
}
int bfsb(QNode st)								//推箱子算法
{
	bool visited[MAXN][MAXN][4];
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;
	qu.push(st);
	while (!qu.empty())
	{	QNode e=qu.front(); qu.pop();			//出队结点e 
		if(grid[e.bx][e.by]==3)					//找到箱子的目标位置
			return e.step;						//返回 
		for(int di=0;di<4;di++)					//搜索四周 
		{	int prex=e.bx-dx[di];				//按di的相反方位求箱子的前一个位置 
			int prey=e.by-dy[di];
			int nextx=e.bx+dx[di];				//按di的方位求箱子的后一个位置
			int nexty=e.by+dy[di];
			if (nextx<0 || nextx>=n || nexty<0 || nexty>=m)
				continue;						//位置(nextx,nexty)超界时跳过 
			if (visited[nextx][nexty][di])
				continue;						//位置(nextx,nexty)已经访问时跳过
			if (prex<0 || prex>=n || prey<0 || prey>=m)
				continue;						//位置(prex,prey)超界时跳过
			if (grid[nextx][nexty]==1 || grid[prex][prey]==1)
				continue;						//两个位置有一个是墙时跳过
			if (bfsp(e.x,e.y,prex,prey,e.bx,e.by)) 	//调用bfsp()进行路径判断
			{	visited[nextx][nexty][di]=1;
				QNode e1;								//推箱子一次扩展出结点e1 
				e1.bx=nextx;
				e1.by=nexty;
				e1.x=e.bx;
				e1.y=e.by;
				e1.step=e.step+1;
				qu.push(e1);
			}
		}
	}
	return -1;										//没有路径的情况
}
int main()
{	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;++cas)
	{	scanf("%d%d",&n,&m);
		QNode st;									//存放初始状态
		st.step=0;
		for(int i=0;i<n;++i)
		{	for(int j=0;j<m;++j)
			{	scanf("%d",&grid[i][j]);
				if(grid[i][j]==4)					//搬运工的初始位置
				{	st.x=i;
					st.y=j;
				}
				if(grid[i][j]==2)					//箱子的初始位置
				{	st.bx=i;
					st.by=j;
				}
			}
		}
		printf("%d\n",bfsb(st));
	}
	return 0;
}

