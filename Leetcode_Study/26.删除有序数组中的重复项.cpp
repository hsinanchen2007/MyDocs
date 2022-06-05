/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:

    // 2022.6.1, LG solution
    int removeDuplicates1(vector<int>& nums) {
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

    // 2022.6.4, from AcWing https://www.acwing.com/video/1348/
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            // example {1, 2, 2, 2, 3, 4, 5}
            //   i = 0, nums[0] = nums[0], k = 1
            //   i = 1, nums[1] = nums[1], k = 2;
            //   i = 2, nums[2] and nums[1] are same, skip
            //   i = 3, nums[3] and nums[2] are same, skip
            //   i = 4, nums[2] = nums[4], k = 3
            //   i = 5, nums[3] = nums[5], k = 4
            //   i = 6, nums[4] = nums[6], k = 5
            // return 5
            // tricky is below if condition
            if (!i || nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

};
// @lc code=end

