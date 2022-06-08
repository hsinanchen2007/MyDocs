/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

/*

https://leetcode.cn/problems/two-sum/

1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

通过次数3,459,984提交次数6,581,774
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
三数之和
中等
四数之和
中等
两数之和 II - 输入有序数组
中等
两数之和 III - 数据结构设计
简单
和为 K 的子数组
中等
两数之和 IV - 输入 BST
简单
小于 K 的两数之和
简单
A really brute force way would be to search for all possible pairs of numbers but that would be too slow. Again, it's best to try out brute force solutions for just for completeness. It is from these brute force solutions that you can come up with optimizations.
So, if we fix one of the numbers, say
x
, we have to scan the entire array to find the next number
y
which is
value - x
where value is the input parameter. Can we change our array somehow so that this search becomes faster?
The second train of thought is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

*/

// @lc code=start
class Solution {
public:

    // 2022.6.3, 极客时间覃超算法训练營, O(n^2)
    vector<int> twoSum3(vector<int>& nums, int target) {
        // answer vector to return
        std::vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            // one trick here is that j starts from (i + 1)
            // so it won't be the same as i
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    // the returned answer needed the index, not its value
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }

        // no answer here
        return answer;
    }

    // 2022.6.3, soulmachine, O(n)
    // in the 2nd for loop, it only needs to find the corresponding index based on rest value
    vector<int> twoSum2(vector<int>& nums, int target) {
        // answer vector to return
        std::vector<int> answer;

        // build up lookup table, (key, value)
        std::unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++) {
            // key is number of nums[i], value is its index i
            lookup.insert(std::make_pair(nums[i], i));
        }

        // iterate all elements, and find the rest from lookup table
        for (int j = 0; j < nums.size(); j++) {
            // rest is the corresponding (value, index)
            int rest = target - nums[j];

            // lookup now, so nums[j] is current value, rest is the corresponding value
            // we only need to find the corresponding index from rest value
            if ((lookup.find(rest) != lookup.end()) && (j != lookup[rest])) {
                answer.push_back(j);
                answer.push_back(lookup[rest]);
                return answer;
            }
        }

        // no answer here
        return answer;
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1317/
    // similar to soulmachine's solution, it uses [value, index] in unordered_map
    // but it use unordered_map.count(value) to check if the given value
    // is existed or not, then return it by {} way, so no push_back() call
    // at the end, as we are using C++, although LC already said it will have 
    // one answer, we need to add that one to compile properly
    vector<int> twoSum1(vector<int>& nums, int target) {
        std::unordered_map<int, int> heap;

        for (int i = 0; i < nums.size(); i++) {
            // to see if any corresponding pair already existed or not
            int r = target - nums[i];

            // use unordered_map.count(value) to check if the given value is existed or not
            // also use {} to return answer without defining a new vector
            if (heap.count(r)) return {heap[r], i};

            // if no pair found, add this {value, index} into unordered_map
            heap[nums[i]] = i;
        }
        return {};
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum.cpp
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                return {lookup[target - nums[i]], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }

};
// @lc code=end

