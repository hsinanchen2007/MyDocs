/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:

    // 2022.6.2, 极客时间李煜东算法训练营2021版二期
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointers to trace the current one in the array
        int i = 0, j = 0;

        // hold the result temporary
        vector<int> result;

        // iterate array
        while (i < m || j < n) {
            // most tricky statement below
            // 1. when j from nums2 is already end, put all rest elements
            //    into result from nums1
            // 2. when i is still within range, and nums1[i] is smaller than
            //    nums2[j], put this element into result
            // think only from one side, and put rest to another side
            if ((j >= n) || (i < m && nums1[i] <= nums2[j])) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        // put numbers back to nums1
        for (int k = 0; k < m + n; k++) nums1[k] = result[k];
    }

    // 2022.6.2, 极客时间李煜东算法训练营2021版二期
    // good example to resolve it by reverse way, and no extra defined
    // variable
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointers, i and j pointed to last elements
        int i = m - 1;
        int j = n - 1;

        // reverse as nums1 has n empty from end, and the sorted elements
        // are located at first m elements in nums1
        for (int k  = m + n -1; k >= 0; k--) {
            // similar to above tricky condition part
            // 1. when j is less than 0, all elements from nums1[i] can be 
            //    copied into the nums1
            // 2. when i is still within range, and element from nums1[i] is
            //    larger than nums2[j] 
            if ((j < 0) || (i >= 0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }

};
// @lc code=end

