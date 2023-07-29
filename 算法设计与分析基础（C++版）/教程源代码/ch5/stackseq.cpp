#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int sum=0;								//累计出栈序列的个数 
vector<int> a={1,2,3,4};					//进栈序列 
int n=a.size();							//进栈序列的元素个数
stack<int> st;
void disp(vector<int>& x)					//输出一个解 
{
	printf("  出栈序列%2d: ",++sum);
	for (int i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void dfs(vector<int>& x,int i,int j)		//递归算法
{
	if (i==n && j==n)						//输出一种可能的方案
		disp(x);
	else
	{ 
		if (i<n)							//i<n时a[i]进栈
		{
			st.push(a[i]);					//a[i]进栈
			dfs(x,i+1,j);
			st.pop();						//回溯:出栈
		}
		if (!st.empty())		 			//栈不空时出栈x 
		{	int tmp=st.top(); st.pop();		//出栈x
			x[j]=tmp; 						//将x添加到x中
			j++;							//j增加1 
			dfs(x,i,j);
			j--;							//回溯:j减少1 
			st.push(tmp);					//回溯:x进栈以恢复环境
		}
	}
}
void solve()								//求a的所有合法的出栈序列 
{
	vector<int> x(n);
	dfs(x,0,0);							//i,j均从0开始
}
int main()
{
	printf("所有输出序列:\n");
	solve();
	printf("  共有%d个合法的出栈序列\n",sum);
	return 0;
}

