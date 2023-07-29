#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 200010
int visited[MAXN];									//访问标记数组
int bfs(int n,int k)									//分层次的广度优先搜索
{	memset(visited,0,sizeof(visited));	
	queue<int> qu;									//定义一个队列（其中结点为int的位置）
	visited[n]=1;
	qu.push(n);
	int minstep=0;										//最少时间（以分钟为单位）
	while(!qu.empty())
	{	int cnt=qu.size();
		for(int i=0;i<cnt;i++)						//循环cnt次
		{	int e=qu.front(); qu.pop();				//出队结点e
			if(e==k)										//找到目标
				return minstep;
			int e1=e+1;									//①:向右步行
			if(e1>=0 && e1<=100000 && visited[e1]==0)
			{	visited[e1]=1;
				qu.push(e1);
			}
			int e2=e-1;									//②:向左步行
			if(e2>=0 && e2<=100000 && visited[e2]==0)
			{	visited[e2]=1;
				qu.push(e2);
			}
			int e3=2*e;									//③:传送
			if(e3>=0 && e3<=100000 && visited[e3]==0)
			{	visited[e3]=1;
				qu.push(e3);
			}
		}
		minstep++;
	}
	return -1;										//没有找到返回-1
}
int main()
{	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	if(n==k)
	{	cout << 0 << endl;
		return 0;
	}
	else
		cout << bfs(n,k) << endl;
	return 0;
}

