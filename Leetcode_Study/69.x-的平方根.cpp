/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

/*

https://leetcode.cn/problems/sqrtx/

69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

 
示例 1：

输入：x = 4
输出：2

示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 

提示：

0 <= x <= 231 - 1
通过次数557,697提交次数1,436,404

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.19, from CyC2018/CS-Notes
    int mySqrt(int x) {
        // sanity check
        if (x <= 1) return x;

        // define left and right pointers
        int left = 0, right = x;

        // find the sqrt
        while (left <= right) {
            int middle = left + (right - left) / 2;

            // key point is below. If sqrt * middle = x, that means
            // we found exactly sqrt. This is only extra one 
            // compared to template
            // For example x = 4, then we have left = 0, right = 4
            // and middle = 2, which is its sqrt 
            int sqrt = x/middle;

            if (sqrt == middle) {
                return middle;
            } else if (middle > sqrt) {
                right = middle -1;
            } else {
                left = middle + 1;
            }
        }

        // again, similar to LC 35, when we didn't find the answer in while loop,
        // at this point, right < left (right pointer becomes at left side of left pointer)
        // we should return right pointer here, since we will should the integer value of 
        // sqrt, for example, 8's sqrt is 2.82842, we pick integer "2" as answer,
        // which is right pointer at this moment
        return right;

        // After a try, we can also return (left - 1) like other answers below
        // return (left - 1);
    }
};


class Solution99 {
public:
    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-69-Sqrt-x-3.html?q=sqrt
    // Time Complexity: O(log n), Space Complexity: O(1)
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 0, right = x / 2 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Move left == right, then we need to move left back
            x / mid < mid ? right = mid : left = mid + 1;
        }

        return left - 1;
    }
};


class Solution98 {
public:
    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sqrtx.cpp
    // Time:  O(logn)
    // Space: O(1)
    int mySqrt1(int x) {
        if (x < 2) {
            return x;
        }
        
        int left = 1, right = x / 2;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left - 1;
    }
};


class Solution97 {
public:
    // 2022.6.19, from AcWing https://www.acwing.com/video/1407/
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right) {
            // tricky below to use "1ll" to avoid overflow 
            int middle = left + 1ll + right >> 1;
            if (middle <= x / middle) left = middle;
            else right = middle - 1;
        }

        return right;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(sqrt(N))
    // Space: O(1)
    int mySqrt(int x) {
        long i = 0;
        while (i * i <= x) ++i;
        return i - 1;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // L <= R template.
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L <= R) {
            long M = (L + R) / 2;
            if (M * M <= x) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // use L < R template
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long L = 0, R = x;
        while (L < R) {
            long M = (L + R + 1) / 2;
            if (M * M <= x) L = M;
            else R = M - 1;
        }
        return L;
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/69.%20Sqrt(x)
    // Newton's method, Reference: https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
    // OJ: https://leetcode.com/problems/sqrtx/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) r = (r + x / r) / 2;
        return r;
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0069/
    // Time: O(logx)
    // Space: O(1)
    int mySqrt(int x) {
        unsigned l = 1;
        unsigned r = x + 1u;

        while (l < r) {
        const unsigned m = (l + r) / 2;
        if (m > x / m)
            r = m;
        else
            l = m + 1;
        }

        // l: smallest number s.t. l * l > x
        return l - 1;
    }
};


class Solution {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-69-Sqrt-x-3.html?h=mysqrt
    // Time Complexity: O(log n), Space Complexity: O(1)
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 0, right = x / 2 + 1;
        while (left < right) {
        int mid = left + (right - left) / 2;
        // Move left == right, then we need to move left back
        x / mid < mid ? right = mid : left = mid + 1;
        }

        return left - 1;
    }
};
// @lc code=end

