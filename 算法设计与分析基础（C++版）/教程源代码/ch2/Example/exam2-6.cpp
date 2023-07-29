#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>&nums,int k)
{	int n=nums.size();
	deque<int> dq;
    vector<int> ans;
	for(int i=0;i<k;i++)									//����numsǰk��Ԫ��
	{
		printf("����nums[%d]=%d:\n",i,nums[i]); 
		if(dq.empty())										//�ӿ�ʱ��Ԫ���±�i����β
		{
			dq.push_back(i);
			printf("  %d(%d)��˽�\n",i,nums[i]);
		}			
		else													//�Ӳ���ʱ
		{	while(!dq.empty() && nums[i]>nums[dq.back()])
			{
				printf("  %d(%d)��˳�\n",dq.back(),nums[dq.back()]); 
       			dq.pop_back();							//����βС��nums[i]��Ԫ�شӶ�β����
       		}
     		dq.push_back(i);								//��Ԫ���±�i����β
			printf("  %d(%d)��˽�\n",i,nums[i]);
   		}
 	}
  	ans.push_back(nums[dq.front()]);				//��ͷԪ����ӵ�ans��
  	printf("ans�����%d(i=%d)\n",ans.back(),dq.front());
	   
	for(int i=k;i<n;i++)									//����nums��ʣ���Ԫ��
	{
		printf("����nums[%d]=%d:\n",i,nums[i]); 
		if(dq.empty())										//�ӿ�ʱ��Ԫ���±�i����β
		{
			dq.push_back(i);
			printf("  %d(%d)��˽�\n",i,nums[i]);
		}			
		else													//�Ӳ���ʱ
		{	while(!dq.empty() && nums[i]>nums[dq.back()])
			{
				printf("  %d(%d)��˳�\n",dq.back(),nums[dq.back()]); 
       			dq.pop_back();									//����βС��nums[i]��Ԫ�شӶ�β����
       		}
     		dq.push_back(i);								//��Ԫ���±�i����β
			printf("  %d(%d)��˽�\n",i,nums[i]);
   		}
		if(dq.front()<i-k+1)								//����ͷ���ڵ�Ԫ�شӶ�ͷ����
		{
			printf("%d(%d)����ǰ�˳�\n",dq.front(),nums[dq.front()]); 
			dq.pop_front();
		}
    	ans.push_back(nums[dq.front()]);					//�¶�ͷԪ����ӵ�ans��
   	  	printf("ans�����%d(i=%d)\n",ans.back(),dq.front());

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
	cout << "���" << endl;
	cout << "ans: ";disp(ans);
	return 0;
}
