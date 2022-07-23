/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

/*

https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

26. 删除有序数组中的重复项
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

 

示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
 

提示：

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 升序 排列
通过次数1,133,649提交次数2,094,788

*/

// @lc code=start
class Solution {
public:

    // 2022.6.1, LG solution
    int removeDuplicates2(vector<int>& nums) {
        int target = 0;
        for (int i = 1; i < nums.size(); i++) {
            // target starts from 0, i starts from 1
            // if they are not same, assign number if ++target != i
            // otherwise i++ to next one if they are same
            if (nums[target] != nums[i]) {
                // tricky here, ++target, not target++
                // perform ++ first and check if it is same as i or not
                // actually even if we still assign the number, it is OK
                if (++target != i) {
                    nums[target] = nums[i];
                }
            }
        }
        return (target + 1);
    }

    // 2022.6.4, from AcWing https://www.acwing.com/video/1348/
    int removeDuplicates1(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            // example {1, 2, 2, 2, 3, 4, 5}
            //   i = 0, nums[0] = nums[0], k = 1
            //   i = 1, nums[1] = nums[1], k = 2;
            //   i = 2, nums[2] and nums[1] are same, skip
            //   i = 3, nums[3] and nums[2] are same, skip
            //   i = 4, nums[2] = nums[4], k = 3
            //   i = 5, nums[3] = nums[5], k = 4
            //   i = 6, nums[4] = nums[6], k = 5
            // return 5
            // tricky is below if condition
            if (!i || nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-duplicates-from-sorted-array.cpp
    int removeDuplicates(vector<int>& nums) {
        int last = -1;
        for (const auto& num : nums) {
            if (last == -1 || nums[last] != num) {
                nums[++last] = num;
            }
        }
        return last + 1;
    }
    
};
// @lc code=end

