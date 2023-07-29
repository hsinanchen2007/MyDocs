/*
执行结果：通过
执行用时：4 ms, 在所有 C++ 提交中击败了95.63%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了74.76%的用户
*/
#define MAXN 42                                         //最大的m,n
int dx[]={0,0,1,-1};                                    //水平方向偏移量
int dy[]={1,-1,0,0};                                    //垂直方向偏移量
struct QNode
{	int x;                                              	//位置
	int y;
	int nums;                                       		//障碍物个数
};                                                           	//队列元素类型
class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) 
	{
		int m=grid.size();                                     //行数
    	int n=grid[0].size();                               //列数
    	if (k>=m+n-3)
        	return m+n-2;
    	int visited[MAXN][MAXN][MAXN];
    	memset(visited,0,sizeof(visited));                  //visited所有元素初始化为0
    	QNode e,e1;
    	queue<QNode> qu;
    	e.x=0; e.y=0; e.nums=0;
    	qu.push(e);
    	int bestd=0;                                   	 //存放最优解 
    	visited[0][0][0]=1;
    	while (!qu.empty())                                     //队不空循环
    	{   int cnt=qu.size();                              //求队中元素个数 
        	for (int i=0;i<cnt;i++)
        	{   e=qu.front(); qu.pop();
            	int x=e.x;                              	//出队元素为(x,y,nums)
            	int y=e.y;
            	int nums=e.nums;
            	if (nums>k) continue;                           //剪支：经过的障碍物个数大于k，跳过
            	if (x==m-1 && y==n-1)                       	//找到目标位置
                    return bestd;                                  //返回bestd
            	for (int di=0;di<4;di++)                        //四周搜索
            	{   int nx=x+dx[di];                            //di方位的位置为(nx,ny)
                	int ny=y+dy[di];
                	if (nx>=0 && nx<m && ny>=0 && ny<n)
                	{   int nnums;
                    	if (grid[nx][ny]==1)                    //遇到一个障碍物
                        	nnums=nums+1;
                    	else
                        	nnums=nums;
                    	if (visited[nx][ny][nnums]==0)      //对应的路径没有走过
                    	{   e1.x=nx; e1.y=ny; e1.nums=nnums;
                        	qu.push(e1);
                        	visited[nx][ny][nnums]=1;
                    	}
                	}
            	}
        	}
        	bestd++;
    	}
    	return -1;
	}
};

