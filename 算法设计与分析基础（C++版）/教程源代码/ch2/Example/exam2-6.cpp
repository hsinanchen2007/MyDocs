#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>&nums,int k)
{	int n=nums.size();
	deque<int> dq;
    vector<int> ans;
	for(int i=0;i<k;i++)									//处理nums前k个元素
	{
		printf("考虑nums[%d]=%d:\n",i,nums[i]); 
		if(dq.empty())										//队空时将元素下标i进队尾
		{
			dq.push_back(i);
			printf("  %d(%d)后端进\n",i,nums[i]);
		}			
		else													//队不空时
		{	while(!dq.empty() && nums[i]>nums[dq.back()])
			{
				printf("  %d(%d)后端出\n",dq.back(),nums[dq.back()]); 
       			dq.pop_back();							//将队尾小于nums[i]的元素从队尾出队
       		}
     		dq.push_back(i);								//将元素下标i进队尾
			printf("  %d(%d)后端进\n",i,nums[i]);
   		}
 	}
  	ans.push_back(nums[dq.front()]);				//队头元素添加到ans中
  	printf("ans中添加%d(i=%d)\n",ans.back(),dq.front());
	   
	for(int i=k;i<n;i++)									//处理nums中剩余的元素
	{
		printf("考虑nums[%d]=%d:\n",i,nums[i]); 
		if(dq.empty())										//队空时将元素下标i进队尾
		{
			dq.push_back(i);
			printf("  %d(%d)后端进\n",i,nums[i]);
		}			
		else													//队不空时
		{	while(!dq.empty() && nums[i]>nums[dq.back()])
			{
				printf("  %d(%d)后端出\n",dq.back(),nums[dq.back()]); 
       			dq.pop_back();									//将队尾小于nums[i]的元素从队尾出队
       		}
     		dq.push_back(i);								//将元素下标i进队尾
			printf("  %d(%d)后端进\n",i,nums[i]);
   		}
		if(dq.front()<i-k+1)								//将队头过期的元素从队头出队
		{
			printf("%d(%d)过期前端出\n",dq.front(),nums[dq.front()]); 
			dq.pop_front();
		}
    	ans.push_back(nums[dq.front()]);					//新队头元素添加到ans中
   	  	printf("ans中添加%d(i=%d)\n",ans.back(),dq.front());

 	}
	return ans;
}
void disp(vector<int> &v)
{
	for(auto e:v)
		printf("%d ",e);
	printf("\n");
}
int main()
{
	vector<int> nums={4,3,5,4,3,3,6,7};
	int k=3;
	cout << "nums: ";disp(nums);
	vector<int> ans=maxSlidingWindow(nums,k);
	cout << "求解" << endl;
	cout << "ans: ";disp(ans);
	return 0;
}
