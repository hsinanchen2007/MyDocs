//AC:15MS 1740K 
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 10
struct QNode									//����Ԫ�ص�����
{	int x,y;									//���˹���λ��
	int bx,by;									//���ӵ�λ��
	int step;									//�����ӵĲ���
};
int dx[]={1,-1,0,0};								//x����ƫ����
int dy[]={0,0,1,-1};								//y����ƫ����
int grid[MAXN][MAXN];								//��ͼ 
int n,m;
bool bfsp(int xi,int yi,int xe,int ye,int bx,int by)
//�ж��Ƿ����(xi,yi)->(xe,ye)������(bx,by)��·��
{	bool visited[MAXN][MAXN];
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;
	QNode p;
	p.x=xi; p.y=yi; 
	visited[xi][yi]=1;
	qu.push(p);
	while(!qu.empty())
	{	p=qu.front(); qu.pop();					//����һ��Ԫ��p
		if (p.x==xe && p.y==ye)					//�ҵ�(xe,ye)
			return true;
		for(int di=0;di<4;di++)
		{	QNode np=p;							//���˹�����di��λ��һ��
			np.x+=dx[di];
			np.y+=dy[di];
			if (np.x<0 || np.x>=n || np.y<0 || np.y>=m)
				continue;						//����ʱ����
			if (visited[np.x][np.y])
				continue;						//�Ѿ�����ʱ����
			if (grid[np.x][np.y]==1)
				continue;						//Ϊǽʱ���� 
			if (np.x==bx && np.y==by)
				continue;						//Ϊ����λ��ʱ���� 
			visited[np.x][np.y]=1;
			qu.push(np);
		}
	}
	return false;
}
int bfsb(QNode st)								//�������㷨
{
	bool visited[MAXN][MAXN][4];
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;
	qu.push(st);
	while (!qu.empty())
	{	QNode e=qu.front(); qu.pop();			//���ӽ��e 
		if(grid[e.bx][e.by]==3)					//�ҵ����ӵ�Ŀ��λ��
			return e.step;						//���� 
		for(int di=0;di<4;di++)					//�������� 
		{	int prex=e.bx-dx[di];				//��di���෴��λ�����ӵ�ǰһ��λ�� 
			int prey=e.by-dy[di];
			int nextx=e.bx+dx[di];				//��di�ķ�λ�����ӵĺ�һ��λ��
			int nexty=e.by+dy[di];
			if (nextx<0 || nextx>=n || nexty<0 || nexty>=m)
				continue;						//λ��(nextx,nexty)����ʱ���� 
			if (visited[nextx][nexty][di])
				continue;						//λ��(nextx,nexty)�Ѿ�����ʱ����
			if (prex<0 || prex>=n || prey<0 || prey>=m)
				continue;						//λ��(prex,prey)����ʱ����
			if (grid[nextx][nexty]==1 || grid[prex][prey]==1)
				continue;						//����λ����һ����ǽʱ����
			if (bfsp(e.x,e.y,prex,prey,e.bx,e.by)) 	//����bfsp()����·���ж�
			{	visited[nextx][nexty][di]=1;
				QNode e1;								//������һ����չ�����e1 
				e1.bx=nextx;
				e1.by=nexty;
				e1.x=e.bx;
				e1.y=e.by;
				e1.step=e.step+1;
				qu.push(e1);
			}
		}
	}
	return -1;										//û��·�������
}
int main()
{	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;++cas)
	{	scanf("%d%d",&n,&m);
		QNode st;									//��ų�ʼ״̬
		st.step=0;
		for(int i=0;i<n;++i)
		{	for(int j=0;j<m;++j)
			{	scanf("%d",&grid[i][j]);
				if(grid[i][j]==4)					//���˹��ĳ�ʼλ��
				{	st.x=i;
					st.y=j;
				}
				if(grid[i][j]==2)					//���ӵĳ�ʼλ��
				{	st.bx=i;
					st.by=j;
				}
			}
		}
		printf("%d\n",bfsb(st));
	}
	return 0;
}

