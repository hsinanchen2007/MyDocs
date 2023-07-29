/*
ִ�н����ͨ��
ִ����ʱ��8 ms, ������ C++ �ύ�л�����63.70%���û�
�ڴ����ģ�12.8 MB, ������ C++ �ύ�л�����64.34%���û�
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
