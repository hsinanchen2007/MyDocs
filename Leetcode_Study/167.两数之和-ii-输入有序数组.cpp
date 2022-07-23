/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

/*

https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

167. 两数之和 II - 输入有序数组
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 
示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。

示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]
解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 

提示：

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 非递减顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案
通过次数443,728提交次数756,637

*/

// @lc code=start
class Solution {
public:

    // 2022.6.17, by Hsinan. Use two pointers as this is an already sorted array
    // Compared with LC 1, we can use two pointers from front and back to check the
    // sum value, increase front is too small, reduce back if too large
    vector<int> twoSum2(vector<int>& numbers, int target) {
        // define answer vector to return 
        vector<int> answer;

        // sanity check for invalid given vector or only two elements
        if (numbers.size() < 2) return answer;
        if (numbers.size() == 2 && numbers[0] + numbers[1] == target) {
            answer.push_back(1);
            answer.push_back(2);
            return answer;
        }

        // define two pointers
        int front = 0;
        int back = numbers.size() - 1;

        // while front < back pointer condition
        while (front < back) {
            if (numbers[front] + numbers[back] > target) {
                // back is too big, reduce
                back--;
                continue;
            } else if (numbers[front] + numbers[back] < target) {
                // front is too small, increase
                front++;
                continue;
            } if (numbers[front] + numbers[back] == target) {
                // find answer, plus index and return
                answer.push_back(front + 1);
                answer.push_back(back + 1);
                return answer;
            }
        }

        // if here, no answer
        return answer;
    }

    // 2022.6.17, from AcWing https://www.acwing.com/video/1545/
    vector<int> twoSum1(vector<int>& numbers, int target) {
        // below for condition is a trick from AcWing code
        for (int i = 0, j = numbers.size() - 1; i < j; i++) {
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
        return {};
    }

    // 2022.6.17, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum-ii-input-array-is-sorted.cpp
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left != right) {
            const auto sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {0, 0};
    }

};
// @lc code=end

