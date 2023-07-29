#include <stdio.h>
#include<vector> 
#include <string.h>
using namespace std;
class Solution {
    vector<vector<int>> ps;         //存放nums的全排序
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
    	int n=nums.size();
		dfs(nums,n,0);
        return ps;
    }
    void dfs(vector<int>&x,int n,int i)			//递归算法
    {
        if (i>=n)								//到达叶子结点
            ps.push_back(x);
	    else									//没有到达叶子结点
	    {	for (int j=i;j<n;j++)				//遍历x[i..n-1]
		    {
			 	if(judge(x,i,j))				//检测x[j]
			 	{   swap(x[i],x[j]);			//i位置置分x[j] 
					dfs(x,n,i+1);				//继续
			    	swap(x[i],x[j]);			//回溯 
		    	}
			}
	    }
    }
    bool judge(vector<int>& x,int i,int j)
	//判断x[j]是否在x[i..j-1]中出现,若出现返回false，没有出现返回true 
	{
		if(j>i)
		{
			for(int k=i;k<j;k++)		//x[j]是否与x[i..j-1]的元素相同 
				if(x[k]==x[j])			//若相同则返回false 
					return false;
		}
		return true;					//全部不相同返回true 
	}

};
int main()
{
	vector<int> a={1,2,3};
	Solution obj;
	vector<vector<int>> ans=obj.permute(a);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
	
