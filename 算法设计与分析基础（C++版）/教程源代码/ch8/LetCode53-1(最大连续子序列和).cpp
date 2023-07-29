/*
ִ�н����ͨ��
ִ����ʱ��8 ms, ������ C++ �ύ�л�����63.70%���û�
�ڴ����ģ�12.8 MB, ������ C++ �ύ�л�����64.34%���û�
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
	
