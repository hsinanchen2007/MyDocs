class Solution {
public:
	string longestPalindrome(string s)
    	{	int n=s.size();
        	if (n==1) return s; 
        	bool dp[n][n];
        	memset(dp,false,sizeof(dp));
        	string ans="";
        	for (int len=1;len<=n;len++)				//������lenö������[i,j]
        	{	for (int i=0;i+len-1<n;i++)
            	{	int j=i+len-1;
                		if (len==1) 						//������ֻ��һ���ַ�ʱΪ�����Ӵ�
                    		dp[i][j]=true;
                		else if (len==2)					//���䳤��Ϊ2�����
                    		dp[i][j]=(s[i]==s[j]);
                		else								//���䳤��>2�����
                    		dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                		if (dp[i][j] && len>ans.size())		//����Ļ����Ӵ�
                    		ans=s.substr(i,len);
            	}
        	}
        	return ans;
    }
};

