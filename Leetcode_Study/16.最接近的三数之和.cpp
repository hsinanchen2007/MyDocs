/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

/* 

https://leetcode.cn/problems/3sum-closest/

16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0
 

提示：

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
通过次数361,677提交次数793,387

*/

// @lc code=start
class Solution {
public:

    // 2022.6.12, from AcWing https://www.acwing.com/video/1333/
    int threeSumClosest3(vector<int>& nums, int target) {
        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // we want to save the smallest diff within res to return
        std::pair<int, int> res(INT_MAX, INT_MAX);

        // first iteration for i
        for (int i = 0; i < nums.size(); i++) {
            // second iteration for j and k
            // again, j starts from (i + 1)
            // again, k starts from (nums.size() -1)
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k--;

                // check current sum
                int sum = nums[i] + nums[j] + nums[k];

                // the answer is asking the sum of closest one, not diff
                // so below one's first will be its diff, and second will be sum
                // compare the initial res and get the smallest diff from pair
                res = std::min(res, std::make_pair(std::abs(sum - target), sum));

                // here, target is larger than sum
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    res = std::min(res, std::make_pair(std::abs(target - sum), sum));
                }
            }
        }

        return res.second;
    }

    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-closest.cpp
    int threeSumClosest2(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int result = 0, min_diff = numeric_limits<int>::max();
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            int left = 0, right = i - 1;
            while (left < right) {
                const auto& total = nums[left] + nums[right] + nums[i];
                if (total < target) {
                    ++left;
                } else if (total > target) {
                    --right;
                } else {
                    return target;
                }
                if (abs(total - target) < min_diff) {
                    min_diff = abs(total - target);
                    result = total;
                }
            }
        }
        return result;
    }

    // 2022.6.12, https://www.guozet.me/leetcode/Leetcode-16-3Sum-Closest.html
    // the solution is better and easier to understand
    int threeSumClosest1(vector<int>& nums, int target) {
        // initialize a closest value from first three elements
        int closest = nums[0] + nums[1] + nums[2];

        // initialize a diff based on closest and target 
        int diff = std::abs(closest - target);

        // sort the given vector so we can use two pointers
        sort(nums.begin(), nums.end());

        // iterate all elements
        for (int i = 0; i < nums.size() -2; i++) {
            // define two pointers
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                // get current sum and diff
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = std::abs(sum - target);

                // update sum and diff if needed
                if (newDiff < diff) {
                    diff = newDiff;
                    closest = sum;
                }

                // otherwise next one
                if (sum < target) { 
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }

    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73e2e4b01a4851f98e6f/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_6268b1aae4b01c509aa8e2b8
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 最接近的三数之和(16)：https://leetcode-cn.com/problems/3sum-closest/submissions/
    int threeSumClosest(vector<int>& nums, int target) {
        // 题目假定每组输入只存在恰好一个解，所以不需要处理边界情况
        int ans = nums[0] + nums[1] + nums[2];

        // 先将数组进行排序操作，从小到大
        sort(nums.begin(), nums.end());

        // 开始遍历整个数组
        // 在遍历的过程中，观察设置的三个位置的元素之后的大小
        // num[i] 为从左到右观察过去的元素
        // left 为从 i 到 len - 1 的元素
        // right 为从 len - 1 向左移动到 i 的元素
        for (int i = 0; i < nums.size() ; i++) {

            // left 为从 i 到 len - 1 的元素，向右移动
            int left = i + 1;

            // right 为从 len - 1 向左移动到 i 的元素，向左移动
            int right = nums.size() - 1;

            // left 和 right 不断的向内移动
            while (left < right) {
                
                // 计算这三者之和
                int sum = nums[i] + nums[left] + nums[right];

                // 寻找出更接近于 target 的那个和
                if (abs(target - sum) < abs(target - ans)) {
                     ans = sum;
                }
                   
                // 如果三者之和小于 target ，那么说明需要找更大的数
                if (sum < target) {
                    // left 向右移动
                    left++;

                // 如果三者之和大于 target ，那么说明需要找更小的数
                } else if (sum > target) {
                    // right 向左移动
                    right--;
                } else {
                    return ans;
                }
            }
        }     
        // 返回结果   
        return ans;
    }

};
// @lc code=end

