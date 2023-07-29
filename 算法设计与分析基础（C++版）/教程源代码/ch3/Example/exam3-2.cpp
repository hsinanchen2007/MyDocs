#include<iostream>
#include<math.h>
using namespace std;
const int MAXD=20005;						//��������ȡֵ
bool isPrime(int x)							//�ж�x�Ƿ�������
{	for (int i=2;i<=(int)sqrt(x);i++)
		if (x%i==0)							//x�ܹ���i����
			return false;
	return true;
}
int Count1(int a,int b)			//��a��b���������� 
{
	if (a>b) return 0;
	int cnt=0;
	for(int x=a;x<=b;x++)
		if(isPrime(x))
			cnt++;
	return cnt;
}
void solve1(int a[],int b[],int n)
{
	for(int i=0;i<n;i++)
		printf("  %d-%d֮�����������=%d\n",a[i],b[i],Count1(a[i],b[i]));
}

int prime[MAXD];								//prime[i]=1��ʾi������ 
void Init()										//���prime 
{	for(int i=0;i<=MAXD;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i<=MAXD;i++)
	{	if(prime[i])
		{							//��i������
			for(int j=2*i;j<=MAXD;j+=i)			//��i�ı�������������
				prime[j]=0;
		}
	}
}
void solve2(int a[],int b[],int n)				//����㷨
{
	Init();
	for(int i=2;i<=MAXD;i++)					//prime[i]�ۼ�С�ڵ���i���������� 
		prime[i]+=prime[i-1];
	for(int i=0;i<n;i++)
		printf("  %d-%d֮�����������=%d\n",a[i],b[i],prime[b[i]]-prime[a[i]-1]);
}
int main()
{
	int a[]={2,5,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	int b[]={3,10,100,5000};
	printf("�ⷨ1\n"); 
	solve1(a,b,n);
	printf("�ⷨ2\n"); 
	solve2(a,b,n);
	return 0;
}
