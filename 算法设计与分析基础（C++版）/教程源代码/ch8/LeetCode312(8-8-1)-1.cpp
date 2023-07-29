#include<iostream>
#include<vector>
using namespace std;
//本文件用于调试 
class Solution {
public:
	int maxCoins(vector<int>& nums)
    {	nums.insert(nums.begin(),1);   			//nums前后尾插入1，不影响结果
       	nums.push_back(1);
       	int n=nums.size();
       	vector<vector<int>> dp(n,vector<int>(n,0));
       	for (int len=3;len<=n;len++)
       	{
       		printf("len=%d\n",len);
           	for (int i=0;i+len-1<n;i++)
           	{	int j=i+len-1;              			//区间[i,j]的长度为len
           		printf("   考虑区间[i,j]=[%d,%d]\n",i,j);
             	for (int m=i+1;m<j;m++)					//分割点为m
              	{
                	int tmp=dp[i][j];
                   	dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
                   	printf("      m=%d,dp[i][j]=%d->dp[%d][%d]=max(dp[i][j],a[%d]*a[%d]*a[%d]+dp[%d][%d]+dp[%d][%d]=%d\n",m,tmp,i,j,i,m,j,i,m,m,j,dp[i][j]);
            	}
            }
        }
        return dp[0][n-1];
    }
};
class Solution1 {
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
           			printf("   考虑区间[i,j]=[%d,%d]\n",i,j);
                	for(int m=i+1;m<j;m++)
					{
                		int tmp=dp[i][j];
                    	dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
                   	printf("      m=%d,dp[i][j]=%d->dp[%d][%d]=max(dp[i][j],a[%d]*a[%d]*a[%d]+dp[%d][%d]+dp[%d][%d]=%d\n",m,tmp,i,j,i,m,j,i,m,m,j,dp[i][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

class Solution2 {
public:
	int maxCoins(vector<int>& nums)
    {	nums.insert(nums.begin(),1);   			//nums前后尾插入1，不影响结果
       	nums.push_back(1);
       	int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
		{
            for(int j=i+1;j<n;j++)
			{
                if(j-i>=2)		//区间长度至少为3时 
                {
           			printf("   考虑区间[i,j]=[%d,%d]\n",i,j);
                	for(int m=i+1;m<j;m++)
					{
                		int tmp=dp[i][j];
                    	dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
                   		printf("      m=%d,dp[i][j]=%d->dp[%d][%d]=max(dp[i][j],a[%d]*a[%d]*a[%d]+dp[%d][%d]+dp[%d][%d]=%d\n",m,tmp,i,j,i,m,j,i,m,m,j,dp[i][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};


int main()
{
	freopen("xyz.txt","w",stdout);
	vector<int> a={2,1};
	Solution2 obj;
	cout << obj.maxCoins(a) << endl;
	return 0;
}
	
