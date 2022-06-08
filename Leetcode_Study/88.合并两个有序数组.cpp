/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

/* 

https://leetcode.cn/problems/merge-sorted-array/

88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

 

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
示例 3：

输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
 

提示：

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

通过次数675,801提交次数1,291,196
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
合并两个有序链表
简单
有序数组的平方
简单
区间列表的交集
中等
You can easily solve this problem if you simply think about two elements at a time rather than two arrays. We know that each of the individual arrays is sorted. What we don't know is how they will intertwine. Can we take a local decision and arrive at an optimal solution?
If you simply consider one element each at a time from the two arrays and make a decision and proceed accordingly, you will arrive at the optimal solution.

*/

// @lc code=start
class Solution {
public:

    // 2022.6.2, 极客时间李煜东算法训练营2021版二期
    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
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

    // 2022.6.5, from AcWing https://www.acwing.com/video/1432/
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we know nums1 has enough space to keep both nums1 and nums2
        // so add largest one from nums1 or nums2 to the end of nums1
        int k = m + n -1;
        int i = m - 1;
        int j = n - 1;

        // add largest one to the end of nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // only need to deal with rest of nums2, as if nums1 still has
        // some left, they are already placed at right index location
        // from the beginning as this is a sorted array
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/merge-sorted-array.cpp
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i - 1] = nums1[m - 1];
                --m;
            } else {
                nums1[i - 1] = nums2[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            nums1[i - 1] = nums2[n - 1];
            --n;
            --i;
        }
    }

};
// @lc code=end

