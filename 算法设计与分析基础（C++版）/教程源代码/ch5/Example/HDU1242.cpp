#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 202
int dx[]={0,0,1,-1};                  		//水平方向偏移量
int dy[]={1,-1,0,0};                  	 	//垂直方向偏移量
char grid[MAXN][MAXN];							//存放网格
int visited[MAXN][MAXN];
int n,m;
int bestlen; 
void dfs(int x,int y,int len)
{	if(grid[x][y]=='r')									//找到朋友
  	{	if(len<bestlen)									//比较求最短路径长度
     	bestlen=len;
  	}
	else
	{	for(int di=0;di<4;di++)							//枚举四个方位
    	{	int nx=x+dx[di];
     	int ny=y+dy[di];
      	if(nx<0 || nx>=n || ny<0 || ny>=m)		//(nx,ny)超界时跳过
				continue;
			if(visited[nx][ny]==1)						//(nx,ny)已访问时跳过
				continue;
    		if(grid[x][y]=='#')							//(nx,ny)为墙时跳过
    			continue;
			if(grid[nx][ny]=='x')						//(nx,ny)为守卫的情况
			{	visited[nx][ny]=1;						//标记(nx,ny)已经访问
        	dfs(nx,ny,len+2);							//走一步+杀死守卫
        	visited[nx][ny]=0;						//路径回溯
     	}
     	else												//(nx,ny)为道路的情况
      	{	visited[nx][ny]=1;
        	dfs(nx,ny,len+1);							//走一步
        	visited[nx][ny]=0;
      	}
    	}
	}
}
int main()
{	int sx,sy;												//标记天使的位置
 	while(cin >> n >> m)
 	{	for(int i=0;i<n;i++)								//输入矩阵
    	{	for(int j=0;j<m;j++)
      	{	cin >> grid[i][j];
        	if(grid[i][j]=='a')
        	{	sx=i;
					sy=j;
        	}
     	}
   	}
   	bestlen=INF;
    	memset(visited,0,sizeof(visited));
   	dfs(sx,sy,0);
    	if(bestlen==INF)									//如果bestlen为INF说明没找到路径
     	cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
   	else
    		cout << bestlen << endl;
	}
	return 0;
}

