class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)					//�Զ����� 
	{
		int n=triangle.size();
        int dp[MAXN][MAXN];
		dp[0][0]=triangle[0][0];
		for(int i=1;i<n;i++)										//���ǵ�0�еı߽�
			dp[i][0]=dp[i-1][0]+triangle[i][0];
		for (int i=1;i<n;i++)										//���ǶԽ��ߵı߽�
			dp[i][i]=triangle[i][i]+dp[i-1][i-1];
		for(int i=2;i<n;i++)										//���������������ﵽ��·��
		{	for(int j=1;j<i;j++)
				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
		}
		int ans=dp[n-1][0];
		for (int j=1;j<n;j++)										//�����Сans
			ans=min(ans,dp[n-1][j]);
		return ans;
	}
};


/*
ִ�н����ͨ��
ִ����ʱ��4ms, ������ C++ �ύ�л�����91.66%���û�
�ڴ����ģ�8.4MB, ������ C++ �ύ�л�����44.55%���û�
*/


class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)				//�Ե�����
	{
		int n=triangle.size();
        int dp[MAXN][MAXN];
        for(int j=0;j<n;j++)
        	dp[n-1][j]=triangle[n-1][j];						//��n-1�� 
		for(int i=n-2;i>=0;i--)										//���ǵ�0�еı߽�
			dp[i][0]=dp[i+1][0]+triangle[i][0];
		for (int i=n-2;i>=0;i--)										//���ǶԽ��ߵı߽�
			dp[i][i]=triangle[i][i]+dp[i+1][i+1];
		for(int i=n-2;i>=0;i--)										//���������������ﵽ��·��
		{	for(int j=0;j<triangle[i].size();j++)
				dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
		}
		return dp[0][0];
	}
};
/*
ִ�н����ͨ��
ִ����ʱ��4ms, ������ C++ �ύ�л�����91.66%���û�
�ڴ����ģ�8.4MB, ������ C++ �ύ�л�����44.55%���û�
*/


class Solution {
    const int MAXN=210;
public:
	int minimumTotal(vector<vector<int>>& triangle)			//�Ե����ϵ��Ż��㷨 
	{
		int n=triangle.size();
        int dp[MAXN];
    	memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
		{
            //�����ҵķ�ʽ����
            for(int j=0;j<triangle[i].size();j++)
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
        }
        //dp����ĵ�һ��Ԫ�ؼ�Ϊ���ս��
        return dp[0];
	}
};
/*
ִ�н����ͨ��
ִ����ʱ��4ms, ������ C++ �ύ�л�����91.66%���û�
�ڴ����ģ�8.1MB, ������ C++ �ύ�л�����44.55%���û�
*/

