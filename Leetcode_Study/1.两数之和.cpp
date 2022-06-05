/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:

    // 2022.6.3, 极客时间覃超算法训练營, O(n^2)
    vector<int> twoSum2(vector<int>& nums, int target) {
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
    vector<int> twoSum1(vector<int>& nums, int target) {
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
    vector<int> twoSum(vector<int>& nums, int target) {
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

};
// @lc code=end

