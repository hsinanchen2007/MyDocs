/* 

https://leetcode.cn/problems/3sum-smaller/

259. 较小的三数之和
给定一个长度为 n 的整数数组和一个目标值 target ，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三元组  i, j, k 个数（0 <= i < j < k < n）。

 

示例 1：

输入: nums = [-2,0,1,3], target = 2
输出: 2 
解释: 因为一共有两个三元组满足累加和小于 2:
     [-2,0,1]
     [-2,0,3]
示例 2：

输入: nums = [], target = 0
输出: 0 
示例 3：

输入: nums = [0], target = 0
输出: 0 
 

提示:

n == nums.length
0 <= n <= 3500
-100 <= nums[i] <= 100
-100 <= target <= 100
通过次数10,005提交次数17,904

*/

class Solution {
public:
    int threeSumSmaller1(vector<int>& nums, int target) {
        // sanity check if nums didn't have enough numbers
        if (nums.size() < 3) return 0;
    
        // define return and sort vector first
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        // iterate from i
        for (int i = 0; i < n - 2; ++i) {
            // define two pointers
            int left = i + 1, right = n - 1;

            // when left < right
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    // tricky, use (right -left) to get all valid solutions
                    res += right - left;
                    ++left;
                } else {
                    // no valid solution here
                    --right;
                }
            }
        }

        return res;
    }

    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-smaller.cpp
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (nums[i] + nums[j] + nums[k] >= target) {
                    --j;
                } else {
                    count += j - i;
                    ++i;
                }
            }
        }

        return count;
    }

};