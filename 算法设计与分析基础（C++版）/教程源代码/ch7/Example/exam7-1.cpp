//LeetCode
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums)
	{
		int n=nums.size();
        if(n==1) return 0;
		int end=nums[0];		//��λ��i��һ�����������λ�� 
    	int maxp; 				//��[i..end]�ܹ���������Զλ��	
    	int steps=1;			//������Ծ���� 
		printf("��λ��0��һ��,steps=%d\n",steps);
    	int i=1,maxi;
    	while(i<n-1)			//����nums[0..n-2] 
		{
			maxp=0;
			while(i<n-1)		//��[i..end]�ܹ���������Զλ��maxp 
			{
                if(maxp<nums[i]+i)
                {
                    maxp=nums[i]+i;
                    maxi=i;					//maxiΪ��Զλ��maxp������λ�� 
                }
        		if(i==end) break;			//[i,end]��������˳�ѭ�� 
                i++;
        	}
            if(i<n-1)						//λ��i��Ч����һ������maxpλ�� 
            {
                end=maxp;
                steps++;
                i=maxi;
               printf("��λ��%d��һ��,steps=%d\n",maxi,steps);
            }
            else break;
    	}
    	return steps;
    }
};
/*

//�򻯰汾 
class Solution {
public:
    int jump(vector<int>& nums)
	{
		int n=nums.size();
		int end=0;			//��λ��i��һ�����������λ�� 
    	int maxp=0; 		//��[i..end]��������ܹ������λ��	
    	int steps=0;		//������Ծ���� 
    	for(int i=0;i<n-1;i++)
		{
        	maxp=max(maxp,nums[i]+i);		//ȡλ��i�������Ծ���� 
        	//printf("i=%d,maxp=%d\n",i,maxp);
        	if(i==end) 						//�����߽磬�͸��±߽磬���Ҳ�����һ
        	{
            	end=maxp;
            	steps++;
        	}
    	}
    	return steps;
    }
};
*/

int main()
{
	//vector<int> a={2,1,1,1};
	vector<int> a={2,3,1,1,4};
	Solution obj;
	int ans=obj.jump(a);
	cout << ans << endl;
	return 0;
}
	
	

