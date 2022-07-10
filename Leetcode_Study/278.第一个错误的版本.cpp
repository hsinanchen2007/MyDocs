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
    int firstBadVersion4(int n) {
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
    int firstBadVersion3(int n) {
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
    int firstBadVersion2(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            isBadVersion(mid) ? right = mid : left = mid + 1;
        }
        return left;
    }

    // 2022.6.19, from AcWing https://www.acwing.com/video/1653/
    int firstBadVersion1(int n) {
        int left = 1, right = n;
        while (left < right) {
            int middle = left + (long long)right >> 1;
            if (isBadVersion(middle)) right = middle;
            else left = middle + 1;
        }
        return right;
    }

    // 2022.6.19, from https://ke.algomooc.com/detail/v_6281aa6ce4b01a4851ff6237/3?from=p_6281a4bbe4b01a4851ff5f23&type=6&parent_pro_id=
    int firstBadVersion(int n) {
        // 注意到题目的第一个版本下标为 1 ，所以边界情况为 [ 1 , n ]
        int left = 1 ;
        int right = n ;

        // 利用二分查找的方法，去定位出【第一个错误的版本】
        // 在 while 循环里面，left 不断的 ++，而 right 不断的 --
        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个版本的时候
        // 这个版本就是【第一个错误的版本】
        // 所以，当 left == right 时，跳出循环
        // 此时，while 循环的判断不可以使用等号
        while (left < right) { 
            // left + (right - left) / 2 和 (left + right) / 2 的结果相同
            // 但是使用 left + (right - left) / 2 可以防止由于 left 、right 同时太大，导致相加的结果溢出的问题
            // 比如数据 int 的最大值为 2,147,483,647
            // 此时，left 为 2,147,483,640
            // 此时，right 为 2,147,483,646
            // 两者直接相加超过了 2,147,483,647，产生了溢出
            int mid = left + (right - left) / 2;

            // 调用系统函数，查看当前的版本是否是错误的版本
            // 1、如果当前版本为错误的版本，那么此时 mid 指向的版本有可能是【第一个错误的版本】
            // 因此，区间缩小为 [ left , mid ]
            if (isBadVersion(mid)) {

                // 再次注意，mid 指向的版本有可能是【第一个错误的版本】，因此，right 移动到 mid 的位置
                right = mid;

            // 2、如果当前版本为正确的版本，那么此时 mid 指向的版本绝对不可能是【第一个错误的版本】
            //  因此，区间缩小为 [ mid + 1 , right ]
            } else {
                
                // 再次注意，mid 指向的版本已经是正确的版本了
                // 意味着 [ left , mid ] 的所有版本都是正确的，错误的版本发生在 [ mid + 1 , right ] 这个区间里面
                left = mid + 1; 

            }
        }

        // 当 left 和 right 相等， [ left , right ] 这个区间存在一个版本的时候
        // 这个版本就是【第一个错误的版本】
        return left;
    }

};
// @lc code=end

