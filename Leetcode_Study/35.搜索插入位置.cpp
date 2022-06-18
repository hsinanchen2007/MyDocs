/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:

    // 2022.6.18, by Hsinan, follow LC 704, use soluition 1 template
    // also from https://programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF
    int searchInsert2(vector<int>& nums, int target) {
        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        // use left <= right condition in while
        while (left <= right) {
            // avoid overflow
            int middle = left + (right - left) / 2;

            // use same rtemplate as LC 704
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        // the tricky part is the end of return answer 
        // when it is not found in the while loop,
        // that means left > right, so the return should be
        // (right + 1)
        // {1, 3, 5, 6}, target 2
        return (right + 1);
    }

    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/search-insert-position.cpp
    int searchInsert1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            const auto mid = left + (right -left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    // 2022.6.18, from AcWing https://www.acwing.com/video/1358/
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int middle = left + right >> 1;
            if (nums[middle] >= target) right = middle;
            else left = middle + 1;
        }
        return left;
    }

};
// @lc code=end

