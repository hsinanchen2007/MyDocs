#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 51
//�����ʾ
struct Action				//����� 
{	int b;					//���ʼʱ��
	int e;					//�����ʱ��
	bool operator<(const Action &s) const
	{
		return e<=s.e;			//���ڰ������ʱ���������
	}
};
//�������ʾ
bool flag[MAX];						//���ѡ��Ļ
void greedly(vector<Action>& A)		//��������ݻ�Ӽ�
{
	int n=A.size();
	memset(flag,0,sizeof(flag));//��ʼ��Ϊfalse
	sort(A.begin(),A.end());			//A[1..n]�������ʱ���������
	int preend=0;				//ǰһ�����ݻ�Ľ���ʱ��
	for (int i=0;i<n;i++)
	{	if (A[i].b>=preend)
		{	flag[i]=true;		//ѡ��A[i]�
			preend=A[i].e;
		}
	}
}
int main()
{
	vector<Action> A={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};
	int cnt=0;					//ѡȡ�ļ��ݻ����
	greedly(A);
	printf("�����\n");
	printf("  ѡȡ�Ļ:");
	for (int i=0;i<A.size();i++)
		if (flag[i])
		{
			printf("[%d,%d] ",A[i].b,A[i].e);
			cnt++;
		}
	printf("\n  ��%d���\n",cnt);
	return 0;
}
