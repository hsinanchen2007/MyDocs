#include<iostream>
#include<vector>
using namespace std;
//int n=4,t=31;
//vector<int> a={11,13,24,7};							//�����������
int n=4,t=8;
vector<int> a={3,1,5,2};							//�����������
int cnt=0;													//�ۼƽ����
void disp(vector<int>&x)								//���һ����
{	printf("  ��%d����  ",++cnt);
	printf("ѡȡ����Ϊ");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d ",a[i]);
	printf("\n");
}
int sum=0;											//�ۼ����������� 
void dfs(int cs,int rs,vector<int>&x,int i) 		//�ݹ��㷨
{	//csΪ���ǵ�i������ʱѡȡ�������ͣ�rsΪʣ��������
	sum++;
	printf("[%d,%d]\n",cs,rs);
	if (i>=n)												//�ҵ�һ��Ҷ�ӽ��
	{	if (cs==t)											//�ҵ�һ�����������Ľ�,���
			disp(x);
	}
	else													//û�е���Ҷ�ӽ��
	{
		rs-=a[i];											//��ʣ���������
		if (cs+a[i]<=t)										//���ӽ���֧
		{	x[i]=1;											//ѡȡ����a[i]
			dfs(cs+a[i],rs,x,i+1);
		}
		else 
			printf("���֧[%d,%d]\n",cs+a[i],rs);
		
		if (cs+rs>=t)										//�Һ��ӽ���֧
		{	x[i]=0;											//��ѡȡ����a[i]
			dfs(cs,rs,x,i+1);
		}
		else
			printf("�Ҽ�֧[%d,%d]\n",cs,rs);
		rs+=a[i];											//�ָ�ʣ��������
	}
}
void subs3()													//����Ӽ�������
{	vector<int> x(n);										//������
	int rs=0;												//��ʾ����������
	for (int j=0;j<n;j++)									//��rs
		rs+=a[j];
	dfs(0,rs,x,0);											//i��0��ʼ	
}
int main()
{
	printf("�Ӽ��������\n"); 
	subs3();
	printf("sum=%d\n",sum);
	return 0;
}
