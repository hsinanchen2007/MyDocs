#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 202
int dx[]={0,0,1,-1};                  		//ˮƽ����ƫ����
int dy[]={1,-1,0,0};                  	 	//��ֱ����ƫ����
char grid[MAXN][MAXN];							//�������
int visited[MAXN][MAXN];
int n,m;
int bestlen; 
void dfs(int x,int y,int len)
{	if(grid[x][y]=='r')									//�ҵ�����
  	{	if(len<bestlen)									//�Ƚ������·������
     		bestlen=len;
  	}
	else
	{	for(int di=0;di<4;di++)							//ö���ĸ���λ
    	{	int nx=x+dx[di];
     	int ny=y+dy[di];
      	if(nx<0 || nx>=n || ny<0 || ny>=m)		//(nx,ny)����ʱ����
				continue;
			if(visited[nx][ny]==1)						//(nx,ny)�ѷ���ʱ����
				continue;
    		if(grid[x][y]=='#')							//(nx,ny)Ϊǽʱ����
    			continue;
			if(grid[nx][ny]=='x')						//(nx,ny)Ϊ���������
			{	visited[nx][ny]=1;						//���(nx,ny)�Ѿ�����
        	dfs(nx,ny,len+2);							//��һ��+ɱ������
        	visited[nx][ny]=0;						//·������
     	}
     	else												//(nx,ny)Ϊ��·�����
      	{	visited[nx][ny]=1;
        	dfs(nx,ny,len+1);							//��һ��
        	visited[nx][ny]=0;
      	}
    	}
	}
}
int main()
{	int sx,sy;												//�����ʹ��λ��
 	while(cin >> n >> m)
 	{	for(int i=0;i<n;i++)								//�������
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
    	if(bestlen==INF)									//���bestlenΪINF˵��û�ҵ�·��
     	cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
   	else
    		cout << bestlen << endl;
	}
	return 0;
}

