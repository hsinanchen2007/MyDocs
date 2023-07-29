#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> Mi;						//存放幂集
		vector<vector<int>> Mi_1={{},{nums[0]}};	//存放M1
		if(nums.size()==1) return Mi_1;
		for(int i=1;i<nums.size();i++)
	    {
    		vector<vector<int>> Ai=appendi(Mi_1,nums[i]);
    		Mi=Mi_1;
	        for(int j=0;j<Ai.size();j++)          //将Ai所有集合元素添加到Mi中
    	    	Mi.push_back(Ai[j]);
	        Mi_1=Mi;
		}
		return Mi;
    }
	vector<vector<int>> appendi(vector<vector<int>> Mi_1,int e)	//向Mi_1中每个集合元素末尾添加e
	{
		vector<vector<int>> Ai=Mi_1;
		for(int j=0;j<Ai.size();j++)
			Ai[j].push_back(e);
		return Ai;	
	}  
};
void disp(vector<vector<int>> ans)			//输出幂集 
{
	printf("    ");
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if((*it).size()==0)
			printf("{} ");
		else
		{
			printf("[");
		   	for(int j=0;j<(*it).size();j++)
		   		if(j==0)
				printf("%d",(*it)[j]);
			else
				printf(" %d",(*it)[j]);
			printf("]  ");
		}
	}
	printf("\n");
}
int main()
{
	vector<int> nums={1};
	vector<vector<int>> ans;
	printf(" 幂集如下:\n  ");
	Solution obj;
	ans=obj.subsets(nums);
	disp(ans);
	return 0;
}
