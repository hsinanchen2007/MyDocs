/*
执行结果：通过
执行用时：108 ms, 在所有C++提交中击败了99.21%的用户
内存消耗：18.1 MB, 在所有 C++ 提交中击败了94.18%的用户
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
int dx[]={0,0,1,-1};                //水平方向偏移量
int dy[]={1,-1,0,0};               	//垂直方向偏移量
struct QNode
{
	int x,y;
	int length;
	bool operator<(const QNode& b) const
	{
		return length>b.length;		//按路径长度越小越优先出队 
	}
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
	{
        int m=heights.size();
        int n=heights[0].size();
        int dist[MAXN][MAXN];
        memset(dist,0x3f,sizeof(dist));
        QNode e,e1;
        priority_queue<QNode> pqu;		//定义一个优先队列 
        e1.x=0; e1.y=0;					//(0,0)进队 
        e1.length=0;
        pqu.push(e1);
        dist[0][0]=0;
        while(!pqu.empty())
        {
        	e=pqu.top(); pqu.pop();
        	int x=e.x, y=e.y;
        	int length=e.length;
        	if(x==m-1 && y==n-1)		//找到终点返回 
        		return e.length;
        	for(int di=0;di<4;di++)
        	{
        		int nx=x+dx[di];
        		int ny=y+dy[di];
        		if(nx<0 || nx>=m || ny<0 || ny>=n)
        			continue;
        		int curlen=max(length,abs(heights[nx][ny]-heights[x][y]));
				if(curlen<dist[nx][ny])
				{	dist[nx][ny]=curlen;
					e1.x=nx; e1.y=ny;
					e1.length=curlen;
					pqu.push(e1);
				}
        	}
        }
       	return -1;
    }
};
int main()
{
	vector<vector<int>> h={{1,2,2},{3,8,2},{5,3,5}};
	Solution obj;
	cout << obj.minimumEffortPath(h) << endl;
	return 0;
}
	
