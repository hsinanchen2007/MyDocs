#include<iostream>
using namespace std;
#define MAX 101
//�����ʾ
int k;
//�������ʾ
int a[MAX][MAX];						//��ű����ճ̱������±�Ϊ0��Ԫ�ز��ã�
void Plan11(int k)						//��Plan1����
{
	if(k==1)							//���2��ѡ�ֱ����ճ�
	{	a[1][1]=1; a[1][2]=2;
		a[2][1]=2; a[2][2]=1;
	}
	else
	{
		Plan11(k-1);
		int n=1<<(k-1);
		for (int i=n+1;i<=2*n;i++ )			//�����½�Ԫ��
			for (int j=1;j<=n; j++)
				a[i][j]=a[i-n][j]+n; 		//���½�Ԫ�غ����Ͻ�Ԫ�صĶ�Ӧ��ϵ
		for (int i=1;i<=n;i++)				//�����Ͻ�Ԫ��
			for (int j=n+1;j<=2*n;j++)
				a[i][j]=a[i+n][(j+n)%(2*n)];
		for (int i=n+1;i<=2*n;i++)			//�����½�Ԫ��
			for (int j=n+1;j<=2*n; j++)
				a[i][j]=a[i-n][j-n];
    }
}
void Plan1(int k)						//�ݹ��㷨�����ѭ���ճ̰������� 
{
	Plan11(k);
}

void Plan2(int k)						//�����㷨�����ѭ���ճ̰������� 
{
	int n=2;							//n��2^1=2��ʼ
	a[1][1]=1; a[1][2]=2;   			//���2��ѡ�ֱ����ճ�,�õ����Ͻ�Ԫ��
	a[2][1]=2; a[2][2]=1;
	for (int t=1;t<k;t++)					//��������,������2^2����,2^k��ѡ�ֵİ��� 
	{
		int tmp=n;								//tmp=2^t
		n=n*2; 									//n=2^(t+1)
		for (int i=tmp+1;i<=n;i++ )			//�����½�Ԫ��
			for (int j=1;j<=tmp; j++)
				a[i][j]=a[i-tmp][j]+tmp; 	//���½�Ԫ�غ����Ͻ�Ԫ�صĶ�Ӧ��ϵ
		for (int i=1;i<=tmp; i++)				//�����Ͻ�Ԫ��
			for (int j=tmp+1;j<=n; j++)
				a[i][j]=a[i+tmp][(j+tmp)% n];
		for (int i=tmp+1; i<=n; i++)			//�����½�Ԫ��
			for (int j=tmp+1;j<=n; j++)
				a[i][j]=a[i-tmp][j-tmp];
    }
}

int main()
{
	k=3;
	int n=1<<k;							//n����2��k�η���n=2^k
	printf("n=%d\n",n);
	printf("�ݹ��㷨:\n"); 
	Plan1(k);							//����n��ѡ�ֵı����ճ̱�
	for(int i=1; i<=n; i++)				//��������ճ̱�
	{	for(int j=1; j<=n; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	printf("�����㷨:\n"); 
	Plan2(k);							//����n��ѡ�ֵı����ճ̱�
	for(int i=1; i<=n; i++)				//��������ճ̱�
	{	for(int j=1; j<=n; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
