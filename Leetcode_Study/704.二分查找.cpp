/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

/*

https://leetcode.cn/problems/binary-search/

704. 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
通过次数634,790提交次数1,166,436

*/

// @lc code=start
class Solution {
public:

    // 2022.6.18, by Hsinan. The given vector is sorted, 
    // and there is no duplicated elements, typical binary search
    int search4(vector<int>& nums, int target) {
        // special cases
        if (nums.size() == 1 && nums[0] == target) return 0;
        if (nums.size() == 2) {
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
        }

        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // if left or right is target
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;

            // get middle from left and right
            int middle = left + (right -left)/2;
            if (middle != left && middle != right) {
                if (target > nums[middle]) {
                    left = middle;
                } else {
                    right = middle;
                }
            } else {
                return -1;
            }
        }

        return -1;
    }

    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    // Solution 1 template: Use [left, right]
    //             while condition will be while (left <= right)
    //             if (nums[middle] > target) right = middle -1;
    //             if (nums[middle] < target) left = middle + 1;
    int search3(vector<int>& nums, int target) {
        // define left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // define middle, note that in case of overflow, 
            // use left + (right - left)/2 to get middle value
            int middle = left + (right - left) / 2; 

            // template above
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }

    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    // Solution 2 template: Use [left, right)
    //             while condition will be while (left < right)
    //             if (nums[middle] > target) right = middle;
    //             if (nums[middle] < target) left = middle + 1;
    int search2(vector<int>& nums, int target) {
        // define two pointers, note that now right index is one overflow, as no "-1" here
        int left = 0;
        int right = nums.size();

        while (left < right) {
            // same as above, get middle value by proper way
            int middle = left + (right - left) / 2;

            if (nums[middle] > target) {
                // no middle -1 here as right side is already one index over from the beginning
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }

    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/binary-search.cpp
    int search1(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    // 2022.6.18, from AcWing https://www.acwing.com/video/2563/
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            // tricky1 to use >> 1 
            int middle = left + right >> 1;

            // tricky2 below uses ">=" condition, not only ">" condition
            // baseically, "right" will be the "middle" or "answer"
            // code is less but coding style is not good or good example
            // to learn algorithm, better to follow 代码随想录 code
            if (nums[middle] >= target) right = middle;

            else left = middle + 1;
        }
        if (nums[right] == target) return right;
        return -1;
    }

};
// @lc code=end

