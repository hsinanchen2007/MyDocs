/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:

    // 2020.6.2, 极客时间覃超算法训练營, very similar to LC 27
    void moveZeroes1(vector<int>& nums) {
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

    // learned from LC 27 solution, use C++ STL
    // nums = {0, 0, 1, 2, 3, 0, 0, 4, 5}, answer = {1, 2, 3, 4, 5, 0, 0, 0, 0}
    void moveZeroes(vector<int>& nums) {
        // get original nums size
        int size = nums.size();

        // note that std::remove returns the number of valid elements
        // which means it will not count the value (0 here) 
        int distance = std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), 0));

        // for this LC question, it needed to remain its original size
        for (int i = 0; i < size-distance; i++) {
            nums[size- 1 - i] = 0;
        }
    }
};
// @lc code=end

