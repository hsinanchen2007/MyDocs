/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:

    // 2020.6.2, 极客时间覃超算法训练營
    void moveZeroes(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[target] = nums[i];
                // if target and i is same, for example {1}, 
                // no need to assign 0 in nums
                if (target != i) {
                    nums[i] = 0;
                }
                // move to next target
                target++;
            }
        }
    }
};
// @lc code=end

