/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:

    // 2022.6.18, by Hsinan. Do sqrt then sort the answers by order
    vector<int> sortedSquares3(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            long answer = nums[i] * nums[i];
            nums[i] = (int)answer;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    // 2022.6.18, from https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html#%E6%9A%B4%E5%8A%9B%E6%8E%92%E5%BA%8F
    // By using two pointers, as the given vector is already sorted, 
    // that means the max or min number will always be from either nums[0] or nums[size-1]
    // so define left and right pointers, and put the answers back to vector
    vector<int> sortedSquares2(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> answer(nums.size(), 0);

        // iterate all elements, but by using for loop like below
        // note that the stop condition is "i <= j" because i and j may have same value
        for (int i = 0, j = nums.size() - 1; i <= j; /* no i or j's increase/decrease here! */) {
            // so if we know j*j is bigger, put it into answer vector
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                answer[k--] = nums[j] * nums[j];
                j--;
            } else {
                // if i*i is equal or bigger, put it into answer vector
                answer[k--] = nums[i] * nums[i];
                i++;
            }
        }

        return answer;
    }

    // 2022.6.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/squares-of-a-sorted-array.cpp
    vector<int> sortedSquares1(vector<int>& nums) {
        int right = distance(nums.cbegin(), lower_bound(nums.cbegin(), nums.cend(), 0));
        int left = right - 1;
        vector<int> result;
        while (0 <= left || right < nums.size()) {
            if (right == nums.size() ||
                (0 <= left && nums[left] * nums[left] < nums[right] * nums[right])) {
                result.emplace_back(nums[left] * nums[left]);
                --left;
            } else {
                result.emplace_back(nums[right] * nums[right]);
                ++right;
            }
        }
        return result;
    }

    // 2022.6.18, from AcWing https://www.acwing.com/video/3272/
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        // as below operations to answer is like an array operation,
        // remember to define the size to answer vector 
        vector<int> answer(size);

        // iterate elements and put larger number into answer
        for (int i = 0, j = size - 1, k = size - 1; i <= j; ) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                answer[k] = nums[i] * nums[i];
                i++, k--;
            } else {
                answer[k] = nums[j] * nums[j];
                j--, k--;
            }
        }
        return answer;
    }

};
// @lc code=end

