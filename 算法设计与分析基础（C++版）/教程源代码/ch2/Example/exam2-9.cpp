#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> topk1(vector<int>&v,int k)		//解法1的算法 
{
	vector<int> ans;
	priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());
	for(int i=1;i<=k;i++)
	{
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}
vector<int> topk2(vector<int>&v,int k)		//解法2的算法 
{
	vector<int> ans(k);						//指定ans的长度为k 
	priority_queue<int> pq;					//大根堆 
	for(int i=0;i<k;i++)					//将前k个整数进队 
		pq.push(v[i]);
	for(int i=k;i<v.size();i++)
	{
		if(v[i]<pq.top())
		{
			pq.pop();
			pq.push(v[i]);
		}
	}
	int j=k-1; 
	while(!pq.empty())
	{
		ans[j--]=pq.top();
		pq.pop();
	}
	return ans;
}
	
int main()
{
	vector<int> v={2,5,3,1,4};
	printf("v: ");
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	int k=3;
	vector<int> ans=topk2(v,k);
	printf("前%d个最小整数: ",k);
	for(auto e:ans)
		printf("%d ",e);
	printf("\n");
	return 0;
}
