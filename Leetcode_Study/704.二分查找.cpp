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
class Solution100 {
public:
    // 2022.6.18, by Hsinan. The given vector is sorted, 
    // and there is no duplicated elements, typical binary search
    int search(vector<int>& nums, int target) {
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
};


class Solution99 {
public:
    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    /*
        为了易于大家理解，我还录制了视频，可以看这里：B站：手把手带你撕出正确的二分法

        这道题目的前提是数组为有序数组，同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的，这些都是使用二分法的前提条件，
        当大家看到题目描述满足如上条件的时候，可要想一想是不是可以用二分法了。
        二分查找涉及的很多的边界条件，逻辑比较简单，但就是写不好。例如到底是 while(left < right) 还是 while(left <= right)，到底是right = middle呢，
        还是要right = middle - 1呢？

        大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，区间的定义就是不变量。要在二分查找的过程中，保持不变量，就是在while寻找中每一次边界的处理都要坚持根据
        区间的定义来操作，这就是循环不变量规则。

        写二分法，区间的定义一般为两种，左闭右闭即[left, right]，或者左闭右开即[left, right)。

        下面我用这两种区间的定义分别讲解两种不同的二分写法。

        二分法第一种写法
        第一种写法，我们定义 target 是在一个在左闭右闭的区间里，也就是[left, right] （这个很重要非常重要）。

        区间的定义这就决定了二分法的代码应该如何写，因为定义target在[left, right]区间，所以有如下两点：

        while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
        if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1
        例如在数组：1,2,3,4,7,9,10中查找元素2，如图所示：

        704.二分查找

        代码如下：（详细注释）
    */
    // Solution 1 template: Use [left, right]
    //             while condition will be while (left <= right)
    //             if (nums[middle] > target) right = middle -1;
    //             if (nums[middle] < target) left = middle + 1;
    int search(vector<int>& nums, int target) {
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
};


class Solution98 {
public:
    // 2022.6.18, from https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#_704-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE
    /*
        二分法第二种写法
        如果说定义 target 是在一个在左闭右开的区间里，也就是[left, right) ，那么二分法的边界处理方式则截然不同。

        有如下两点：

        while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的
        if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，所以right更新为middle，
        即：下一个查询区间不会去比较nums[middle]

        在数组：1,2,3,4,7,9,10中查找元素2，如图所示：（注意和方法一的区别）

        704.二分查找1

        代码如下：（详细注释）

        二分法是非常重要的基础算法，为什么很多同学对于二分法都是一看就会，一写就废？

        其实主要就是对区间的定义没有理解清楚，在循环中没有始终坚持根据查找区间的定义来做边界处理。
        区间的定义就是不变量，那么在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。

        本篇根据两种常见的区间定义，给出了两种二分法的写法，每一个边界为什么这么处理，都根据区间的定义做了详细介绍。
        相信看完本篇应该对二分法有更深刻的理解了。

        相关题目推荐
        35.搜索插入位置
        34.在排序数组中查找元素的第一个和最后一个位置
        69.x 的平方根
        367.有效的完全平方数
    */
    // Solution 2 template: Use [left, right)
    //             while condition will be while (left < right)
    //             if (nums[middle] > target) right = middle;
    //             if (nums[middle] < target) left = middle + 1;
    int search(vector<int>& nums, int target) {
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
};


class Solution97 {
public:
    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/binary-search.cpp
    // Time:  O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
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
};


class Solution96 {
public:
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


class Solution95 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/704.%20Binary%20Search
    // OJ: https://leetcode.com/problems/binary-search/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] < target) L = M + 1;
            else R = M;
        }
        return A[L] == target ? L : -1;
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/704.%20Binary%20Search
    // OJ: https://leetcode.com/problems/binary-search/
    // Author: github.com/lzl124631x
    // Time: O(logN)
    // Space: O(1)
    // Update by Hsinan, need to add "A.size() != M + 1" for boundary check
    int search(vector<int>& A, int target) {
        int L = 0, R = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] < target && A.size() != M + 1) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


class Solution93 {
public:
    // 2022.7.26, from https://www.guozet.me/leetcode/summary/2019-01-15-Algorithms-Binary-Search.html?h=704
    // Time complexity: O(log n), Space complexity: O(1)
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};


class Solution {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/704
    /*
        这道题就是最基本的二分搜索法了，这是博主之前总结的LeetCode Binary Search Summary 二分搜索法小结的四种之中的第一类，也是最简单的一类，
        写法什么很模版啊，注意right的初始化值，还有while的循环条件，以及right的更新值，这三点不同的人可能会有不同的写法，选一种自己最习惯的就好啦，
        参见代码如下：
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

