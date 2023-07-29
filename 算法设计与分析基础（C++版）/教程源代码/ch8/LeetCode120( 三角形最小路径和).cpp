class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)					//自顶向下 
	{
		int n=triangle.size();
        int dp[MAXN][MAXN];
		dp[0][0]=triangle[0][0];
		for(int i=1;i<n;i++)										//考虑第0列的边界
			dp[i][0]=dp[i-1][0]+triangle[i][0];
		for (int i=1;i<n;i++)										//考虑对角线的边界
			dp[i][i]=triangle[i][i]+dp[i-1][i-1];
		for(int i=2;i<n;i++)										//考虑其他有两条达到的路径
		{	for(int j=1;j<i;j++)
				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
		}
		int ans=dp[n-1][0];
		for (int j=1;j<n;j++)										//求出最小ans
			ans=min(ans,dp[n-1][j]);
		return ans;
	}
};


/*
执行结果：通过
执行用时：4ms, 在所有 C++ 提交中击败了91.66%的用户
内存消耗：8.4MB, 在所有 C++ 提交中击败了44.55%的用户
*/


class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)				//自底向上
	{
		int n=triangle.size();
        int dp[MAXN][MAXN];
        for(int j=0;j<n;j++)
        	dp[n-1][j]=triangle[n-1][j];						//第n-1行 
		for(int i=n-2;i>=0;i--)										//考虑第0列的边界
			dp[i][0]=dp[i+1][0]+triangle[i][0];
		for (int i=n-2;i>=0;i--)										//考虑对角线的边界
			dp[i][i]=triangle[i][i]+dp[i+1][i+1];
		for(int i=n-2;i>=0;i--)										//考虑其他有两条达到的路径
		{	for(int j=0;j<triangle[i].size();j++)
				dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
		}
		return dp[0][0];
	}
};
/*
执行结果：通过
执行用时：4ms, 在所有 C++ 提交中击败了91.66%的用户
内存消耗：8.4MB, 在所有 C++ 提交中击败了44.55%的用户
*/


class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)			//自底向上的优化算法 
	{
		int n=triangle.size();
        int dp[MAXN];
    	memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
		{
            //从左到右的方式计算
            for(int j=0;j<triangle[i].size();j++)
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
        }
        //dp数组的第一个元素即为最终结果
        return dp[0];
	}
};
/*
执行结果：通过
执行用时：4ms, 在所有 C++ 提交中击败了91.66%的用户
内存消耗：8.1MB, 在所有 C++ 提交中击败了44.55%的用户
*/

