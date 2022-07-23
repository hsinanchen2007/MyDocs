/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

/* 

https://leetcode.cn/problems/3sum/

15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：

输入：nums = []
输出：[]

示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
通过次数1,004,997提交次数2,820,263

*/

// @lc code=start
class Solution {
public:

    // 2022.6.9, from https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/medium/15.3sum
    vector<vector<int>> threeSum3(vector<int>& nums) {
        // tricky one, the returned vector is vector<vector<int>>, three
        // numbers, not two numbers
        vector<vector<int>> answer;

        // return if nums < 3
        if (nums.size() < 3) return answer;

        // sort the vector first so we can pick one target number i, and use
        // two pointers to start from j (target + 1) and k (nums.size()-1),
        //   if i + j + k > 0, k--, because k side is larger number
        //   if i + j + k < 0, j++, because j side is smaller number
        sort(nums.begin(), nums.end());
        
        // why nums.size() -2 here? for example below has 10 numbers
        //   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        // the last iteration from i is at index of number 8, which is 
        // nums.size() - 2, index 7. If we go to index 8, which is number 9,
        // two pointers can only hold same number 10
        // however, we should be able to handle this without -2 below
        //
        // tested below code by -1, not -2, it also works as j and k will 
        // perforn the range check. To make code easier to read and maintain,
        // I would prefer the code with -1, not -2
        for (int i = 0; i < nums.size() - 1; ++i) {
            // need this check to filter out duplicated ones
            // since the question didn't say the numbers in vector are unique,
            // they can be same number, but what we want is all solutions of 
            // different numbers
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // define two pointers j and k, j moves from left to right,
            // and k moves from right to left
            int j = i + 1;
            int k = nums.size() - 1;

            // stop condition of j and k
            while (j < k) {
                // check sum value now
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // a way to push_back three numers into vector in one line code
                    answer.push_back({nums[i], nums[j], nums[k]});
                }

                // below "=" are very important, as above condition didn't update j and k index
                // we need below two "<=" and ">=" conditions to update j and k accordingly
                // otherwise it will cause hang in the while loop
                if (sum <= 0) {
                    // +1 first, then copmpare the nums value with previous one, j - 1
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                }
                if (sum >= 0) {
                    --k;
                    // -1 first, then compare the nums value with previous one, k + 1
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }

        return answer;
    }

    // 2022.6.10, from AcWing https://www.acwing.com/video/1332/
    vector<vector<int>> threeSum2(vector<int>& nums) {
        // define return answer
        vector<vector<int>> answer;

        // sort the given vector as two pointers need a sorted array
        sort(nums.begin(), nums.end());

        // iteration, i as fixed one, j and k are moving forward/backward
        for (int i = 0; i < nums.size(); i++) {
            // if i is not 0 (first one) and next is same, skip
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                // if j is not i + 1 (first one) and next is same, skip
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // key condition, why (j < k -1) here? because if j = k -1, 
                // we only need to check nums[i] + nums[j] + nums[k]
                // but if (j < k - 1) and the sum is >= 0, current k is still too big
                // so k--, and if the sum is still too big, keep k--,
                // until j/k condition or the sum < 0 
                while ((j < k - 1) && (nums[i] + nums[j] + nums[k - 1] >= 0)) k--;

                // if sum is 0, add this one into answer
                if (nums[i] + nums[j] + nums[k] == 0) {
                    answer.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return answer;
    }

    // 2022.6.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum.cpp
    vector<vector<int>> threeSum1(vector<int> &nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            const auto& target = -nums[i];
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] < target) {
                    ++left;
                } else if (nums[left] + nums[right] > target) {
                    --right;
                } else {
                    result.push_back({nums[left], nums[right], nums[i]});
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
            }
        }
        return result;
    }

    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73dee4b01a4851f98e6b/3?from=p_6268b1aae4b01c509aa8e2b8&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 三数之和(15)：https://leetcode-cn.com/problems/3sum/ 
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 题目存在多组解，每一组解都是一个数组，所以使用二维数组存储所有的解
        vector<vector<int>> ans;

        // 获取数组的程度
        int len = nums.size();

        // 边界情况判断
        if (len < 3) return ans;

        // 先将数组进行排序操作，从小到大
        sort(nums.begin(), nums.begin() + len);

        // 开始遍历整个数组
        // 在遍历的过程中，观察设置的三个位置的元素之后的大小
        // num[i] 为从左到右观察过去的元素
        // left 为从 i 到 len - 1 的元素
        // right 为从 len - 1 向左移动到 i 的元素
        for (int i = 0; i < len ; i++) {

            // 如果发现 nums[i] > 0 ，由于 nums 是递增序列，left 在 nums[i] 的右侧，right 也在 nums[i] 的右侧
            // 那么 num[i]、nums[left]、nums[right] 都大于 0 
            // 说明这三数之和一定大于 0 ，结束循环
            if (nums[i] > 0) break; 

            // 答案中不可以包含重复的三元组，所以需要执行一个去重的操作
            // 比如这个输入 [-4,-1,-1,0,1,2]
            // i 指向的为第一个 -1 时，left 指向的元素值为 0 ，right 指向的元素值为 1 
            // i 指向的为第二个 -1 时，left 指向的元素值为 0 ，right 指向的元素值为 1 
            // 这两组解都是 [ -1 , 0 , 1]，所以需要去重
            if (i > 0 && nums[i] == nums[ i - 1 ]) continue; 

            // left 为从 i 到 len - 1 的元素，向右移动
            int left = i + 1;

            // right 为从 len - 1 向左移动到 i 的元素，向左移动
            int right = len - 1;

            // left 和 right 不断的向内移动
            while(left < right){

                // 计算这三者之和
                int sum = nums[i] + nums[left] + nums[right];

                // 发现三者之和为 0
                if (sum == 0) {

                    // 把这个结果记录一下
                    vector<int>v = {nums[i], nums[left], nums[right]};
                    ans.push_back(v);
     
                    // 答案中不可以包含重复的三元组，所以需要执行一个去重的操作
                    // 比如这个输入 [-2,0,0,2,2]
                    // i 指向的元素值为 -2 ，left 指向的元素值为第一个 0 ，right 指向的元素值为倒数第一个 2 时
                    // 它们的 sum 为 0 ，如果让 ，left 向右移动一下，，right 向左移动一下，它们的 sum 也为 0
                    // 但是这两组解都是 [ -2 , 0 , 2]，所以需要去重
                    while( left < right && nums[left] == nums[ left + 1 ]) {
                        // left 向右移动
                        left++;
                    }

                    while( left < right && nums[right] == nums[ right - 1]){
                        // right 向左移动
                        right--;
                    }

                    // left 向右移动
                    left++;

                    // right 向左移动
                    right--;

                // 如果三者之和小于 0 ，那么说明需要找更大的数
                } else if (sum < 0) {
                    // left 向右移动
                    left++;

                // 如果三者之和大于 0 ，那么说明需要找更小的数
                } else if (sum > 0) {
                    // right 向左移动
                    right--;
                }
            }
        }     
        // 返回结果   
        return ans;
    }

};
// @lc code=end

