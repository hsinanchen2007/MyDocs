class Soluion {
public:
	int maxCoins(vector<int>& nums)
    	{	nums.insert(nums.begin(),1);   			//nums前后尾插入1，不影响结果
        	nums.push_back(1);
        	int n=nums.size();
        	vector<vector<int>> dp(n,vector<int>(n,0));
        	for (int len=3;len<=n;len++)
            	for (int i=0;i+len-1<n;i++)
            	{	int j=i+len-1;              			//区间[i,j]的长度为len
                		for (int m=i+1;m<j;m++)			//分割点为m
                    		dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
            	}
        	return dp[0][n-1];
    	}
};
/*
执行结果：通过
执行用时：600 ms, 在所有 C++ 提交中击败了73.39%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了57.57%的用户
*/

class Solution {
public:
	int maxCoins(vector<int>& nums)
    {	nums.insert(nums.begin(),1);   			//nums前后尾插入1，不影响结果
       	nums.push_back(1);
       	int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--)
		{
            for(int j=i+1;j<n;j++)
			{
                if(j-i>=2)		//区间长度至少为3时 
                {
                	for(int m=i+1;m<j;m++)
                    	dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
/*
执行结果：通过
执行用时：596 ms, 在所有 C++ 提交中击败了74.87%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了65.59%的用户
*/
