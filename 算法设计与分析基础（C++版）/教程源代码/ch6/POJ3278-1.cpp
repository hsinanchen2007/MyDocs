#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 200010
int visited[MAXN];									//���ʱ������
int bfs(int n,int k)									//�ֲ�εĹ����������
{	memset(visited,0,sizeof(visited));	
	queue<int> qu;									//����һ�����У����н��Ϊint��λ�ã�
	visited[n]=1;
	qu.push(n);
	int minstep=0;										//����ʱ�䣨�Է���Ϊ��λ��
	while(!qu.empty())
	{	int cnt=qu.size();
		for(int i=0;i<cnt;i++)						//ѭ��cnt��
		{	int e=qu.front(); qu.pop();				//���ӽ��e
			if(e==k)										//�ҵ�Ŀ��
				return minstep;
			int e1=e+1;									//��:���Ҳ���
			if(e1>=0 && e1<=100000 && visited[e1]==0)
			{	visited[e1]=1;
				qu.push(e1);
			}
			int e2=e-1;									//��:������
			if(e2>=0 && e2<=100000 && visited[e2]==0)
			{	visited[e2]=1;
				qu.push(e2);
			}
			int e3=2*e;									//��:����
			if(e3>=0 && e3<=100000 && visited[e3]==0)
			{	visited[e3]=1;
				qu.push(e3);
			}
		}
		minstep++;
	}
	return -1;										//û���ҵ�����-1
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

