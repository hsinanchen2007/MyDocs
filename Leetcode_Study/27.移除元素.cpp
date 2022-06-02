/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:

    // 2022.6.2, very similar to LC 283
    // nums = {0, 2, 3, 4, 5, 5, 2, 2}, val = 2
    // answer = {0, 3, 4, 5, 5}, return 5
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                // assign not val's values to current index
                nums[index] = nums[i];
                // after assigning value, move index to next
                index++;
            }
        }
        // note that in the nums, we still have such values
        // {0, 3, 4, 5, 5, 2, 2}, return size 5, so we know
        // if we print out the elements in this nums, we will
        // only print {0, 3, 4, 5, 5}, no 2 there
        // this matches the required condition (same order) 
        // and valid size of this question, there is no need
        // to overwrite the rest values in nums
        return index;
    }
};
// @lc code=end

