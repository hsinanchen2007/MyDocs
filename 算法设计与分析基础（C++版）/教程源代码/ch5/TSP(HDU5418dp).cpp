#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,dis[20][20];
int t;
int dp[20][100000];
/*
s��ʾ�Ѿ������ĳ��еļ��ϣ�v��ʾ���������ڵĳ��С�
����dp[s][v]Ϊ��v������������ʣ��ĳ��У��ٷ����������Ҫ����̵�·����
mp[i][j] ��ʾ i �� j �����·�� 
*/
void floyd()
{
	//�����·
    for(register int k=0;k<n;++k)
        for(register int i=0;i<n;++i)
            for(register int j=0;j<n;++j)
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
}
int main()
{
    cin>>t;
    for(register int k=1;k<=t;++k)
	{
        cin>>n>>m;
        memset(dis,0x3f,sizeof(dis));
        memset(dp,0x3f,sizeof(dp));
        for(register int i = 1;i<=m;i++)
		{
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c); a--;b--;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
        }
        /*
        dp��ʼֵΪ�����һ��ʼ�Լ������벻ͨΪʲô��(1<<n)-1��
        ����ͻȻ�뵽����״ѹ�У� ���ǰѶ������е�0λҲ������ʾһ�����У�
        �����г��ж��ڼ�����Ҫ��ʾΪ(1<<n)-1 
        */
        for(int i=0;i<n;i++) dis[i][i]=0;
        floyd();
        dp[0][(1<<n)-1]=0;
        for(register int s=(1<<n)-2;s>=0;--s) 
            for(register int i=0;i<n;++i)
                for(register int j=0;j<n;++j)
                    if(!(s>>j & 1)) //�����ǰ����j��û�о���,���Ǵ�i����j
                    { 
                        dp[i][s]=min(dp[i][s],dp[j][s|(1<<j)]+dis[i][j]);
                        /*���dp���̱�ʾ����Ҫ��i����j,��dp[j][s|(1<<j)]��ʾ������j,��ʣ�µĻ�δ�ߵĳ���
                        dp[i][s]�ǵ�����i��ʣ�µĻ�δ�ߵĳ��е�ԭ��ľ���,Ȼ�����i->j�����ߵ�Ȩֵ
                        ע�������Ǵ��յ��������
                        */
                    }
        cout<<dp[0][0]<<endl;
    }
}

