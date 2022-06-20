/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

/*

https://leetcode.cn/problems/first-bad-version/

278. 第一个错误的版本
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

 
示例 1：

输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。
示例 2：

输入：n = 1, bad = 1
输出：1
 

提示：

1 <= bad <= n <= 231 - 1
通过次数345,957提交次数761,940

*/

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    // 2022.6.19, by Hsinan. Use Binary Search
    int firstBadVersion3(int n) {
        // define left and right pointers, since the starting version is 1
        // so we use left = 1, and right is latest version n
        int left = 1, right = n;

        while (left <= right) {
            int middle = left + (right -left) / 2;
            if (isBadVersion(middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }

    // 2022.6.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/single-element-in-a-sorted-array.cpp
    int firstBadVersion2(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // 2022.6.19, from https://www.guozet.me/leetcode/Leetcode-278-First-Bad-Version.html?h=first%20bad
    int firstBadVersion1(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            isBadVersion(mid) ? right = mid : left = mid + 1;
        }
        return left;
    }

    // 2022.6.19, from AcWing https://www.acwing.com/video/1653/
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int middle = left + (long long)right >> 1;
            if (isBadVersion(middle)) right = middle;
            else left = middle + 1;
        }
        return right;
    }

};
// @lc code=end

