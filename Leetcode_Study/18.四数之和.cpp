/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

/* 

https://leetcode.cn/problems/4sum/

18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

提示：

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
通过次数328,889提交次数836,378

*/

// @lc code=start
class Solution {
public:

    // 2022.6.12, from AcWing https://www.acwing.com/activity/content/problem/content/2351/
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        // define answer vector to return
        vector<vector<int>> answer;

        // sort the given vector
        sort(nums.begin(), nums.end());

        // iterate all elements
        for (int i = 0; i < nums.size(); i++) {
            // remove duplicated one
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                // remove duplicated one
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                for (int k = j + 1, u = nums.size() - 1; k < u; k++) {
                    // remove duplicated one
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;

                    // do u-- loop unti it either equal or smaller than target
                    // tricky part is that the second pointer u should be nums[u -1] here,
                    // not nums[u], because we want to see "next" one and decide u-- or not
                    // note that the sum condition is >=, the = is needed

                    // CORRECTION: Latest LC will give overflow numbers, so we need to avoid such situation
                    // Instead of using nums[i] + nums[j] + nums[k] + nums[u] >= target
                    // we use nums[i] + nums[j] >= target - nums[k] - nums[u -1]
                    // reference from another solution at 代码随想录:
                    // https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.md
                    while ((u - 1 > k) &&
                           (nums[i] + nums[j] >= target - nums[k] - nums[u -1])) {
                        u--;
                    }
                    // if the sum is same as target, add this set into answer
                    if (nums[i] + nums[j] == target - nums[k] - nums[u] ) {
                        answer.push_back({nums[i], nums[j], nums[k], nums[u]});
                    }
                }
            }
        }

        return answer;
    }

    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/4sum.cpp
    vector<vector<int> > fourSum1(vector<int> &nums, int target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = 0; i + 3 < size(nums); ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j + 2 < size(nums); ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                const auto& total = target - nums[i] - nums[j];
                int left = j + 1, right = size(nums) - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == total) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > total) {
                            --right;
                        } else {
                            ++left;
                        }
                    }
                }
            }
        }
        return result;
    }

    // 2022.6.12, from https://github.com/grandyang/leetcode/issues/18
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }

};
// @lc code=end

