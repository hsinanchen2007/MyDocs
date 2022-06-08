/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

/*

https://leetcode.cn/problems/reverse-integer/

7. 整数反转
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0
 

提示：

-231 <= x <= 231 - 1
通过次数1,027,693提交次数2,911,171
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
字符串转换整数 (atoi)
中等
颠倒二进制位
简单

*/

// @lc code=start
class Solution {
public:

    // 2022.5.30, LG solution
    //   1. Do integer limit check first, and return 0 if they are over limit
    //   2. Check and convert number to positive first, sign is used to
    //      determine positive or negative number by 1 or -1
    //   3. do (last = x % 10) in while condition
    //   4. Remember if (last != 0), we need to apply it back, also
    //      convert it to long and do integer limit check
    //   5. At the end of return, apply sign back
    int reverse3(int x) {
        // sanity check, INT_MAX is 2147483648, INT_MIN is -2147483648
        // if the given number is reversed, it will cause over integer limit
        if (x == INT_MAX || x == INT_MIN) return 0;

        // check the given x is positive or negative number, and always
        // convert it to positive number first
        // note that the sign should be 1 or -1, not 1 or 0, as we will 
        // need to (result * sign) at the end, so if sign is 0, that will 
        // cause negative number returns 0
        int sign = (x > 0) ? 1 : -1;
        x = (x < 0) ? -x : x;

        // defnie result and last, note that these two variables needed to 
        // be used inside while loop and outside later
        int result = 0;
        int last = 0;

        // key point condition, assign (x % 10) first, then compare with x
        // itself, if they are same, this is last number, otherwise run into
        // this while loop, for example 123, we want to reverse it to 321
        while ((last = x % 10) != x) {
            result = (result * 10) + last;
            x = x / 10;
        }

        // if last is not 0, if won't run into while loop
        // that means above will only include (n-1) numbers
        // from original n numbers, for example, 123, and 
        // after while loop, we only get 32, where 1 was not 
        // executed in while loop, so we need below code
        // if last = 0, for example, original 320 will become
        // 23, not 023, so we can skip the last if it is 0
        if (last != 0) {
            // note here we do a small to large conversion, from integer to long
            // so it won't have over integer limit issue
            long re = result;
            re = re * 10 + last;

            // do the limit check again before return
            if (re > INT_MAX || re < INT_MIN) {
                return 0;
            } else {
                // convert it back to integer from long
                result = (int)re;
            }
        }

        return result * sign;
    }

    // 2022.5.31, Leetcode 題目詳解, lvyilong316@163.com
    // However, need to add the INT_MAX/INT_MIN check as Leetcode
    // now will check the integer overflow in the submission cases
    int reverse2(int x) {
        // need to define "result" as long, not int, to detect and prevent integer overflow
        long result = 0;
        for (; x; x/=10) {
            // tricky part, result starts with 0, so (x % 10) returns the 
            // last digit, then move to next one
            result = (result * 10) + (x % 10);
        
            // need this check to avoid integer overflow
            if (result >= INT_MAX || result <= INT_MIN) return 0;
        }
        return (int)result;
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1323/
    // it can use integer without converting anything to long long
    // two conditions that over limit:
    //   1. r * 10 + x % 10 > INT_MAX
    //      ==> r > (INT_MAX - x % 10) / 10
    //   2. r * 10 + x % 10 < INT_MIN
    //      ==> r < (INT_MIN - x % 10) / 10
    int reverse1(int x) {
        int r = 0;
        while (x) {
            if (r > 0 && r > (INT_MAX - x % 10) / 10) return 0;
            if (r < 0 && r < (INT_MIN - x % 10) / 10) return 0;
            r = r * 10 + x % 10;
            x = x / 10;
        }
        return r;
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-integer.cpp
    int reverse(int x) {
        int result = 0;
        while (x) {
            if (result > numeric_limits<int>::max() / 10 ||
                (result == numeric_limits<int>::max() / 10 && x % 10 > numeric_limits<int>::max() % 10)) {
                return 0;
            }
            if (result < numeric_limits<int>::min() / 10 ||
                (result == numeric_limits<int>::min() / 10 && x % 10 < numeric_limits<int>::min() % 10)) {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }

};
// @lc code=end

