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
            int upLeft=dp[0]; // ÿ�п�ʼ��ʱ����Ҫ������upleft, ������ʵÿ�ζ���0
            for (int j=1;j<=n;j++)
            {
                int tmp=dp[j]; // ��¼δ������֮ǰ��dp[j], �����ڼ��� j+1��ʱ����ΪupLeft�õ�
                if (text1[i-1]==text2[j-1])
                    dp[j]=upLeft+1;
                else
                    dp[j]=max(dp[j-1],dp[j]);
                upLeft=tmp; // ����upLeft
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
            int upLeft=dp[0]; // ÿ�п�ʼ��ʱ����Ҫ������upleft, ������ʵÿ�ζ���0
            for (int j=1;j<=n;j++)
            {
                int tmp=dp[j]; // ��¼δ������֮ǰ��dp[j], �����ڼ��� j+1��ʱ����ΪupLeft�õ�
                if (text1[i-1]==text2[j-1])
                    dp[j]=upLeft+1;
                else
                    dp[j]=max(dp[j-1],dp[j]);
                upLeft=tmp; // ����upLeft
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
                // ��ѡ����Ʒ
                int n = dp[j]; 
                // ѡ�����Ʒ
                int y = dp[j-v[i]] + w[i]; 
                dp[j] = Math.max(n, y);
            }
        }
        return dp[C];
    }
}
