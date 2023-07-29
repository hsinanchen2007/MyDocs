class Solution {
public:
	string longestPalindrome(string s)
    	{	int n=s.size();
        	if (n==1) return s; 
        	bool dp[n][n];
        	memset(dp,false,sizeof(dp));
        	string ans="";
        	for (int len=1;len<=n;len++)				//按长度len枚举区间[i,j]
        	{	for (int i=0;i+len-1<n;i++)
            	{	int j=i+len-1;
                		if (len==1) 						//区间中只有一个字符时为回文子串
                    		dp[i][j]=true;
                		else if (len==2)					//区间长度为2的情况
                    		dp[i][j]=(s[i]==s[j]);
                		else								//区间长度>2的情况
                    		dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                		if (dp[i][j] && len>ans.size())		//求最长的回文子串
                    		ans=s.substr(i,len);
            	}
        	}
        	return ans;
    }
};

