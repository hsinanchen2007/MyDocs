/*
执行结果：通过
执行用时：8 ms, 在所有 C++ 提交中击败了63.70%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了64.34%的用户
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        for(int j=1;j<n;j++)
            dp[j]=max(dp[j-1]+nums[j],nums[j]);
        int ans=dp[0];
        for(int j=1;j<n;j++)
            ans=max(ans,dp[j]);
        return ans;
    }
};
