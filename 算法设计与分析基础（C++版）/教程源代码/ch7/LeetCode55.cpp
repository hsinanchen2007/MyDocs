
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
    	int n=nums.size();
    	if(n==1) return true;
    	int step=0,i=0;
    	while(i<=step)
    	{
    		step=max(i+nums[i],step);
    		if(step>=n-1)
    			return true;
    		i++;
    	}
    	return false;
    }
};
