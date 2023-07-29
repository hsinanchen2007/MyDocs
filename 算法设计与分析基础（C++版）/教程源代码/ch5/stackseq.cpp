#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int sum=0;								//�ۼƳ�ջ���еĸ��� 
vector<int> a={1,2,3,4};					//��ջ���� 
int n=a.size();							//��ջ���е�Ԫ�ظ���
stack<int> st;
void disp(vector<int>& x)					//���һ���� 
{
	printf("  ��ջ����%2d: ",++sum);
	for (int i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void dfs(vector<int>& x,int i,int j)		//�ݹ��㷨
{
	if (i==n && j==n)						//���һ�ֿ��ܵķ���
		disp(x);
	else
	{ 
		if (i<n)							//i<nʱa[i]��ջ
		{
			st.push(a[i]);					//a[i]��ջ
			dfs(x,i+1,j);
			st.pop();						//����:��ջ
		}
		if (!st.empty())		 			//ջ����ʱ��ջx 
		{	int tmp=st.top(); st.pop();		//��ջx
			x[j]=tmp; 						//��x��ӵ�x��
			j++;							//j����1 
			dfs(x,i,j);
			j--;							//����:j����1 
			st.push(tmp);					//����:x��ջ�Իָ�����
		}
	}
}
void solve()								//��a�����кϷ��ĳ�ջ���� 
{
	vector<int> x(n);
	dfs(x,0,0);							//i,j����0��ʼ
}
int main()
{
	printf("�����������:\n");
	solve();
	printf("  ����%d���Ϸ��ĳ�ջ����\n",sum);
	return 0;
}

