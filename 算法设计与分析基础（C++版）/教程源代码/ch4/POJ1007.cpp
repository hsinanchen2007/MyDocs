#include<iostream> 
#include<cstring> 
using namespace std;
#define MAXN 55
#define MAXM 105 
struct SNode								//Ԫ������
{	char str[MAXN];							//�ַ���
	int inv;									//������
} a[MAXM];
void BubbleSort(SNode a[],int m) 			//ð������:��inv��������
{	for (int i=0;i<m-1;i++) 
	{	bool exchange=false;					//����ǰ��exchange��Ϊfalse
		for (int j=m-1;j>i;j--)				//һ�����ҳ���С�ؼ��ֵ�Ԫ��
			if (a[j].inv<a[j-1].inv)			//����ʱ����
			{	swap(a[j],a[j-1]);
				exchange=true;				//���˷���������exchangeΪtrue
			}
		if (!exchange)						//����û�з�����������;�����㷨
			return;
	}
}
int main()
{	int n,m;
	char s[MAXN]; 
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{	scanf("%s",s);
		int cnt=0; 
		for(int j=0;j<n;j++)							//���ַ���s��������
			for(int k=0;k<j;k++)
				if(s[j]<s[k])
					cnt++;  							//�ۼ�������
		strcpy(a[i].str,s);
		a[i].inv=cnt;
	}
	BubbleSort(a,m);									//����
	for(int i=0;i<m;i++)								//������
		printf("%s\n",a[i].str);
	return 0;
}

