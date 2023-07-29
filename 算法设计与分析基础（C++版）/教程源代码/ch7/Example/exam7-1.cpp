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
		int end=nums[0];		//在位置i跳一次最多跳到的位置 
    	int maxp; 				//从[i..end]能够跳到的最远位置	
    	int steps=1;			//最少跳跃次数 
		printf("从位置0跳一次,steps=%d\n",steps);
    	int i=1,maxi;
    	while(i<n-1)			//遍历nums[0..n-2] 
		{
			maxp=0;
			while(i<n-1)		//求[i..end]能够跳到的最远位置maxp 
			{
                if(maxp<nums[i]+i)
                {
                    maxp=nums[i]+i;
                    maxi=i;					//maxi为最远位置maxp的起跳位置 
                }
        		if(i==end) break;			//[i,end]处理完毕退出循环 
                i++;
        	}
            if(i<n-1)						//位置i有效则跳一次跳到maxp位置 
            {
                end=maxp;
                steps++;
                i=maxi;
               printf("从位置%d跳一次,steps=%d\n",maxi,steps);
            }
            else break;
    	}
    	return steps;
    }
};
/*

//简化版本 
class Solution {
public:
    int jump(vector<int>& nums)
	{
		int n=nums.size();
		int end=0;			//在位置i跳一次最多跳到的位置 
    	int maxp=0; 		//从[i..end]起跳最多能够到达的位置	
    	int steps=0;		//最少跳跃次数 
    	for(int i=0;i<n-1;i++)
		{
        	maxp=max(maxp,nums[i]+i);		//取位置i的最大跳跃长度 
        	//printf("i=%d,maxp=%d\n",i,maxp);
        	if(i==end) 						//遇到边界，就更新边界，并且步数加一
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
	
	

