/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:

    // 2022.6.1, LG solution
    int removeDuplicates(vector<int>& nums) {
        int target = 0;
        for (int i = 1; i < nums.size(); i++) {
            // target starts from 0, i starts from 1
            // if they are not same, assign number if ++target != i
            // otherwise i++ to next one if they are same
            if (nums[target] != nums[i]) {
                // tricky here, ++target, not target++
                // perform ++ first and check if it is same as i or not
                // actually even if we still assign the number, it is OK
                if (++target != i) {
                    nums[target] = nums[i];
                }
            }
        }
        return (target + 1);
    }
    
};
// @lc code=end

