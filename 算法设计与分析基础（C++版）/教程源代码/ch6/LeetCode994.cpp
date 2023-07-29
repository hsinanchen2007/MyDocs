int dx[]={0,0,1,-1};                                    			//ˮƽ����ƫ����
int dy[]={1,-1,0,0};                                    			//��ֱ����ƫ����
struct QNode                                                		//����Ԫ������
{	int x,y;                                            					//��¼(x,y)λ��
    	QNode(int x1,int y1):x(x1),y(y1) {}    			//���ع��캯��
}; 
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid)
    	{	int m=grid.size();                                  		//����
        	int n=grid[0].size();                           			//����
        	queue<QNode> qu;                                		//����һ������qu
        	for(int i=0;i<m;i++)
         		for(int j=0;j<n;j++)
            	{	if (grid[i][j]==2)                  				//���и��õ����ӽ���
                   	qu.push(QNode(i,j));
            	}
        	int ans=0;                          							//��������С������
        	while(!qu.empty())                              			//�Ӳ���ѭ��
        	{	bool flag=false;
            	int cnt=qu.size();                    				//�������Ԫ�ظ���cnt
            	for(int i=0;i<cnt;i++)                  			//ѭ��cnt�δ���ò�����Ԫ��
            	{	QNode e=qu.front(); qu.pop();          	//����Ԫ��e
                	for(int di=0;di<4;di++)                 		//��������
                	{	int nx=e.x+dx[di];
                    	int ny=e.y+dy[di];
                    	if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)  
                    	{	grid[nx][ny]=2;                 		//�������ӱ�Ϊ��������
                        	qu.push(QNode(nx,ny));          	//�������ӽ���
                        	flag=true;                      			//��ʾ���������ӱ�Ϊ��������
                    	}
               	}
            	}
            	if (flag) ans++;                        				//���������ӱ�Ϊ��������ʱans��1
        	}
        	for(int i=0;i<m;i++)                    				//�ж��Ƿ񻹴�����������
        		for(int j=0;j<n;j++)
                	if (grid[i][j]==1)              					//��������������
                    	return -1;              						//����-1
        	return ans;
    }
};

