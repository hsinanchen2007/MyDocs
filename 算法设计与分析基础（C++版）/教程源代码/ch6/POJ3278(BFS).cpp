//AC:1256K 172MS 
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 200010
int visited[MAXN];					//���ʱ������
struct QNode						//�����еĽ������
{
	int p;							//��ǰλ��
	int step;						//ʱ�䣨�Է���Ϊ��λ�� 
	QNode() {}
	QNode(int p,int step):p(p),step(step) {}
};
int bfs(int n,int k)
{
	memset(visited,0,sizeof(visited));
	queue<QNode> qu;				//����һ������ 
	qu.push(QNode(n,0));
	visited[n]=1;
	while(!qu.empty())
	{
		QNode e=qu.front(); qu.pop();	//���ӽ��e 
		if(e.p==k)						//�ҵ�Ŀ�� 
			return e.step;
		QNode e1,e2,e3;
		e1.p=e.p+1; e1.step=e.step+1;		//��:���Ҳ���
		if(e1.p>=0 && e1.p<=100000 && visited[e1.p]==0)
		{
			visited[e1.p]=1;
			qu.push(e1);
		}
		e2.p=e.p-1; e2.step=e.step+1;		//��:������
		if(e2.p>=0 && e2.p<=100000 && visited[e2.p]==0)
		{
			visited[e2.p]=1;
			qu.push(e2);
		}
		e3.p=2*e.p; e3.step=e.step+1;		//��:����
		if(e3.p>=0 && e3.p<=100000 && visited[e3.p]==0)
		{
			visited[e3.p]=1;
			qu.push(e3);
		}
	}
	return -1;							//û���ҵ�����-1 
}
int main()
{
	int n,k;
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
