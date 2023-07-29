int dx[]={0,0,1,-1};                                    			//水平方向偏移量
int dy[]={1,-1,0,0};                                    			//垂直方向偏移量
struct QNode                                                		//队列元素类型
{	int x,y;                                            					//记录(x,y)位置
    	QNode(int x1,int y1):x(x1),y(y1) {}    			//重载构造函数
}; 
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid)
    	{	int m=grid.size();                                  		//行数
        	int n=grid[0].size();                           			//列数
        	queue<QNode> qu;                                		//定义一个队列qu
        	for(int i=0;i<m;i++)
         		for(int j=0;j<n;j++)
            	{	if (grid[i][j]==2)                  				//所有腐烂的橘子进队
                   	qu.push(QNode(i,j));
            	}
        	int ans=0;                          							//经过的最小分钟数
        	while(!qu.empty())                              			//队不空循环
        	{	bool flag=false;
            	int cnt=qu.size();                    				//求队列中元素个数cnt
            	for(int i=0;i<cnt;i++)                  			//循环cnt次处理该层所有元素
            	{	QNode e=qu.front(); qu.pop();          	//出队元素e
                	for(int di=0;di<4;di++)                 		//四周搜索
                	{	int nx=e.x+dx[di];
                    	int ny=e.y+dy[di];
                    	if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)  
                    	{	grid[nx][ny]=2;                 		//新鲜橘子变为腐烂橘子
                        	qu.push(QNode(nx,ny));          	//腐烂橘子进队
                        	flag=true;                      			//表示有新鲜橘子变为腐烂橘子
                    	}
               	}
            	}
            	if (flag) ans++;                        				//有新鲜橘子变为腐烂橘子时ans增1
        	}
        	for(int i=0;i<m;i++)                    				//判断是否还存在新鲜橘子
        		for(int j=0;j<n;j++)
                	if (grid[i][j]==1)              					//还存在新鲜橘子
                    	return -1;              						//返回-1
        	return ans;
    }
};

