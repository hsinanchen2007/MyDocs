#include<iostream>
#include<vector>
using namespace std;
int cnt=0;								//�ۼ����еĸ��� 
void disp(vector<int>&a)				//���һ����
{
	printf(" %2d: (",++cnt);
	for (int i=0;i<a.size()-1;i++)
		printf("%d,",a[i]);
	printf("%d)",a.back());
	printf("\n");
}
void dfs(vector<int>& a,int i)			//�ݹ��㷨 
{
	int n=a.size();
	if (i>=n-1)							//�ݹ����
		disp(a);
	else
	{	for (int j=n-1;j>=i;j--)
		{	swap(a[i],a[j]);			//����a[i]��a[j]
			dfs(a,i+1);
			swap(a[i],a[j]);			//����a[i]��a[j]���ָ�
		}
	}
}
void perm(vector<int>& a)				//��a��ȫ����
{
	dfs(a,0);
}
int main()
{
	vector<int> a={3,2,1};
	printf("a��ȫ����\n");
	perm(a);
	return 0;
}
