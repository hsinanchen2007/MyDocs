#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> topck(vector<int>&v,int k)		//求解算法 
{
	vector<int> ans;						//存放结果 
	map<int,int,greater<int>> mp;
	for(auto e:v)
		mp[e]++;
	auto it=mp.begin();						//定义s的迭代器 
	for(int i=1;i<=k;i++)					//求前k个最大整数的出现次数 
	{
		ans.push_back(it->first);
		ans.push_back(it->second);
		it++;
	}
	return ans;
}
	
int main()
{
	vector<int> v={1,4,6,2,5,6,3,2,1,5,4};
	printf("v: ");
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");	
	for(int k=1;k<=6;k++)
	{
		printf("前%d大整数出现次数:  ",k);
		vector<int> ans=topck(v,k);
		for(int i=0;i<ans.size();i+=2)
			printf("%d : %d   ",ans[i],ans[i+1]);
		printf("\n");
	}
	return 0;
}
