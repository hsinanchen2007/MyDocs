class Soluion {
public:
	int maxCoins(vector<int>& nums)
    	{	nums.insert(nums.begin(),1);   			//numsǰ��β����1����Ӱ����
        	nums.push_back(1);
        	int n=nums.size();
        	vector<vector<int>> dp(n,vector<int>(n,0));
        	for (int len=3;len<=n;len++)
            	for (int i=0;i+len-1<n;i++)
            	{	int j=i+len-1;              			//����[i,j]�ĳ���Ϊlen
                		for (int m=i+1;m<j;m++)			//�ָ��Ϊm
                    		dp[i][j]=max(dp[i][j],nums[i]*nums[m]*nums[j]+dp[i][m]+dp[m][j]);
            	}
        	return dp[0][n-1];
    	}
};
/*
ִ�н����ͨ��
ִ����ʱ��600 ms, ������ C++ �ύ�л�����73.39%���û�
�ڴ����ģ�9.9 MB, ������ C++ �ύ�л�����57.57%���û�
*/

class Solution {
public:
	int maxCoins(vector<int>& nums)
    {	nums.insert(nums.begin(),1);   			//numsǰ��β����1����Ӱ����
       	nums.push_back(1);
       	int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--)
		{
            for(int j=i+1;j<n;j++)
			{
                if(j-i>=2)		//���䳤������Ϊ3ʱ 
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
ִ�н����ͨ��
ִ����ʱ��596 ms, ������ C++ �ύ�л�����74.87%���û�
�ڴ����ģ�9.9 MB, ������ C++ �ύ�л�����65.59%���û�
*/
