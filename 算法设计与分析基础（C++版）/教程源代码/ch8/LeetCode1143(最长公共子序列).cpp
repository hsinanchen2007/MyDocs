class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.size();
        int n=text2.size();
        if(m==0 || n==0)
            return 0;
        vector<int> dp(n+1,0);
        for (int i=1;i<=m;i++)
        {
            int upLeft=dp[0]; // 每行开始的时候需要更新下upleft, 这里其实每次都是0
            for (int j=1;j<=n;j++)
            {
                int tmp=dp[j]; // 记录未被覆盖之前的dp[j], 它会在计算 j+1的时候作为upLeft用到
                if (text1[i-1]==text2[j-1])
                    dp[j]=upLeft+1;
                else
                    dp[j]=max(dp[j-1],dp[j]);
                upLeft=tmp; // 更新upLeft
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.size();
        int n=text2.size();
        if(m==0 || n==0)
            return 0;
        vector<int> dp(n+1,0);
        for (int i=1;i<=m;i++)
        {
            int upLeft=dp[0]; // 每行开始的时候需要更新下upleft, 这里其实每次都是0
            for (int j=1;j<=n;j++)
            {
                int tmp=dp[j]; // 记录未被覆盖之前的dp[j], 它会在计算 j+1的时候作为upLeft用到
                if (text1[i-1]==text2[j-1])
                    dp[j]=upLeft+1;
                else
                    dp[j]=max(dp[j-1],dp[j]);
                upLeft=tmp; // 更新upLeft
            }
        }
        return dp[n];
    }
};

class Solution {
    public int maxValue(int N, int C, int[] v, int[] w) {
        int[] dp = new int[C + 1];
        for (int i = 0; i < N; i++) {
            for (int j = C; j >= v[i]; j--) {
                // 不选该物品
                int n = dp[j]; 
                // 选择该物品
                int y = dp[j-v[i]] + w[i]; 
                dp[j] = Math.max(n, y);
            }
        }
        return dp[C];
    }
}
