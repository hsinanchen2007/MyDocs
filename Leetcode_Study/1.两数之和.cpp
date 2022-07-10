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

*/

// @lc code=start
class Solution {
public:

    // 2022.6.3, 极客时间覃超算法训练營, O(n^2)
    vector<int> twoSum4(vector<int>& nums, int target) {
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
    vector<int> twoSum3(vector<int>& nums, int target) {
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
    vector<int> twoSum2(vector<int>& nums, int target) {
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
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                return {lookup[target - nums[i]], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }

    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73dce4b01c509aaaf267/3?from=p_6268b1aae4b01c509aa8e2b8&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 两数之和（LeetCode 1）:https://leetcode-cn.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        // 首先构建一个哈希表，用来存放数组的元素值以及索引值
        // 其中 key 是数组中的元素值
        // value 为数组中元素值的索引
        unordered_map< int , int > map;

        // 接下来，遍历整个数组
        for(int i = 0; i < nums.size(); i++) {

            // 目标值为 target，将 target 与 nums[i] 求差
            // 获取与 nums[i] 配对的那个数 anotherNum
            int anotherNum = target - nums[i];

            // 判断哈希表中是否存在那个与 nums[i] 配对的数 anotherNum
            auto it = map.find(anotherNum);
            if (it != map.end()) {
                // 由于哈希表中所有 key 都是来自于数组中，
                // 所以，如果发现哈希表存在那个与 nums[i] 配对的数 anotherNum
                // 也就说明数组中存在一个数，可以和 nums[i] 相加为 target
                // 此时， anotherNum 这个 key 对应的 value 为这个数在数组中的索引
                // 所以，返回 map.get(anotherNum) 和 i 就是这两个值的下标
                return {map[anotherNum], i};
            } else {
                // 如果发现哈希表中目前不存在那个与 nums[i] 配对的数 anotherNum
                // 那么就把此时观察的数 nums[i] 和它的索引存放到哈希表中
                // 等待后面的数能和它配对为 target
                map[nums[i]] =  i;
            }
        }

        // 如果遍历完整个数组都找不到和为 target 的两个数，返回 0
        return {};
    }

};
// @lc code=end

