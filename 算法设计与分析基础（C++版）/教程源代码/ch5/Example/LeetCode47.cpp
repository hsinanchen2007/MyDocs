#include <stdio.h>
#include<vector> 
#include <string.h>
using namespace std;
class Solution {
    vector<vector<int>> ps;         //���nums��ȫ����
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
    	int n=nums.size();
		dfs(nums,n,0);
        return ps;
    }
    void dfs(vector<int>&x,int n,int i)			//�ݹ��㷨
    {
        if (i>=n)								//����Ҷ�ӽ��
            ps.push_back(x);
	    else									//û�е���Ҷ�ӽ��
	    {	for (int j=i;j<n;j++)				//����x[i..n-1]
		    {
			 	if(judge(x,i,j))				//���x[j]
			 	{   swap(x[i],x[j]);			//iλ���÷�x[j] 
					dfs(x,n,i+1);				//����
			    	swap(x[i],x[j]);			//���� 
		    	}
			}
	    }
    }
    bool judge(vector<int>& x,int i,int j)
	//�ж�x[j]�Ƿ���x[i..j-1]�г���,�����ַ���false��û�г��ַ���true 
	{
		if(j>i)
		{
			for(int k=i;k<j;k++)		//x[j]�Ƿ���x[i..j-1]��Ԫ����ͬ 
				if(x[k]==x[j])			//����ͬ�򷵻�false 
					return false;
		}
		return true;					//ȫ������ͬ����true 
	}

};
int main()
{
	vector<int> a={1,2,3};
	Solution obj;
	vector<vector<int>> ans=obj.permute(a);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
	
