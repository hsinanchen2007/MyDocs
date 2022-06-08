/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

/*

https://leetcode.cn/problems/move-zeroes/

283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能尽量减少完成的操作次数吗？

通过次数768,285提交次数1,200,598
请问您在哪类招聘中遇到此题？
贡献者
LeetCode
半年内半年 ~ 1年1年 ~ 2年
移除元素
简单
In-place means we should not be allocating any space for extra array. But we are allowed to modify the existing array. However, as a first step, try coming up with a solution that makes use of additional space. For this problem as well, first apply the idea discussed using an additional array and the in-place solution will pop up eventually.
A two-pointer approach could be helpful here. The idea would be to have one pointer for iterating the array and another pointer that just works on the non-zero elements of the array.

*/

// @lc code=start
class Solution {
public:

    // 2022.6.2, 极客时间覃超算法训练營, very similar to LC 27
    void moveZeroes4(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[target] = nums[i];
                // if target and i is same, for example {1}, 
                // no need to assign 0 in nums
                if (target != i) {
                    nums[i] = 0;
                }
                // move to next target
                target++;
            }
        }
    }

    // learned from LC 27 solution, use C++ STL
    // nums = {0, 0, 1, 2, 3, 0, 0, 4, 5}, answer = {1, 2, 3, 4, 5, 0, 0, 0, 0}
    void moveZeroes3(vector<int>& nums) {
        // get original nums size
        int size = nums.size();

        // note that std::remove returns the number of valid elements
        // which means it will not count the value (0 here) 
        int distance = std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), 0));

        // for this LC question, it needed to remain its original size
        for (int i = 0; i < size-distance; i++) {
            nums[size- 1 - i] = 0;
        }
    }
    
    // 2022.6.5, from AcWing https://www.acwing.com/video/1657/
    // this one is similar to LC 26 and LC 27
    void moveZeroes2(vector<int>& nums) {
        int k = 0;

        // use below to get value directly
        for (auto i : nums) {
            if (i != 0) nums[k++] = i;
        }

        // assign 0 to rest elements
        while (k < nums.size()) nums[k++] = 0;
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/move-zeroes.cpp
    void moveZeroes1(vector<int>& nums) {
        int pos = 0;
        for (auto& num : nums) {
            if (num) {
                swap(nums[pos++], num);
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (const auto& num : nums) {
            if (num) {
                nums[pos++] = num;
            }
        }
        fill(next(nums.begin(), pos), nums.end(), 0);
    }

};
// @lc code=end

