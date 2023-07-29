#include<iostream>
#include<cstring>
using namespace std;
#define max(a,b) (a>b?a:b)
#define MAXN 6005											//ͼ�����Ķ�����
int head[MAXN];												//ͷ�������
struct Edge															//�߽������
{	int adjvex;														//�ڽӵ�
	int next;															//��һ���߽����edges�����е��±�
} edges[MAXN];												//�߽������
int n;																	//������
int cnt;																//edges����Ԫ�ظ���
int dp[MAXN][2];												//��̬�滮����
int parent[MAXN];												//parent[i]��ʾԱ��i��˫��
int value[MAXN];												//value[i]��ʾԱ��i�Ŀ���ָ��
void addedge(int u,int v)										//���һ�������<u,v>
{	edges[cnt].adjvex=v;										//�ñ߲��뵽edges����ĩβ
	edges[cnt].next=head[u];									//��edges[cnt]�߽����뵽head[u]�ı�ͷ
	head[u]=cnt;
	cnt++;															//edges����Ԫ�ظ�����1
}
void init()															//��ʼ���㷨
{	cnt=0;															//cnt��0��ʼ
	memset(head,0xff,sizeof(head));						//����Ԫ�س�ʼ��Ϊ-1
	memset(parent,0xff,sizeof(parent));					//���е�˫�׳�ʼ��Ϊ-1
	memset(dp,0,sizeof(dp));
}
void dfs(int root)
{	if(head[root]==-1)											//Ա��rootû���¼�
  {	dp[root][1]=value[root];
     	dp[root][0]=0;
     	return;
	}
  	dp[root][0]=0;
  	dp[root][1]=value[root];
  	int now=head[root];
	while(now!=-1)
 	{	int son=edges[now].adjvex;							//�ҵ�root���¼�Ա��son
		dfs(son);
    	dp[root][1]+=dp[son][0];  							//Ա��root�μӵ����
  		dp[root][0]+=max(dp[son][1],dp[son][0]); 		//Ա��root���μӵ����
    	now=edges[now].next;									//������root���¼�Ա��
 	}
}
int main()
{	while(scanf("%d",&n)!=EOF)
 	{	init();
    	for(int i=1;i<=n;i++)									//��ȡÿ��Ա���Ŀ���ָ��
      	scanf("%d",&value[i]);
    	int a,b;
    	while(scanf("%d%d",&a,&b),a+b)
     {	addedge(b,a);    									//��ӱ�<b,a>
     	parent[a]=b;   										//��ʾa��˫��Ϊb����b��a��ֱ���ϼ���
   	}
		int root=n;
    	while(parent[root]!=-1)								//��Ա��n�����ҵ������root
			root=parent[root];
		dfs(root);													//DFS��dp����
    	printf("%d\n",max(dp[root][0],dp[root][1]));	//������
	}
  	return 0;
}

