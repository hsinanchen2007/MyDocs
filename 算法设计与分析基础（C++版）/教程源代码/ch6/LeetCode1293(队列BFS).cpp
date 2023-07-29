/*
ִ�н����ͨ��
ִ����ʱ��4 ms, ������ C++ �ύ�л�����95.63%���û�
�ڴ����ģ�7.9 MB, ������ C++ �ύ�л�����74.76%���û�
*/
#define MAXN 42                                         //����m,n
int dx[]={0,0,1,-1};                                    //ˮƽ����ƫ����
int dy[]={1,-1,0,0};                                    //��ֱ����ƫ����
struct QNode
{	int x;                                              	//λ��
	int y;
	int nums;                                       		//�ϰ������
};                                                           	//����Ԫ������
class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) 
	{
		int m=grid.size();                                     //����
    	int n=grid[0].size();                               //����
    	if (k>=m+n-3)
        	return m+n-2;
    	int visited[MAXN][MAXN][MAXN];
    	memset(visited,0,sizeof(visited));                  //visited����Ԫ�س�ʼ��Ϊ0
    	QNode e,e1;
    	queue<QNode> qu;
    	e.x=0; e.y=0; e.nums=0;
    	qu.push(e);
    	int bestd=0;                                   	 //������Ž� 
    	visited[0][0][0]=1;
    	while (!qu.empty())                                     //�Ӳ���ѭ��
    	{   int cnt=qu.size();                              //�����Ԫ�ظ��� 
        	for (int i=0;i<cnt;i++)
        	{   e=qu.front(); qu.pop();
            	int x=e.x;                              	//����Ԫ��Ϊ(x,y,nums)
            	int y=e.y;
            	int nums=e.nums;
            	if (nums>k) continue;                           //��֧���������ϰ����������k������
            	if (x==m-1 && y==n-1)                       	//�ҵ�Ŀ��λ��
                    return bestd;                                  //����bestd
            	for (int di=0;di<4;di++)                        //��������
            	{   int nx=x+dx[di];                            //di��λ��λ��Ϊ(nx,ny)
                	int ny=y+dy[di];
                	if (nx>=0 && nx<m && ny>=0 && ny<n)
                	{   int nnums;
                    	if (grid[nx][ny]==1)                    //����һ���ϰ���
                        	nnums=nums+1;
                    	else
                        	nnums=nums;
                    	if (visited[nx][ny][nnums]==0)      //��Ӧ��·��û���߹�
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

