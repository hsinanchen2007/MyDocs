/*
ִ�н����ͨ��
ִ����ʱ��108 ms, ������C++�ύ�л�����99.21%���û�
�ڴ����ģ�18.1 MB, ������ C++ �ύ�л�����94.18%���û�
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
int dx[]={0,0,1,-1};                //ˮƽ����ƫ����
int dy[]={1,-1,0,0};               	//��ֱ����ƫ����
struct QNode
{
	int x,y;
	int length;
	bool operator<(const QNode& b) const
	{
		return length>b.length;		//��·������ԽСԽ���ȳ��� 
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
        priority_queue<QNode> pqu;		//����һ�����ȶ��� 
        e1.x=0; e1.y=0;					//(0,0)���� 
        e1.length=0;
        pqu.push(e1);
        dist[0][0]=0;
        while(!pqu.empty())
        {
        	e=pqu.top(); pqu.pop();
        	int x=e.x, y=e.y;
        	int length=e.length;
        	if(x==m-1 && y==n-1)		//�ҵ��յ㷵�� 
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
	
