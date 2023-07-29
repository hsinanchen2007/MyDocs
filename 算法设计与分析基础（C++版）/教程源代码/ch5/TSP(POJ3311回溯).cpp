//AC:144K 172MS 
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 12
int A[MAXN][MAXN];
int n;
int bestd;									//������Сʱ��
void dfs(vector<int>&x,int d,int s,int i)	//���ݷ��㷨
{
	if(i>n)								//�ﵽһ��Ҷ�ӽ�� 
	{
		if(d+A[x[n]][s]<bestd)			//�Ƚ������Ž� 
			bestd=d+A[x[n]][s];			//��TSP���� 
	}
	else
	{
		for(int j=i;j<=n;j++)				//��̽x[i]�ߵ�x[j]�ķ�֧
		{
			if (A[x[i-1]][x[j]]!=0 && A[x[i-1]][x[j]]!=INF)	//��x[i-1]��x[j]�б�
			{
				if(d+A[x[i-1]][x[j]]<bestd)					//��֧
				{
					swap(x[i],x[j]);
					dfs(x,d+A[x[i-1]][x[i]],s,i+1);
					swap(x[i],x[j]);
				}
			}
		}
	}			
}
void TSP1(int s)								//���TSP(��ʼ��Ϊs)
{
	vector<int> x;								//���������
	x.push_back(s);
	for(int i=0;i<=n;i++)						//����s�Ķ�����ӵ�x��
		if(i!=s)
			x.push_back(i);
	int d=0;
	bestd=INF;
	dfs(x,d,s,1);
}
void Floyd()						//�������·������
{
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];
}
int main()
{
	//freopen("abc.txt","r",stdin);
    while(scanf("%d",&n)==1 &&n)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                scanf("%d",&A[i][j]);
        Floyd();						//�������·������
        TSP1(0);
        printf("%d\n",bestd);
    }
    return 0;
} 


