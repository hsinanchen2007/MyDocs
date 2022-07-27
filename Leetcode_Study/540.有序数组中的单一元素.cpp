/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

/*

https://leetcode.cn/problems/single-element-in-a-sorted-array/

540. 有序数组中的单一元素
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
 

示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10
 

提示:

1 <= nums.length <= 105
0 <= nums[i] <= 105
通过次数98,502提交次数161,946

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, by Hsinan. Hint is O(logn) and sorted vector, that means binary search
    // key is how to determine this is the only one number that happened only once in this
    // given vector
    // Since all other numbers happened twice in this sorted vector, this vector size should
    // be odd number, so size/2 will return a even number, 
    // For example, [1,1,2,3,3,4,4,8,8]
    // Also refer CS-Notes/CyC2018
    int singleNonDuplicate(vector<int>& nums) {
        // sanity check
        if (nums.size() == 1) {
            return nums[0];
        }

        // define left and right pointers, note that now right is a even number
        // so its next one should be same number if there is no other number happened
        // once before
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (middle % 2 == 1) {
                // make sure middle is even number
                middle--;
            }
            if (nums[middle] == nums[middle + 1]) {
                // since we already adjust middle to even number, if the next number
                // is same as current one, there is no number happened once before,
                // then we can adjust middle to next 2, so middle + 2
                left = middle + 2;
            } else {
                // one number happened only once before middle, adjust right pointer 
                // as middle and keep searching
                right = middle;
            }
        }
        return nums[left];
    }
};


class Solution99 {
public:
    // 2022.6.19 from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/single-element-in-a-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if (!(mid % 2 == 0 && mid + 1 < nums.size() &&
                  nums[mid] == nums[mid + 1]) &&
                !(mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};


class Solution98 {
public:
    // 2022.6.19, from AcWing 
    int singleNonDuplicate(vector<int>& nums) {
        // based on the question, we know the size of given vector will be odd number
        // so let's make it to even by adding a number, the last number + 1
        nums.push_back(nums.back() + 1);

        // now define left and right pointers
        // note that "nums.size() / 2 - 1" will make it to the first number of pair
        // and we expect first and second numbers in pair are same if there is no
        // number happened once before this point
        int left = 0, right = nums.size() / 2 - 1;

        while (left < right) {
            // note that at the beginning right is already around middle
            int middle = left + (right - left) / 2;
            if (nums[middle * 2] != nums[middle * 2 + 1]) right = middle;
            else left = middle + 1;
        }

        // very tricky return!
        return nums[right * 2];
    }
};


class Solution97 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if ((M % 2 == 0 && A[M] == A[M + 1])
               || (M % 2 == 1 && A[M] == A[M - 1])) L = M + 1;
                else R = M;
        }
        return A[L];
    }
};


class Solution96 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (M % 2) M--;
            if (A[M] == A[M + 1]) L = M + 2;
            else R = M;
        }
        return A[L];
    }
};


class Solution95 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/540.%20Single%20Element%20in%20a%20Sorted%20Array
    // OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int singleNonDuplicate(vector<int>& A) {
        int N = A.size(), L = 0, R = N - 1;
        auto valid = [&](int M) { // returns `true` is the index of the single element < M
            return M % 2 ? (M + 1 < N && A[M] == A[M + 1]) : (M - 1 >= 0 && A[M] == A[M - 1]);
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return A[R];
    }
};


class Solution {
public:
    // 2022.7.26, from https://walkccc.me/LeetCode/problems/0540/
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (m & 1)
                --m;
            if (nums[m] == nums[m + 1])
                l = m + 2;
            else
                r = m;
        }

        return nums[l];
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


  