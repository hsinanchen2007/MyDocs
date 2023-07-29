#include<iostream>
using namespace std;
#define MAXN 20					//���ʺ����
int q[MAXN];					//��Ÿ��ʺ����ڵ��к�,Ϊȫ�ֱ���
int cnt=0;						//�ۼƽ����
void disp(int n)   				//���һ����
{
	printf("  ��%d����:",++cnt);
	for (int i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
bool place(int i,int j)				//����(i,j)λ���ܷ�ڷŻʺ�
{	if (i==1) return true;			//��һ���ʺ����ǿ��Է���
	int k=1;
	while (k<i)						//k=1��i-1���ѷ����˻ʺ����
	{	if ((q[k]==j) || (abs(q[k]-j)==abs(i-k)))
			return false;
		k++;
	}
	return true;
}
//-----------�ݹ�ⷨ------------------------ 
void queen11(int n,int i)			//�����㷨 
{	if (i>n) 
		disp(n);					//���лʺ���ý���
	else
	{	for (int j=1;j<=n;j++)		//�ڵ�i������̽ÿһ����j
			if (place(i,j))			//�ڵ�i�����ҵ�һ������λ��(i,j)
			{	q[i]=j;
				queen11(n,i+1);
				q[i]=0;				//���� 
			}
	}
}
void queen1(int n)				//�ݹ鷨���n�ʺ�����
{
	queen11(n,1);
} 

//-----------�����ⷨ------------------------ 
void queen2(int n)						//���������n�ʺ�����
{
	int i=1;							//i��ʾ��ǰ��,Ҳ��ʾ���õ�i���ʺ�
	q[i]=0;								//q[i]�ǵ�ǰ��,��0�м���ͷ��̽
	while (i>=1)						//�ظ���̽
	{
		q[i]++;
		while (q[i]<=n && !place(i,q[i]))	//��̽һ��λ��(i,q[i])
			q[i]++;
		if (q[i]<=n)					//Ϊ��i���ʺ��ҵ���һ������λ��(i,q[i])
		{
			if (i==n)					//�����������лʺ�,���һ����
				disp(n);
			else						//�ʺ�û�з�����
			{
				i++;					//ת����һ��,����ʼ��һ���ʺ�ķ���
				q[i]=0;					//ÿ�η�һ���»ʺ�,���Ӹ��е���ͷ������̽
			}
		}
		else i--;						//����i���ʺ��Ҳ������ʵ�λ��,����ݵ���һ���ʺ�
	}
}

int main()
{	int n=6;								//n���ʵ�ʻʺ����
	printf("%d�ʺ������������:\n",n);
	queen1(n);
	return 0;
}
