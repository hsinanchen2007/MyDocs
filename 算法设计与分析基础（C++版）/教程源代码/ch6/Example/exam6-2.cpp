#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f			//��ʾ��
#define MAXN 51
//�����ʾ
int n=6;							//ͼ�������
int A[MAXN][MAXN]={					//ͼ���ڽӾ���
{0,2,3,4,INF,INF},
{INF,0,INF,INF,8,INF},
{INF,INF,0,6,INF,INF},
{INF,INF,INF,0,INF,1},
{INF,INF,INF,INF,0,2},
{INF,INF,INF,INF,1,0}};
//�������ʾ
struct QNode					//���н������
{
    int vno;					//������
	int length;					//·������
    bool operator<(const QNode&b) const
    {
        return length>b.length;	//lengthԽСԽ���ȳ���
    }
};
int sum=0;
int bfs(int s,int t)					//��s��t�����·������
{
	QNode e,e1;
    priority_queue<QNode> pqu;	//�������ȶ���
	e.vno=s;						//����Դ����e
	e.length=0;
	pqu.push(e);					//Դ����e����
    while(!pqu.empty())				//���в���ѭ��
    {
		e=pqu.top(); pqu.pop();		//�����н��e
		int u=e.vno;
		//printf("����%d\n",u); 
		//printf("     �״�%d:e.length=%d\n",u,e.length);
		if(u==t)
		{
			//printf("   ����%d�ĳ���=%d\n",u,e.length); 
			return e.length;
		}
        for (int v=0;v<n;v++)
		{
            if(A[u][v]!=0 && A[u][v]<INF)	//u��v�б� 
            {
				//printf("  �������ڵ�%d  ", v);
				e1.vno=v;					//�������ڶ���v�Ľ��e1
				e1.length=e.length+A[u][v];
                //printf(" �޸�e1.length=%d\n",e1.length); 
				pqu.push(e1);				//���e1����
            }
		}
		//sum++;
		//if(sum>12) break;
    }
    return -1;
}
int main()
{
	//for(int s=0;s<n;s++)
	int s=0;
	int t=4;
		//for(int t=0;t<n;t++)
			printf("%d��%d�����·������=%d\n",s,t,bfs(s,t));
	return 0;
}
