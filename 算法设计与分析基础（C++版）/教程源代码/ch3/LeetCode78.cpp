#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> Mi;						//����ݼ�
		vector<vector<int>> Mi_1={{},{nums[0]}};	//���M1
		if(nums.size()==1) return Mi_1;
		for(int i=1;i<nums.size();i++)
	    {
    		vector<vector<int>> Ai=appendi(Mi_1,nums[i]);
    		Mi=Mi_1;
	        for(int j=0;j<Ai.size();j++)          //��Ai���м���Ԫ����ӵ�Mi��
    	    	Mi.push_back(Ai[j]);
	        Mi_1=Mi;
		}
		return Mi;
    }
	vector<vector<int>> appendi(vector<vector<int>> Mi_1,int e)	//��Mi_1��ÿ������Ԫ��ĩβ���e
	{
		vector<vector<int>> Ai=Mi_1;
		for(int j=0;j<Ai.size();j++)
			Ai[j].push_back(e);
		return Ai;	
	}  
};
void disp(vector<vector<int>> ans)			//����ݼ� 
{
	printf("    ");
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if((*it).size()==0)
			printf("{} ");
		else
		{
			printf("[");
		   	for(int j=0;j<(*it).size();j++)
		   		if(j==0)
				printf("%d",(*it)[j]);
			else
				printf(" %d",(*it)[j]);
			printf("]  ");
		}
	}
	printf("\n");
}
int main()
{
	vector<int> nums={1};
	vector<vector<int>> ans;
	printf(" �ݼ�����:\n  ");
	Solution obj;
	ans=obj.subsets(nums);
	disp(ans);
	return 0;
}
