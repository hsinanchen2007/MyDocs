/*
执行结果：通过
执行用时：8 ms, 在所有 C++ 提交中击败了63.70%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了64.34%的用户
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1) return nums[0];
        int dp;
        dp=nums[0];
        int ans=dp;
        for(int j=1;j<n;j++)
        {
            dp=max(dp+nums[j],nums[j]);
            ans=max(ans,dp);
    	}
        return ans;
    }
};
int main()
{
	vector<int> a={-1,-2};
	Solution obj;
	printf("ans=%d\n",obj.maxSubArray(a));
	return 0;
}
	
