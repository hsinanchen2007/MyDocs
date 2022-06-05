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
    int removeElement2(vector<int>& nums, int val) {
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

    // 2022.6.2, Leetcode 題目詳解, lvyilong316@163.com
    // use C++ STL, return distance as number of valid size, and use remove 
    // to remove the specified value from nums
    int removeElement1(vector<int>& nums, int val) {
        return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1349/
    // very similar to LC 26 as well
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

};
// @lc code=end

