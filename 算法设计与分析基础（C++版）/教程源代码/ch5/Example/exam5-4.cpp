#include<iostream>
#include<vector>
using namespace std;
int cnt=0;								//累计排列的个数 
void disp(vector<int>&a)				//输出一个解
{
	printf(" %2d: (",++cnt);
	for (int i=0;i<a.size()-1;i++)
		printf("%d,",a[i]);
	printf("%d)",a.back());
	printf("\n");
}
void dfs(vector<int>& a,int i)			//递归算法 
{
	int n=a.size();
	if (i>=n-1)							//递归出口
		disp(a);
	else
	{	for (int j=i;j<n;j++)
		{	swap(a[i],a[j]);			//交换a[i]与a[j]
			dfs(a,i+1);
			swap(a[i],a[j]);			//交换a[i]与a[j]：恢复
		}
	}
}
void perm(vector<int>& a)				//求a的全排列
{
	dfs(a,0);
}
int main()
{
	vector<int> a={1,2,3};
	printf("a的全排列\n");
	perm(a);
	return 0;
}
