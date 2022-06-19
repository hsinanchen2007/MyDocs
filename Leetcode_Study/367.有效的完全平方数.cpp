/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

/*

https://leetcode.cn/problems/valid-perfect-square/

367. 有效的完全平方数
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false
 

提示：

1 <= num <= 2^31 - 1
通过次数162,651提交次数362,577

*/

// @lc code=start
class Solution {
public:

    // 2022.6.19, by Hsinan. Very similar to LC 69, we are looking for a middle value
    // by binary search as question required a O(logn)
    bool isPerfectSquare2(int num) {
        // sanity check
        if (num < 2) return num;

        // define left and right pointers
        int left = 0;
        int right = num;

        // binary search with template code
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int sqrt = num / middle;

            if (middle > sqrt) {
                right = middle - 1;
            } else if (middle < sqrt) {
                left = middle + 1;
            } else {
                // middle is sams as sqrt, this means sqrt * middle = num
                // middle or sqrt value as integer may cause it shifted
                // Say middle = 5 / 2 = 2, while num is 5
                // then sqrt = 5 / 2 = 2, that makes middle and sqrt are same
                // the check below will further check its accuracy
                if (middle * middle == num) {
                    return true;
                } else {
                    left = middle + 1;
                }
            }
        }

        return false;
    }

    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-perfect-square.cpp
    bool isPerfectSquare1(int num) {
        int left = 1, right = num;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (mid >= num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left == num / left && num % left == 0;
    }

    // 2022.6.19, from AcWing https://www.acwing.com/video/1753/
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left < right) {
            // tricky below that "+1", in case of overflow, it uses "1ll" long long
            int middle = left + 1ll + right >> 1;
            if (middle <= num / middle) left = middle;
            else right = middle - 1;
        }
        // Actually (left * left == num) can also work
        return (right * right == num);
    }

};
// @lc code=end

