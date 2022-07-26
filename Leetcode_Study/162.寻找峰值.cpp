/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

/*

https://leetcode.cn/problems/find-peak-element/

162. 寻找峰值
峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。


示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。

示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
 

提示：

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]
通过次数240,610提交次数486,015

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.10, by Hsinan, check the middle and see if it is higher than right side's element
    // then adjust left or right accordingly
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= nums[middle+1]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return right;
    }
};


class Solution99 {
public:
    // 2022.7.10, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 寻找峰值(162):https://leetcode-cn.com/problems/find-peak-element/ 
    int findPeakElement(vector<int>& nums) {
        
        // left 为当前区间最左侧的元素，可以获取到
        int left = 0;

        // right 为当前区间最右侧的元素，可以获取到
        int right = nums.size() - 1;


        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个元素的时候
        // 这也意味着这个区间里面的元素找不到其它元素和它进行比较，也就无法得知这个元素是否严格大于它左右相邻值的元素了
        // 所以，当 left == right 时，跳出循环
        // 此时，while 循环的判断不可以使用等号
        while(left < right) {

            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 题目告诉我们 nums[-1] = nums[n] = -∞ 
            // 这暗示我们只要数组中存在一个元素比它相邻的元素大，那么沿着它一定可以找到一个峰值
            // 就像爬山一样，较小的山高度是 100，前面的山高度是 200，在前面是一个深渊，那么高度为 200 的那座山就是山峰
            // 所以比较 nums[mid] 与 nums[mid + 1] 的值

            // 如果 nums[mid] > nums[mid + 1]
            // 所以，如果存在山峰，那么这一段是右侧下降的那一段，因此需要在左侧去寻找上升的那段 
            if (nums[mid] > nums[mid + 1]) {

                // 缩小区间，从 [ left , mid ] 里面去找
                right = mid;
            
            // 如果 nums[mid] < nums[mid + 1]
            // 所以，如果存在山峰，那么这一段是左侧上升的那一段，因此需要在右侧去寻找下降的那段         
            } else {

                // 缩小区间，从 [ mid + 1 , right ] 里面去找
                left = mid + 1;

            }
        }

        // 跳出循环，此时 left == right，返回这个下标即可
        return left;
    }
};


class Solution98 {
public:
    // 2022.7.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-peak-element.cpp
    // Time:  O(logn)
    // Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};


class Solution97 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/162.%20Find%20Peak%20Element
    // Solution 1. Binary Search (L <= R)
    // OJ: https://leetcode.com/problems/find-peak-element/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            long M = (L + R) / 2, left = M == 0 ? LONG_MIN : A[M - 1], right = M == A.size() - 1 ? LONG_MIN : A[M + 1];
            if (A[M] > left && A[M] > right) return M;
            if (A[M] < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/162.%20Find%20Peak%20Element
    // Solution 2. Binary Search (L < R)
    // OJ: https://leetcode.com/problems/find-peak-element/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int findPeakElement(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[M + 1]) R = M;
            else L = M + 1;
        }
        return L;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0162/
    // Time: O(logn)
    // Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
        const int m = (l + r) / 2;
        if (nums[m] >= nums[m + 1])
            r = m;
        else
            l = m + 1;
        }

        return l;
    }
};


class Solution {
public:
    // 2022.7.10, from AcWing https://www.acwing.com/activity/content/code/content/411113/
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return r;
    }

};
// @lc code=end

