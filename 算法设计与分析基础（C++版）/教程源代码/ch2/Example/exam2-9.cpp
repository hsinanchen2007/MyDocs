#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> topk1(vector<int>&v,int k)		//�ⷨ1���㷨 
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
vector<int> topk2(vector<int>&v,int k)		//�ⷨ2���㷨 
{
	vector<int> ans(k);						//ָ��ans�ĳ���Ϊk 
	priority_queue<int> pq;					//����� 
	for(int i=0;i<k;i++)					//��ǰk���������� 
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
	printf("ǰ%d����С����: ",k);
	for(auto e:ans)
		printf("%d ",e);
	printf("\n");
	return 0;
}
