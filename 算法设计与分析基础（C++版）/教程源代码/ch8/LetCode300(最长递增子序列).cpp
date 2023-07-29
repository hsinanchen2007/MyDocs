/*
执行结果：通过
执行用时：196 ms, 在所有 C++ 提交中击败了68.11%的用户
内存消耗：10.1 MB, 在所有 C++ 提交中击败了90.21%的用户
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
	{	int n=nums.size();
        int dp[n];
		int ans=0; 
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
			for(int j=0;j<i;j++)
			{
				if (nums[i]>nums[j])
					dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		return ans;
	}
};
