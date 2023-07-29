#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 30					//��ඥ����� 
int n;
vector<int> A[MAXN];			//�ڽӱ� 
int cnt;						//ȫ�ֱ������ۼƽ����
int x[MAXN];					//ȫ�ֱ�����x[i]��ʾ����i����ɫ
bool judge(int i,int j)				//�ж϶���i�Ƿ����Ⱦ����ɫj 
{
    for(int k=0;k<A[i].size();k++)
    {
        if(x[A[i][k]]==j)		//������ͬ��ɫ�Ķ��� 
            return false;
    }
    return true;
}
void dfs(int m,int i)			//�ݹ�����㷨 
{
    if(i>=n)					//�ﵽһ��Ҷ�ӽ�� 
        cnt++;
    else
    {
    	for(int j=0;j<m;j++)
    	{
        	x[i]=j;				//�ö���iΪ��ɫj 
        	if(judge(i,j))	//������i����Ⱦ����ɫj
            	dfs(m,i+1);
            x[i]=-1; 			//���� 
    	}
	}
}
int Colors(int m)				//��ͼ��m��ɫ����
{
	cnt=0;
	memset(x,0xff,sizeof(x));		//����Ԫ�س�ʼ��Ϊ-1 
	dfs(m,0);						//�Ӷ���0��ʼ����
	return cnt;
}
int main()
{
	n=4;
	A[0]={1,2,3};
	A[1]={0};
	A[2]={0,3};
	A[3]={0,2};
	int m=3;
	printf("����%d����ɫ����\n",Colors(m));
	return 0;
}


